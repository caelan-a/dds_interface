/******************************************************************************
 * (c) Copyright, Real-Time Innovations, 2018-
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 *****************************************************************************/

#ifndef HPP_APPUTILS_PATH_HPP_
#define HPP_APPUTILS_PATH_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdint.h>
#include <cerrno>

#include <sys/types.h>
#include <sys/stat.h>

#if defined(RTI_UNIX) || defined(RTI_QNX)
#include <unistd.h>
#include <time.h>
#endif

#if defined(RTI_UNIX) || defined(RTI_QNX)
  #if !defined(_XOPEN_SOURCE) && !defined(RTI_DARWIN)
    #define _XOPEN_SOURCE 600
  #endif
#include <ftw.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdint.h>
#endif

#ifdef RTI_WIN32
#include <windows.h>
#endif

#include "osapi/osapi_type.h"
#include "osapi/osapi_utility.h"

#include <rti/core/Exception.hpp>
#include <rti/apputils/ServiceException.hpp>

namespace rti { namespace apputils { namespace util {

class Path {
public:
    Path() { }

    Path(const std::string& path) : path_string_(path)
    {
        path_string_ = remove_double_separators(path_string_);
        path_string_ = remove_trailing_separators(path_string_);
    }

    Path(const Path& path) : path_string_(path.path_string_)
    {
    }

    operator const std::string&() const { return path_string_; }

    operator const char *() const { return path_string_.c_str(); }

    void append(const std::string& fragment)
    {
        if (!path_string_.empty()) {
            path_string_ += "/";
        }
        path_string_ += fragment;
        path_string_ = remove_double_separators(path_string_);
        path_string_ = remove_trailing_separators(path_string_);
    }

    void append(const Path& fragment)
    {
        append((const std::string&) fragment);
    }

    void operator +=(const std::string& fragment)
    {
        append(fragment);
    }

    void operator +=(const Path& fragment)
    {
        append((const std::string&) fragment);
    }

    int compare(const Path& other)
    {
        return path_string_.compare((const std::string&) other);
    }

    int compare(const std::string& other)
    {
        return path_string_.compare(other);
    }

    int compare(const char *other)
    {
        return path_string_.compare(other);
    }

    /**
     * Path is interpreted as a file. Return whether the file exists or not.
     */
    bool exists() const
    {
        // Check if the path is a file and if it exists
        if (RTIOsapiUtility_fileExists(path_string_.c_str()) == RTI_TRUE) {
            return true;
        } else {
#if defined(RTI_UNIX) || defined(RTI_QNX)
            // Otherwise check if it's a directory and if it exists
            struct stat info;
            if (stat(path_string_.c_str(), &info) == 0
                    && S_ISDIR(info.st_mode)) {
                return true;
            } else {
                return false;
            }
#elif defined(RTI_WIN32)
#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & _S_IFMT) == _S_IFDIR)
#endif
            // Otherwise check if it's a directory and if it exists
            struct _stat info;
            if (_stat(path_string_.c_str(), &info) == 0
                    && S_ISDIR(info.st_mode)) {
                return true;
            } else {
                return false;
            }
#endif
        }
    }

    static void create_directory(const Path& path)
    {
#if defined(RTI_UNIX) || defined(RTI_QNX)
        errno = 0;
        if (mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0
                && (errno != EEXIST)) {
            std::stringstream error_msg;
            error_msg << "!create directory: "
                    << path
                    << "\n"
                    << "CreateDirectory() error code: "
                    << errno
                    << "\n";
            throw dds::core::IllegalOperationError(error_msg.str());
        }
#elif defined(RTI_WIN32)
        if (!CreateDirectory(path, NULL)) {
            DWORD last_error = GetLastError();
            if (last_error != ERROR_ALREADY_EXISTS) {
                std::stringstream error_msg;
                error_msg << "!create directory: "
                        << path
                        << "\n"
                        << "CreateDirectory() error code: "
                        << last_error
                        << "\n";
                throw dds::core::IllegalOperationError(error_msg.str());
            }
        }
#else
        throw dds::core::IllegalOperationError("unsupported");
#endif
    }

    /**
     * Interpreting the path as a directory, create any non-existing directories
     * in the path.
     */
    void create_directory()
    {
        // If the path is a file, and it exists, exit
        if (exists()) {
            return;
        }
        // Get splits, build a
        std::vector<std::string> splits = split();
        Path aux;
        for (std::vector<std::string>::iterator split_it = splits.begin();
                split_it != splits.end();
                split_it++) {
            aux += *split_it;
            if (!aux.exists()) {
                create_directory(aux);
            }
        }
    }

