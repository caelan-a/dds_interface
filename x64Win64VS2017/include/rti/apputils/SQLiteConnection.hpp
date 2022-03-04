/*
 * (c) Copyright, Real-Time Innovations, 2016-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_RTI_APPUTILS_SQLiteConnection_HPP_
#define HPP_RTI_APPUTILS_SQLiteConnection_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "ndds/ndds_utility_c.h"
#include <dds/core/types.hpp>
#include <rti/core/constants.hpp>
#include <rti/core/Exception.hpp>

#include "SQLiteConnection.hpp"

#include "apputils/apputils_dll.h"

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "osapi/osapi_host.h"
#include "rtisqlite/sqlite3.h"
#include "rtiboost/smart_ptr/shared_ptr.hpp"
#include "rti/apputils/util/LockedBuffer.hpp"
#include "rti/apputils/util/Path.hpp"

struct sqlite3;

namespace rti { namespace apputils {

class APPUTILSDllExport SQLiteConnection {
public:
    SQLiteConnection(): sqlite_init_string_(default_sqlite_init_string()){}
    SQLiteConnection(const std::string& sqlite_init_string)
        : sqlite_init_string_(sqlite_init_string) {}
    ~SQLiteConnection() {}

    class SQLiteException: public std::exception {
    public:

        SQLiteException() :
            sqlite_error_(),
            sqlite_error_code(SQLITE_OK),
            sql_statement_() {}

        SQLiteException(const SQLiteException& other) :
            sqlite_error_(other.sqlite_error_),
            sqlite_error_code(other.sqlite_error_code),
            sql_statement_(other.sql_statement_),
            what_(other.what_) {}

        SQLiteException(
                int return_code,
                const std::string error_string,
                const std::string sql_statement):
                sqlite_error_(error_string),
                sqlite_error_code(return_code),
                sql_statement_(sql_statement)
        {
            what_string_stream << "SQLite error: " + sqlite_error_;
            what_string_stream << std::endl;
            what_string_stream << "  [SQLite return code = " << sqlite_error_code
                    << "]" << std::endl;
            if (!sql_statement_.empty()) {
                what_string_stream << "  [SQL statement = " << sql_statement_
                        << "]" << std::endl;
            }
            set_what();
        }

        ~SQLiteException() throw() {}

        virtual const char * what() const throw()
        {
            return what_.c_str();
        }

    protected:
        void set_what() {
            unsigned int what_size = what_string_stream.str().size() + 1;
            what_.resize(what_size);
            strncpy(&what_[0], what_string_stream.str().c_str(), what_size);
        }

        std::string sqlite_error_;
        int sqlite_error_code;
        std::string sql_statement_;
        std::stringstream what_string_stream;
        std::string what_;
    };

    class SQLiteOpenException: public SQLiteException {
    public:
        SQLiteOpenException(
                const int return_code,
                const std::string error_string,
                const std::string filename)
                : filename_(filename)
        {
            sqlite_error_ = error_string;
            sqlite_error_code = return_code;

            what_string_stream << "SQLite - failed to open database file; sqlite returned error: "
                    + sqlite_error_;
            what_string_stream << std::endl;
            what_string_stream << "  [SQLite return code = "
                    << sqlite_error_code << "]" << std::endl;
            what_string_stream << "  [File = " << filename_ << "]"
                    << std::endl;
            set_what();
        }

        ~SQLiteOpenException() throw() {}

    private:
        std::string filename_;
    };

    class SQLiteCloseException: public SQLiteException {
    public:
        SQLiteCloseException(
                const int return_code,
                const std::string error_string)
        {
            sqlite_error_ = error_string;
            sqlite_error_code = return_code;

            what_string_stream << "SQLite - failed to open database; error: "
                    + sqlite_error_;
            what_string_stream << std::endl;
            what_string_stream << "  [SQLite return code = "
                    << sqlite_error_code << "]" << std::endl;
            set_what();
        }

        ~SQLiteCloseException() throw() {}

    };

    class SQLiteBindException: public SQLiteException {
    public:
        SQLiteBindException(int return_code,
                const std::string error_string,
                const std::string sql_statement,
                int column) :
                column_(column)
        {
            sqlite_error_ = error_string;
            sqlite_error_code = return_code;
            sql_statement_ = sql_statement;

            what_string_stream << "SQLite error: " + sqlite_error_;
            what_string_stream << std::endl;
            what_string_stream << "  [SQLite return code = "
                    << sqlite_error_code << "]" << std::endl;
            if (!sql_statement_.empty()) {
                what_string_stream << "  [SQL statement = " << sql_statement_
                        << "]" << std::endl;
            }
            what_string_stream << "  [Column being bound: " << column << "]"
                    << std::endl;
            set_what();
        };

        ~SQLiteBindException() throw() {}

    private:
        int column_;
    };

    class SQLiteDeleter {
    public:
        void operator()(struct sqlite3 *p)
        {
            if (p != NULL) {
                sqlite3_close_v2(p);
            }
        }

        static void statement_delete(sqlite3_stmt *p)
        {
            if (p != NULL) {
                sqlite3_finalize(p);
            }
        }
    };

    /**
     * This class opens an exclusive SQLite transaction within the constructor,
     * on the SQLite connection given as a parameter to it.
     * The transaction is closed when the object comes out of scope, and the
     * destructor is called. It provides an error setting method. When there has
     * been an error, the transaction will be rolled back. When everything went
     * fine, the destructor will commit normally.
     */
    class TransactionToken {
    public:
        TransactionToken(SQLiteConnection& connection)
                : connection_(connection),
                  error_(false)
        {
            connection_.begin();
        }
        ~TransactionToken()
        {
            if (error_) {
                connection_.rollback();
            } else {
                connection_.commit();
            }
        }
        void set_error(bool error)
        {
            error_ = error;
        }
    private:
        SQLiteConnection& connection_;
        bool error_;
    };

    class RowIterator {
    public:
        RowIterator() :
            return_code_(SQLITE_OK),
            is_bound_(false),
            is_output_stmt_(false) { }

        RowIterator(
                const rtiboost::shared_ptr<sqlite3_stmt>& statement,
                const rtiboost::shared_ptr<sqlite3>& connection,
                const bool auto_step = true) :
            statement_(statement),
            connection_(connection),
            return_code_(SQLITE_OK),
            is_bound_(false),
            is_output_stmt_(false)
        {
            initialize(auto_step);
        }

        RowIterator(
                const rtiboost::shared_ptr<sqlite3_stmt>& statement,
                SQLiteConnection& connection,
                const bool auto_step = true) :
            statement_(statement),
            connection_(connection.connection_),
            return_code_(SQLITE_OK),
            is_bound_(false),
            is_output_stmt_(false)
        {
            initialize(auto_step);
        }

        ~RowIterator() { }

        int num_columns() const
        {
            return sqlite3_column_count(statement_.get());
        }

        void bind(const int column, const int64_t value)
        {
            int ret_code = sqlite3_bind_int64(
                    statement_.get(),
                    column,
                    (sqlite_int64) value);
            if (ret_code != SQLITE_OK) {
                std::string errMsg(sqlite3_errmsg(connection_.get()));
                std::string sql(sqlite3_sql(statement_.get()));
                throw SQLiteBindException(ret_code, errMsg, sql, column);
            }
            is_bound_ = true;
        }

        void bind(const int column, const double value)
        {
            int ret_code = sqlite3_bind_double(statement_.get(), column, value);
            if (ret_code != SQLITE_OK) {
                std::string errMsg(sqlite3_errmsg(connection_.get()));
                std::string sql(sqlite3_sql(statement_.get()));
                throw SQLiteBindException(ret_code, errMsg, sql, column);
            }
            is_bound_ = true;
        }

        void bind(const int column, const std::string& value)
        {
            int ret_code = sqlite3_bind_text(
                    statement_.get(),
                    column,
                    value.c_str(),
                    (int) value.size(),
                    SQLITE_TRANSIENT);
            if (ret_code != SQLITE_OK) {
                std::string err_msg(sqlite3_errmsg(connection_.get()));
                std::string sql(sqlite3_sql(statement_.get()));
                throw SQLiteBindException(ret_code, err_msg, sql, column);
            }
            is_bound_ = true;
        }

        void bind(const int column, const std::vector<uint8_t>& value)
        {
            void *value_array = NULL;
            if (value.size() > 0) {
                value_array = (void *) &(value[0]);
            }
            int ret_code = sqlite3_bind_blob(
                    statement_.get(),
                    column,
                    value_array,
                    (int) value.size(),
                    SQLITE_TRANSIENT);
            if (ret_code != SQLITE_OK) {
                std::string errMsg(sqlite3_errmsg(connection_.get()));
                std::string sql(sqlite3_sql(statement_.get()));
                throw SQLiteBindException(ret_code, errMsg, sql, column);
            }
            is_bound_ = true;
        }

        void bind(
                const int column,
                const rti::apputils::util::LockedBuffer<uint8_t>& value)
        {
            int ret_code = sqlite3_bind_blob(
                    statement_.get(),
                    column,
                    value.buffer(),
                    (int) value.size(),
                    SQLITE_STATIC);
            if (ret_code != SQLITE_OK) {
                std::string errMsg(sqlite3_errmsg(connection_.get()));
                std::string sql(sqlite3_sql(statement_.get()));
                throw SQLiteBindException(ret_code, errMsg, sql, column);
            }
            is_bound_ = true;
        }

        bool is_null(const int column)
        {
            return sqlite3_column_type(statement_.get(), column) == SQLITE_NULL;
        }

        /**
         * Get an integer value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(const int column, int64_t& value)
        {
            value = (int64_t) sqlite3_column_int64(statement_.get(), column);
        }
        /**
         * Get a floating-point value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(const int column, double& value)
        {
            value = sqlite3_column_double(statement_.get(), column);
        }
        /**
         * Get a text value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(const int column, std::string& value)
        {
            int length = sqlite3_column_bytes(statement_.get(), column);
            if (length > 0) {
                const char *c_tmp = (const char *) sqlite3_column_text(
                        statement_.get(),
                        column);
                if (c_tmp == NULL) {
                    std::string errMsg(sqlite3_errmsg(connection_.get()));
                    std::string sql(sqlite3_sql(statement_.get()));
                    throw SQLiteException(SQLITE_ERROR, errMsg, sql);
                }
                value.assign(c_tmp, c_tmp + strlen(c_tmp));
            }
        }
        /**
         * Get a wide-string value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(const int column, dds::core::wstring& value)
        {
            int length = sqlite3_column_bytes(statement_.get(), column);
            if (length > 0) {
                DDS_UnsignedShort *utf16_string =
                        (DDS_UnsignedShort *) sqlite3_column_text16(
                                statement_.get(),
                                column);
                if (utf16_string == NULL) {
                    std::string errMsg(sqlite3_errmsg(connection_.get()));
                    std::string sql(sqlite3_sql(statement_.get()));
                    throw SQLiteException(SQLITE_ERROR, errMsg, sql);
                }
                uint32_t utf16_string_length =
                        sqlite3_column_bytes16(statement_.get(), column) >> 1;
                dds::core::wstring tmp(utf16_string_length);
                for (uint32_t i = 0; i < utf16_string_length; ++i) {
                    tmp.native()[i] = (DDS_Wchar) utf16_string[i];
                }
                value = tmp;
            }
        }
        /**
         * Get a blob value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(const int column, std::vector<uint8_t>& value)
        {
            int length = sqlite3_column_bytes(statement_.get(), column);
            if (length > 0) {
                uint8_t *c_array = (uint8_t *) sqlite3_column_blob(
                        statement_.get(),
                        column);
                value.assign(c_array, c_array + length);
            }
        }
        /**
         * Get a blob pointer value from the current iterator position.
         *
         * @param column The index of the column to get the value from. Leftmost
         *               column is indexed by 0.
         */
        void get(
                const int column,
                rti::apputils::util::LockedBuffer<uint8_t>& value)
        {
            int length = sqlite3_column_bytes(statement_.get(), column);
            if (length > 0) {
                uint8_t *c_array = (uint8_t *) sqlite3_column_blob(
                        statement_.get(),
                        column);
                value.set(c_array, length);
            }
        }

        bool has_no_data(const int column)
        {
            return (sqlite3_column_bytes(statement_.get(), column) == 0);
        }

        RowIterator& operator =(const RowIterator& copy_from)
        {
            statement_ = copy_from.statement_;
            connection_ = copy_from.connection_;
            return_code_ = copy_from.return_code_;
            is_bound_ = copy_from.is_bound_;
            is_output_stmt_ = copy_from.is_output_stmt_;
            return *this;
        }

        /**
         * Step the iterator.
         */
        RowIterator& operator ++()
        {
            return_code_ = sqlite3_step(statement_.get());
            switch (return_code_) {
            case (SQLITE_OK):
                break;
            case (SQLITE_ROW):
                break;
            case (SQLITE_DONE):
                break;
            default:
                throw SQLiteException(
                        return_code_,
                        sqlite3_errmsg(connection_.get()),
                        sqlite3_sql(statement_.get()));
            }
            if (is_bound_ && is_output_stmt_) {
                int ret_code = sqlite3_reset(statement_.get());
                if (ret_code != SQLITE_OK) {
                    throw SQLiteException(
                            ret_code,
                            sqlite3_errmsg(connection_.get()),
                            sqlite3_sql(statement_.get()));
                }
                sqlite3_clear_bindings(statement_.get());
            }
            return *this;
        }

        bool at_end() {
            return return_code_ == SQLITE_DONE;
        }

        void reset() {
            int ret_code = sqlite3_reset(statement_.get());
            if (ret_code != SQLITE_OK) {
                throw SQLiteException(
                        ret_code,
                        sqlite3_errmsg(connection_.get()),
                        sqlite3_sql(statement_.get()));
            }
            sqlite3_clear_bindings(statement_.get());
            return_code_ = SQLITE_OK;
        }

    private:
        rtiboost::shared_ptr<sqlite3_stmt> statement_;
        rtiboost::shared_ptr<sqlite3> connection_;
        int return_code_;
        bool is_bound_;
        /**
         * This is true only when the statement is an INSERT statement
         */
        bool is_output_stmt_;

        void initialize(const bool auto_step)
        {
            return_code_ = sqlite3_reset(statement_.get());
            if (return_code_ != SQLITE_OK) {
                throw SQLiteException(
                        return_code_,
                        sqlite3_errmsg(connection_.get()),
                        sqlite3_sql(statement_.get()));
            }
            if (REDAString_iFindSubString(
                    sqlite3_sql(statement_.get()),
                    "INSERT INTO ") == NULL
                    && REDAString_iFindSubString(
                            sqlite3_sql(statement_.get()),
                            "DELETE FROM ") == NULL) {
                if (auto_step) {
                    ++(*this);
                }
            } else {
                is_output_stmt_ = true;
            }
        }
    };

    void connect(
            const std::string& filename,
            bool create_on_open = true,
            bool readonly = false)
    {
        struct sqlite3 *connection = NULL;
        std::string sql;

        // Setup the SQLite open function flags
        int open_flags = 0;
        std::string stringified_open_flags(" for ");
        if (create_on_open) {
            /*
             * Create the file when opening it. Replay and Converter _should not_
             * use this
             */
            open_flags = open_flags | SQLITE_OPEN_CREATE;
            stringified_open_flags += "create ";
        }
        if (readonly) {
            open_flags = open_flags | SQLITE_OPEN_READONLY;
            stringified_open_flags += "readonly ";
        } else {
            open_flags = open_flags | SQLITE_OPEN_READWRITE;
            stringified_open_flags += "read+write ";
        }
        int sqlite3_open_retcode = sqlite3_open_v2(
                filename.c_str(),
                &connection,
                open_flags,
                NULL);
        if (sqlite3_open_retcode != SQLITE_OK) {
            std::stringstream location_to_report;
#if !defined(RTI_INTY)
            location_to_report << filename << " from working directory ";
            location_to_report << rti::apputils::util::Path::cwd();
#else
            location_to_report << filename << " ";
#endif
            location_to_report << stringified_open_flags;
            sqlite3_close_v2(connection);
            throw SQLiteOpenException(
                    sqlite3_open_retcode,
                    sqlite3_errstr(sqlite3_open_retcode),
                    location_to_report.str());
        }
        connection_ = rtiboost::shared_ptr<sqlite3>(
                connection,
                SQLiteConnection::SQLiteDeleter());

        if (sqlite3_busy_handler(
                connection,
                SQLiteConnection::busy_handler,
                NULL) != SQLITE_OK) {
            std::stringstream location_to_report;
#if !defined(RTI_INTY)
            location_to_report << filename << " from working directory ";
            location_to_report << rti::apputils::util::Path::cwd();
#else
            location_to_report << filename << " ";
#endif
            location_to_report << stringified_open_flags;
            throw SQLiteOpenException(
                    sqlite3_errcode(connection_.get()),
                    sqlite3_errmsg(connection_.get()),
                    location_to_report.str());
        }

        // RECNEXTGEN-72 [Juanlu]: for the EAR 1, default to the most performant
        // SQLite settings. We will need to document that we're setting them
        exec(sqlite_init_string_);
    }

    const std::string db_filename() const
    {
        std::string db_filename(sqlite3_db_filename(connection_.get(), NULL));
        return db_filename;
    }

    void disconnect() { connection_.reset(); }

    void begin()
    {
        std::string sql("BEGIN");
        int retcode = sqlite3_exec(
                connection_.get(),
                sql.c_str(),
                NULL,
                NULL,
                NULL);
        if (retcode != SQLITE_OK && retcode != SQLITE_BUSY) {
            throw SQLiteException(
                    sqlite3_errcode(connection_.get()),
                    sqlite3_errmsg(connection_.get()),
                    sql);
        }
        while (retcode == SQLITE_BUSY) {
            retcode = sqlite3_exec(
                        connection_.get(),
                        sql.c_str(),
                        NULL,
                        NULL,
                        NULL);
            if (retcode != SQLITE_OK && retcode != SQLITE_BUSY) {
                throw SQLiteException(
                        sqlite3_errcode(connection_.get()),
                        sqlite3_errmsg(connection_.get()),
                        sql);
            }
        }
    }

    void commit()
    {
        const std::string sql("COMMIT");

        if (sqlite3_exec(connection_.get(), sql.c_str(), NULL, NULL, NULL)
                != SQLITE_OK) {
            throw SQLiteException(
                    sqlite3_errcode(connection_.get()),
                    sqlite3_errmsg(connection_.get()),
                    sql);
        }
    }

    void rollback()
    {
        const std::string sql("ROLLBACK");

        if (sqlite3_exec(connection_.get(), sql.c_str(), NULL, NULL, NULL)
                != SQLITE_OK) {
            throw SQLiteException(
                    sqlite3_errcode(connection_.get()),
                    sqlite3_errmsg(connection_.get()),
                    sql);
        }
    }

    rtiboost::shared_ptr<sqlite3_stmt> prepare(
            const std::string& statement_text)
    {
        sqlite3_stmt *statement = NULL;

        if (sqlite3_prepare_v2(
                connection_.get(),
                statement_text.c_str(),
                (int) statement_text.size(),
                &statement,
                NULL) != SQLITE_OK) {
            throw SQLiteException(
                    sqlite3_errcode(connection_.get()),
                    sqlite3_errmsg(connection_.get()),
                    statement_text);
        }
        return rtiboost::shared_ptr<sqlite3_stmt>(
                statement,
                SQLiteConnection::SQLiteDeleter::statement_delete);
    }

    void exec(const std::string& statement_text)
    {
        int return_code = sqlite3_exec(
                connection_.get(),
                statement_text.c_str(),
                NULL,
                NULL,
                NULL);
        if (return_code != SQLITE_OK) {
            throw SQLiteException(
                    return_code,
                    sqlite3_errmsg(connection_.get()),
                    statement_text);
        }
    }

    RowIterator begin(
            const rtiboost::shared_ptr<sqlite3_stmt>& statement,
            const bool auto_step = true)
    {
        return RowIterator(statement, connection_, auto_step);
    }

    RowIterator begin(
            const std::string& statement_text,
            const bool auto_step = true)
    {
        return RowIterator(prepare(statement_text), connection_, auto_step);
    }


    const std::string& sqlite_init_string() { return sqlite_init_string_; }

    /**
     * See: https://www.sqlite.org/c3ref/busy_handler.html
     * The SQLite busy handler allows for a process to wait when another process
     * has a database table locked. This will help concurrency, but also, is
     * necessary for some of our automated tests.
     */
    static int busy_handler(void *, int)
    {
        const uint32_t max_time_millis = 300;
        struct RTINtpTime maxTime = RTI_NTP_TIME_ZERO;
        struct RTINtpTime timeout = RTI_NTP_TIME_ZERO;
        RTINtpTime_packFromMillisec(maxTime, 0, max_time_millis);
        // Use the OsapiHost method already implemented to obtain a random time
        // given a maximum
        RTIOsapiHost_generateRandomTime(&timeout, &maxTime);
        int32_t timeout_sec = 0;
        uint32_t timeout_nsec = 0;
        RTINtpTime_unpackToNanosec(timeout_sec, timeout_nsec, timeout);
        struct DDS_Duration_t wait_period = { timeout_sec, timeout_nsec };

        std::ostringstream string_buffer;
        string_buffer
                << (timeout_nsec / rti::core::nanosec_per_millisec)
                << " milliseconds";
        DDSLog_content(
                &RTI_LOG_ANY_ss,
                "Executing busy handler: waiting for ",
                string_buffer.str().c_str());
        NDDS_Utility_sleep(&wait_period);
        return RTI_TRUE;
    }

    static const std::string& default_sqlite_init_string()
    {
        static const std::string default_sql_init_string(
                "PRAGMA SYNCHRONOUS = OFF; PRAGMA JOURNAL_MODE = MEMORY;");
        return default_sql_init_string;
    }

    bool table_exists(const std::string& table_name)
    {
        try {
            std::stringstream select_stmt_stream;
            select_stmt_stream
                    << "SELECT * FROM [" << table_name << "] LIMIT 1";
            exec(select_stmt_stream.str());
        } catch (const std::exception& ex) {
            return false;
        }
        return true;
    }

    int64_t last_rowid() const
    {
        return sqlite3_last_insert_rowid(connection_.get());
    }

private:
    rtiboost::shared_ptr<sqlite3> connection_;

    static const std::string default_sqlite_init_string_;
    std::string sqlite_init_string_;
};

/**
 * This class is supposed to be sub-classed by classes that contain an
 * SQLite connection, for example, our metadata or discovery file
 * abstractions.
 */
class AbstractSQLiteObject {
public:
    AbstractSQLiteObject(
            const std::string& sqlite_init_string
                    = SQLiteConnection::default_sqlite_init_string()) :
        connection_(sqlite_init_string) { }
    virtual ~AbstractSQLiteObject()
    {
        connection_.disconnect();
    }

    virtual SQLiteConnection& connection() { return connection_; }

protected:

    SQLiteConnection connection_;
};


} } /* rti::app_utils */

#endif /* HPP_RTI_APPUTILS_SQLiteConnection_HPP_ */