    static void remove_directory(const Path& path)
    {
#if defined(RTI_UNIX) || defined(RTI_QNX)
        errno = 0;
        if (nftw(path, remove_file, 20, FTW_DEPTH) == -1) {
            if (errno != ENOENT) {
                perror("nftw");
                RTI_THROW_SERVICE_EXCEPTION(
                        &RTI_LOG_ANY_FAILURE_s,
                        "remove_directory() error");
            }
        }
#else
        if (!delete_directory(path)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_ANY_ss,
                    "Failed to delete directory: ",
                    path);
        }
#endif
    }

    void copy_to(const Path& destination_path)
    {
        if (!exists()) {
            return;
        }
        try {
            std::ifstream  src(path_string_.c_str(), std::ios::binary);
            std::ofstream dst(
                    destination_path.path_string_.c_str(),
                    std::ios::binary);
            dst << src.rdbuf();
        } catch (std::exception& ex) {
            std::stringstream stream;
            stream << "Failed to copy file" << std::endl;
            stream << "    origin     : " << path_string_ << std::endl;
            stream << "    destination: " << destination_path << std::endl;
            stream << "    error message: " << ex.what() << std::endl;
            DDSLog_exception(&RTI_LOG_ANY_s, stream.str().c_str());
        }
    }

    void append_extension(const std::string& extension)
    {
        path_string_ += extension;
    }

    /**
     * This method detects and returns a (last) "." in the last split of a
     * string. The substring after this dot is considered to be the file
     * extension.
     */
    std::string detect_file_extension()
    {
        std::string file_extension;
        std::vector<std::string> splits = split();
        std::string last_split = splits[splits.size()-1];
        std::string::size_type pos = last_split.find_last_of('.');
        if (pos != std::string::npos) {
            file_extension = last_split.substr(pos+1);
        }
        return file_extension;
    }

    /**
     * This method returns the file name (the last split in the path). Depending
     * on the parameter, it will strip out the file extension or not.
     */
    std::string detect_file_name(bool include_extension = true) const
    {
        std::vector<std::string> splits = split();
        std::string last_split = splits[splits.size()-1];
        if (!include_extension) {
            std::string::size_type pos = last_split.find_last_of('.');
            if (pos != std::string::npos) {
                return last_split.substr(0, pos);
            }
        }
        return last_split;
    }

    std::vector<std::string> split() const
    {
        std::vector<std::string> splits;
        std::istringstream stream(path_string_);
        std::string string_split;
        bool prepend_separator = false;
        while (getline(stream, string_split, '/')) {
            if (string_split.empty()) {
                // This can happen if the path is absolute (starts with a
                // separator). The first split should contain that separator.
                // Signal this with a boolean variable
                prepend_separator = true;
                continue;
            }
            if (prepend_separator) {
                splits.push_back("/" + string_split);
                prepend_separator = false;
            } else {
                splits.push_back(string_split);
            }
        }
        return splits;
    }

    static Path from_splits(const std::vector<std::string>& splits)
    {
        Path path;
        for (size_t i = 0; i < splits.size(); i++) {
            path += splits[i];
        }
        return path;
    }

    uint64_t file_size() const
    {
#ifdef RTI_WIN32
        HANDLE file_handle = CreateFile(
                path_string_.c_str(),
                GENERIC_READ,
                FILE_SHARE_READ | FILE_SHARE_WRITE,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        if (file_handle == INVALID_HANDLE_VALUE) {
            DDSLog_warn(
                    &RTI_LOG_ANY_ss,
                    "Failed to get file size for file: ",
                    path_string_.c_str());
            return 0;
        }
        LARGE_INTEGER size;
        if (!GetFileSizeEx(file_handle, &size)) {
            CloseHandle(file_handle);
            DDSLog_warn(
                    &RTI_LOG_ANY_ss,
                    "Failed to get file size for file: ",
                    path_string_.c_str());
            return 0;
        }
        CloseHandle(file_handle);
        return size.QuadPart;
#else
        struct stat buffer;
        if (stat(path_string_.c_str(), &buffer) != 0) {
            DDSLog_warn(
                    &RTI_LOG_ANY_ss,
                    "Failed to get file size for file: ",
                    path_string_.c_str());
            return 0;
        }
        return (uint64_t) buffer.st_size;
#endif
    }

#if !defined(RTI_INTY)
/*
 * CORE-10727 [Antonio L]:
 * cwd() is not supported in all the architectures. We have to
 * port it.
 */
    static Path cwd()
    {
        char working_directory[RTI_OSAPI_STRING_SEQ_STRING_MAX_SIZE] = {0};
        bool no_error = false;

        no_error = (RTIOsapiUtility_getCurrentDirectory(
                working_directory,
                RTI_OSAPI_STRING_SEQ_STRING_MAX_SIZE) != NULL);
        if (!no_error) {
            int errnum = RTIOsapiUtility_getError();
            char error_string[RTI_OSAPI_ERROR_STRING_MAX_SIZE] = {0};
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_OS_FAILURE_sXs,
                    "getcwd",
                    errnum,
                    RTIOsapiUtility_getErrorString(
                            error_string,
                            RTI_OSAPI_ERROR_STRING_MAX_SIZE,
                            errnum));
        }
        return Path(working_directory);
    }
#endif

private:

    std::string path_string_;

#define SEPARATOR_STR "/"

    /**
     * Converter Windows-style separators into Unix-style ones
     */
    std::string normalize(const std::string& path)
    {
        std::string normalized(path);
        const std::string SEPARATOR(SEPARATOR_STR);
        std::string::size_type pos = normalized.find_first_of('\\');
        while (pos != std::string::npos) {
            normalized = normalized.replace(pos, 1, SEPARATOR);
            pos = normalized.find_first_of('\\', pos + 1);
        }
        return normalized;
    }

    std::string remove_trailing_separators(const std::string& path)
    {
        std::string modified(normalize(path));
        if (!modified.empty() && modified.at(modified.size() - 1) == '/') {
            modified.erase(modified.size() - 1);
        }
        return modified;
    }

    std::string remove_double_separators(std::string& path)
    {
        const std::string DOUBLE_SEPARATOR_STR("//");
        std::string modified(normalize(path));
        std::string::size_type pos = modified.find(DOUBLE_SEPARATOR_STR);
        while (pos != std::string::npos) {
            modified = modified.replace(
                    pos,
                    DOUBLE_SEPARATOR_STR.size(),
                    SEPARATOR_STR);
            pos = modified.find(DOUBLE_SEPARATOR_STR, pos + 1);
        }
        return modified;
    }

    static int remove_file(
        const char *fpath,
        const struct stat *sb,
        int tflag,
        struct FTW *ftwbuf)
    {
        RTIOsapiUtility_unusedParameter(sb);
        RTIOsapiUtility_unusedParameter(tflag);
        RTIOsapiUtility_unusedParameter(ftwbuf);

#ifdef RTI_QNX
        /**
         * In QNX we create the working directory in the NFS. Because the NFS
         * have important delays, if we try to remove all the directories,
         * the remove will fail because the NFS will accept the request to remove
         * the files, but they won't be removed once we reach the upper level.
         * Therefore, we will not remove the directories of the QNX testers
         */
        struct stat buf;
        int err = stat(fpath, &buf);
        errno = 0;
        if(err == 0 && (buf.st_mode&_S_IFMT) != S_IFDIR)
            errno = remove(fpath);
        return errno;
#else
        return remove(fpath);
#endif
    }

#ifdef RTI_WIN32

    static int is_dots(const char *path)
    {
        if (strcmp(path, ".") != 0 && strcmp(path, "..") != 0) {
            return RTI_FALSE;
        }
        return RTI_TRUE;
    }

    static int delete_directory(const char *dir_name)
    {
        HANDLE hFind;  // file handle
        WIN32_FIND_DATA findFileData;

        TCHAR dirPath[MAX_PATH];
        TCHAR fileName[MAX_PATH];
        RTIBool bSearch = RTI_TRUE;

        // searching all files
        strcpy(dirPath, dir_name);
        strcat(dirPath, "\\*");
        strcpy(fileName, dir_name);
        strcat(fileName, "\\");

        hFind = FindFirstFile(dirPath, &findFileData);
        if(hFind == INVALID_HANDLE_VALUE) {
            return RTI_FALSE;
        }
        strcpy(dirPath, fileName);

        while(bSearch) {
            if(FindNextFile(hFind,&findFileData)) {
                if(is_dots(findFileData.cFileName)) {
                    continue;
                }
                strcat(fileName,findFileData.cFileName);
                if((findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    // we have found a directory, recurse
                    if(!delete_directory(fileName)) {
                        FindClose(hFind);
                        return RTI_FALSE; // directory couldn't be deleted
                    }
                    RemoveDirectory(fileName); // remove the empty directory
                    strcpy(fileName,dirPath);
                }
                else {
                    if(!DeleteFile(fileName)) {  // delete the file
                        FindClose(hFind);
                        return RTI_FALSE;
                    }
                    strcpy(fileName,dirPath);
                }
            }
            else {
                if(GetLastError() == ERROR_NO_MORE_FILES) { // no more files there
                    bSearch = RTI_FALSE;
                } else {
                    // some error occured, close the handle and return FALSE
                    FindClose(hFind);
                    return RTI_FALSE;
                }
            }
        }
        FindClose(hFind);
        return RemoveDirectory(dir_name); // remove the empty directory
    }

#endif

};

} } } /* rti::apputils::util */

#endif /* HPP_APPUTILS_PATH_HPP_ */
