

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from RecordingServiceMonitoring.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef RecordingServiceMonitoring_741490610_hpp
#define RecordingServiceMonitoring_741490610_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "ServiceCommon.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
namespace RTI {
    namespace RecordingService {
        namespace Monitoring {
            using namespace ::RTI::Service;
            using namespace ::RTI::Service::Monitoring;

            class NDDSUSERDllExport TopicConfig
            : public RTI::Service::Monitoring::EntityConfig {
              public:
                TopicConfig();

                TopicConfig(
                    const RTI::Service::ResourceId& resource_id,
                    const RTI::Service::XmlString& configuration,
                    const std::string& topic_name,
                    const std::string& registered_type_name,
                    const std::string& participant_name,
                    const RTI::Service::Monitoring::ResourceGuid& topic_group);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicConfig (TopicConfig&&) = default;
                TopicConfig& operator=(TopicConfig&&) = default;
                TopicConfig& operator=(const TopicConfig&) = default;
                TopicConfig(const TopicConfig&) = default;
                #else
                TopicConfig(TopicConfig&& other_) OMG_NOEXCEPT;  
                TopicConfig& operator=(TopicConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& topic_name() OMG_NOEXCEPT {
                    return m_topic_name_;
                }

                const std::string& topic_name() const OMG_NOEXCEPT {
                    return m_topic_name_;
                }

                void topic_name(const std::string& value) {
                    m_topic_name_ = value;
                }

                std::string& registered_type_name() OMG_NOEXCEPT {
                    return m_registered_type_name_;
                }

                const std::string& registered_type_name() const OMG_NOEXCEPT {
                    return m_registered_type_name_;
                }

                void registered_type_name(const std::string& value) {
                    m_registered_type_name_ = value;
                }

                std::string& participant_name() OMG_NOEXCEPT {
                    return m_participant_name_;
                }

                const std::string& participant_name() const OMG_NOEXCEPT {
                    return m_participant_name_;
                }

                void participant_name(const std::string& value) {
                    m_participant_name_ = value;
                }

                RTI::Service::Monitoring::ResourceGuid& topic_group() OMG_NOEXCEPT {
                    return m_topic_group_;
                }

                const RTI::Service::Monitoring::ResourceGuid& topic_group() const OMG_NOEXCEPT {
                    return m_topic_group_;
                }

                void topic_group(const RTI::Service::Monitoring::ResourceGuid& value) {
                    m_topic_group_ = value;
                }

                bool operator == (const TopicConfig& other_) const;
                bool operator != (const TopicConfig& other_) const;

                void swap(TopicConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_topic_name_;
                std::string m_registered_type_name_;
                std::string m_participant_name_;
                RTI::Service::Monitoring::ResourceGuid m_topic_group_;

            };

            inline void swap(TopicConfig& a, TopicConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicConfig& sample);

            class NDDSUSERDllExport TopicEvent
            : public RTI::Service::Monitoring::EntityEvent {
              public:
                TopicEvent();

                explicit TopicEvent(
                    const RTI::Service::EntityStateKind& state,
                    int32_t _dummy);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicEvent (TopicEvent&&) = default;
                TopicEvent& operator=(TopicEvent&&) = default;
                TopicEvent& operator=(const TopicEvent&) = default;
                TopicEvent(const TopicEvent&) = default;
                #else
                TopicEvent(TopicEvent&& other_) OMG_NOEXCEPT;  
                TopicEvent& operator=(TopicEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                int32_t& _dummy() OMG_NOEXCEPT {
                    return m__dummy_;
                }

                const int32_t& _dummy() const OMG_NOEXCEPT {
                    return m__dummy_;
                }

                void _dummy(int32_t value) {
                    m__dummy_ = value;
                }

                bool operator == (const TopicEvent& other_) const;
                bool operator != (const TopicEvent& other_) const;

                void swap(TopicEvent& other_) OMG_NOEXCEPT ;

              private:

                int32_t m__dummy_;

            };

            inline void swap(TopicEvent& a, TopicEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicEvent& sample);

            class NDDSUSERDllExport TopicPeriodic {
              public:
                TopicPeriodic();

                TopicPeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance,
                    const ::dds::core::optional< RTI::Service::Monitoring::CountStatus >& matched_status);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicPeriodic (TopicPeriodic&&) = default;
                TopicPeriodic& operator=(TopicPeriodic&&) = default;
                TopicPeriodic& operator=(const TopicPeriodic&) = default;
                TopicPeriodic(const TopicPeriodic&) = default;
                #else
                TopicPeriodic(TopicPeriodic&& other_) OMG_NOEXCEPT;  
                TopicPeriodic& operator=(TopicPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() const OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                void network_performance(const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& value) {
                    m_network_performance_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::CountStatus >& matched_status() OMG_NOEXCEPT {
                    return m_matched_status_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::CountStatus >& matched_status() const OMG_NOEXCEPT {
                    return m_matched_status_;
                }

                void matched_status(const ::dds::core::optional< RTI::Service::Monitoring::CountStatus >& value) {
                    m_matched_status_ = value;
                }

                bool operator == (const TopicPeriodic& other_) const;
                bool operator != (const TopicPeriodic& other_) const;

                void swap(TopicPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance > m_network_performance_;
                ::dds::core::optional< RTI::Service::Monitoring::CountStatus > m_matched_status_;

            };

            inline void swap(TopicPeriodic& a, TopicPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicPeriodic& sample);

            class NDDSUSERDllExport TopicGroupConfig
            : public RTI::Service::Monitoring::EntityConfig {
              public:
                TopicGroupConfig();

                explicit TopicGroupConfig(
                    const RTI::Service::ResourceId& resource_id,
                    const RTI::Service::XmlString& configuration,
                    const std::string& participant_name);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicGroupConfig (TopicGroupConfig&&) = default;
                TopicGroupConfig& operator=(TopicGroupConfig&&) = default;
                TopicGroupConfig& operator=(const TopicGroupConfig&) = default;
                TopicGroupConfig(const TopicGroupConfig&) = default;
                #else
                TopicGroupConfig(TopicGroupConfig&& other_) OMG_NOEXCEPT;  
                TopicGroupConfig& operator=(TopicGroupConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& participant_name() OMG_NOEXCEPT {
                    return m_participant_name_;
                }

                const std::string& participant_name() const OMG_NOEXCEPT {
                    return m_participant_name_;
                }

                void participant_name(const std::string& value) {
                    m_participant_name_ = value;
                }

                bool operator == (const TopicGroupConfig& other_) const;
                bool operator != (const TopicGroupConfig& other_) const;

                void swap(TopicGroupConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_participant_name_;

            };

            inline void swap(TopicGroupConfig& a, TopicGroupConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicGroupConfig& sample);

            class NDDSUSERDllExport TopicGroupEvent
            : public RTI::Service::Monitoring::EntityEvent {
              public:
                TopicGroupEvent();

                explicit TopicGroupEvent(
                    const RTI::Service::EntityStateKind& state,
                    int32_t _dummy);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicGroupEvent (TopicGroupEvent&&) = default;
                TopicGroupEvent& operator=(TopicGroupEvent&&) = default;
                TopicGroupEvent& operator=(const TopicGroupEvent&) = default;
                TopicGroupEvent(const TopicGroupEvent&) = default;
                #else
                TopicGroupEvent(TopicGroupEvent&& other_) OMG_NOEXCEPT;  
                TopicGroupEvent& operator=(TopicGroupEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                int32_t& _dummy() OMG_NOEXCEPT {
                    return m__dummy_;
                }

                const int32_t& _dummy() const OMG_NOEXCEPT {
                    return m__dummy_;
                }

                void _dummy(int32_t value) {
                    m__dummy_ = value;
                }

                bool operator == (const TopicGroupEvent& other_) const;
                bool operator != (const TopicGroupEvent& other_) const;

                void swap(TopicGroupEvent& other_) OMG_NOEXCEPT ;

              private:

                int32_t m__dummy_;

            };

            inline void swap(TopicGroupEvent& a, TopicGroupEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicGroupEvent& sample);

            class NDDSUSERDllExport TopicGroupPeriodic {
              public:
                TopicGroupPeriodic();

                TopicGroupPeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance,
                    ::rti::core::int64 topic_count);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                TopicGroupPeriodic (TopicGroupPeriodic&&) = default;
                TopicGroupPeriodic& operator=(TopicGroupPeriodic&&) = default;
                TopicGroupPeriodic& operator=(const TopicGroupPeriodic&) = default;
                TopicGroupPeriodic(const TopicGroupPeriodic&) = default;
                #else
                TopicGroupPeriodic(TopicGroupPeriodic&& other_) OMG_NOEXCEPT;  
                TopicGroupPeriodic& operator=(TopicGroupPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() const OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                void network_performance(const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& value) {
                    m_network_performance_ = value;
                }

                ::rti::core::int64& topic_count() OMG_NOEXCEPT {
                    return m_topic_count_;
                }

                const ::rti::core::int64& topic_count() const OMG_NOEXCEPT {
                    return m_topic_count_;
                }

                void topic_count(::rti::core::int64 value) {
                    m_topic_count_ = value;
                }

                bool operator == (const TopicGroupPeriodic& other_) const;
                bool operator != (const TopicGroupPeriodic& other_) const;

                void swap(TopicGroupPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance > m_network_performance_;
                ::rti::core::int64 m_topic_count_;

            };

            inline void swap(TopicGroupPeriodic& a, TopicGroupPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TopicGroupPeriodic& sample);

            class NDDSUSERDllExport SessionConfig
            : public RTI::Service::Monitoring::EntityConfig {
              public:
                SessionConfig();

                explicit SessionConfig(
                    const RTI::Service::ResourceId& resource_id,
                    const RTI::Service::XmlString& configuration,
                    const std::string& default_participant_name);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SessionConfig (SessionConfig&&) = default;
                SessionConfig& operator=(SessionConfig&&) = default;
                SessionConfig& operator=(const SessionConfig&) = default;
                SessionConfig(const SessionConfig&) = default;
                #else
                SessionConfig(SessionConfig&& other_) OMG_NOEXCEPT;  
                SessionConfig& operator=(SessionConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& default_participant_name() OMG_NOEXCEPT {
                    return m_default_participant_name_;
                }

                const std::string& default_participant_name() const OMG_NOEXCEPT {
                    return m_default_participant_name_;
                }

                void default_participant_name(const std::string& value) {
                    m_default_participant_name_ = value;
                }

                bool operator == (const SessionConfig& other_) const;
                bool operator != (const SessionConfig& other_) const;

                void swap(SessionConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_default_participant_name_;

            };

            inline void swap(SessionConfig& a, SessionConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SessionConfig& sample);

            class NDDSUSERDllExport SessionEvent
            : public RTI::Service::Monitoring::EntityEvent {
              public:
                SessionEvent();

                explicit SessionEvent(
                    const RTI::Service::EntityStateKind& state,
                    int32_t _dummy);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SessionEvent (SessionEvent&&) = default;
                SessionEvent& operator=(SessionEvent&&) = default;
                SessionEvent& operator=(const SessionEvent&) = default;
                SessionEvent(const SessionEvent&) = default;
                #else
                SessionEvent(SessionEvent&& other_) OMG_NOEXCEPT;  
                SessionEvent& operator=(SessionEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                int32_t& _dummy() OMG_NOEXCEPT {
                    return m__dummy_;
                }

                const int32_t& _dummy() const OMG_NOEXCEPT {
                    return m__dummy_;
                }

                void _dummy(int32_t value) {
                    m__dummy_ = value;
                }

                bool operator == (const SessionEvent& other_) const;
                bool operator != (const SessionEvent& other_) const;

                void swap(SessionEvent& other_) OMG_NOEXCEPT ;

              private:

                int32_t m__dummy_;

            };

            inline void swap(SessionEvent& a, SessionEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SessionEvent& sample);

            class NDDSUSERDllExport SessionPeriodic {
              public:
                SessionPeriodic();

                SessionPeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance,
                    const ::dds::core::optional< RTI::Service::Monitoring::ThreadPoolPeriodic >& thread_pool);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SessionPeriodic (SessionPeriodic&&) = default;
                SessionPeriodic& operator=(SessionPeriodic&&) = default;
                SessionPeriodic& operator=(const SessionPeriodic&) = default;
                SessionPeriodic(const SessionPeriodic&) = default;
                #else
                SessionPeriodic(SessionPeriodic&& other_) OMG_NOEXCEPT;  
                SessionPeriodic& operator=(SessionPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& network_performance() const OMG_NOEXCEPT {
                    return m_network_performance_;
                }

                void network_performance(const ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance >& value) {
                    m_network_performance_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::ThreadPoolPeriodic >& thread_pool() OMG_NOEXCEPT {
                    return m_thread_pool_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::ThreadPoolPeriodic >& thread_pool() const OMG_NOEXCEPT {
                    return m_thread_pool_;
                }

                void thread_pool(const ::dds::core::optional< RTI::Service::Monitoring::ThreadPoolPeriodic >& value) {
                    m_thread_pool_ = value;
                }

                bool operator == (const SessionPeriodic& other_) const;
                bool operator != (const SessionPeriodic& other_) const;

                void swap(SessionPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::NetworkPerformance > m_network_performance_;
                ::dds::core::optional< RTI::Service::Monitoring::ThreadPoolPeriodic > m_thread_pool_;

            };

            inline void swap(SessionPeriodic& a, SessionPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SessionPeriodic& sample);

            class NDDSUSERDllExport SqliteDatabaseConfig {
              public:
                SqliteDatabaseConfig();

                SqliteDatabaseConfig(
                    const std::string& db_directory,
                    const ::dds::core::optional< std::string >& execution_directory_expression,
                    const ::dds::core::optional< std::string >& user_data_file_expression);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SqliteDatabaseConfig (SqliteDatabaseConfig&&) = default;
                SqliteDatabaseConfig& operator=(SqliteDatabaseConfig&&) = default;
                SqliteDatabaseConfig& operator=(const SqliteDatabaseConfig&) = default;
                SqliteDatabaseConfig(const SqliteDatabaseConfig&) = default;
                #else
                SqliteDatabaseConfig(SqliteDatabaseConfig&& other_) OMG_NOEXCEPT;  
                SqliteDatabaseConfig& operator=(SqliteDatabaseConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& db_directory() OMG_NOEXCEPT {
                    return m_db_directory_;
                }

                const std::string& db_directory() const OMG_NOEXCEPT {
                    return m_db_directory_;
                }

                void db_directory(const std::string& value) {
                    m_db_directory_ = value;
                }

                ::dds::core::optional< std::string >& execution_directory_expression() OMG_NOEXCEPT {
                    return m_execution_directory_expression_;
                }

                const ::dds::core::optional< std::string >& execution_directory_expression() const OMG_NOEXCEPT {
                    return m_execution_directory_expression_;
                }

                void execution_directory_expression(const ::dds::core::optional< std::string >& value) {
                    m_execution_directory_expression_ = value;
                }

                ::dds::core::optional< std::string >& user_data_file_expression() OMG_NOEXCEPT {
                    return m_user_data_file_expression_;
                }

                const ::dds::core::optional< std::string >& user_data_file_expression() const OMG_NOEXCEPT {
                    return m_user_data_file_expression_;
                }

                void user_data_file_expression(const ::dds::core::optional< std::string >& value) {
                    m_user_data_file_expression_ = value;
                }

                bool operator == (const SqliteDatabaseConfig& other_) const;
                bool operator != (const SqliteDatabaseConfig& other_) const;

                void swap(SqliteDatabaseConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_db_directory_;
                ::dds::core::optional< std::string > m_execution_directory_expression_;
                ::dds::core::optional< std::string > m_user_data_file_expression_;

            };

            inline void swap(SqliteDatabaseConfig& a, SqliteDatabaseConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SqliteDatabaseConfig& sample);

            class NDDSUSERDllExport SqliteDatabaseEvent {
              public:
                SqliteDatabaseEvent();

                SqliteDatabaseEvent(
                    const ::dds::core::optional< std::string >& current_db_directory,
                    const ::dds::core::optional< std::string >& current_file,
                    const ::dds::core::optional< int32_t >& rollover_count);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SqliteDatabaseEvent (SqliteDatabaseEvent&&) = default;
                SqliteDatabaseEvent& operator=(SqliteDatabaseEvent&&) = default;
                SqliteDatabaseEvent& operator=(const SqliteDatabaseEvent&) = default;
                SqliteDatabaseEvent(const SqliteDatabaseEvent&) = default;
                #else
                SqliteDatabaseEvent(SqliteDatabaseEvent&& other_) OMG_NOEXCEPT;  
                SqliteDatabaseEvent& operator=(SqliteDatabaseEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< std::string >& current_db_directory() OMG_NOEXCEPT {
                    return m_current_db_directory_;
                }

                const ::dds::core::optional< std::string >& current_db_directory() const OMG_NOEXCEPT {
                    return m_current_db_directory_;
                }

                void current_db_directory(const ::dds::core::optional< std::string >& value) {
                    m_current_db_directory_ = value;
                }

                ::dds::core::optional< std::string >& current_file() OMG_NOEXCEPT {
                    return m_current_file_;
                }

                const ::dds::core::optional< std::string >& current_file() const OMG_NOEXCEPT {
                    return m_current_file_;
                }

                void current_file(const ::dds::core::optional< std::string >& value) {
                    m_current_file_ = value;
                }

                ::dds::core::optional< int32_t >& rollover_count() OMG_NOEXCEPT {
                    return m_rollover_count_;
                }

                const ::dds::core::optional< int32_t >& rollover_count() const OMG_NOEXCEPT {
                    return m_rollover_count_;
                }

                void rollover_count(const ::dds::core::optional< int32_t >& value) {
                    m_rollover_count_ = value;
                }

                bool operator == (const SqliteDatabaseEvent& other_) const;
                bool operator != (const SqliteDatabaseEvent& other_) const;

                void swap(SqliteDatabaseEvent& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< std::string > m_current_db_directory_;
                ::dds::core::optional< std::string > m_current_file_;
                ::dds::core::optional< int32_t > m_rollover_count_;

            };

            inline void swap(SqliteDatabaseEvent& a, SqliteDatabaseEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SqliteDatabaseEvent& sample);

            class NDDSUSERDllExport SqliteDatabasePeriodic {
              public:
                SqliteDatabasePeriodic();

                SqliteDatabasePeriodic(
                    const ::dds::core::optional< std::string >& current_file,
                    const ::dds::core::optional< ::rti::core::uint64 >& current_file_size,
                    int32_t current_timestamp_sec,
                    uint32_t current_timestamp_nanosec);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                SqliteDatabasePeriodic (SqliteDatabasePeriodic&&) = default;
                SqliteDatabasePeriodic& operator=(SqliteDatabasePeriodic&&) = default;
                SqliteDatabasePeriodic& operator=(const SqliteDatabasePeriodic&) = default;
                SqliteDatabasePeriodic(const SqliteDatabasePeriodic&) = default;
                #else
                SqliteDatabasePeriodic(SqliteDatabasePeriodic&& other_) OMG_NOEXCEPT;  
                SqliteDatabasePeriodic& operator=(SqliteDatabasePeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< std::string >& current_file() OMG_NOEXCEPT {
                    return m_current_file_;
                }

                const ::dds::core::optional< std::string >& current_file() const OMG_NOEXCEPT {
                    return m_current_file_;
                }

                void current_file(const ::dds::core::optional< std::string >& value) {
                    m_current_file_ = value;
                }

                ::dds::core::optional< ::rti::core::uint64 >& current_file_size() OMG_NOEXCEPT {
                    return m_current_file_size_;
                }

                const ::dds::core::optional< ::rti::core::uint64 >& current_file_size() const OMG_NOEXCEPT {
                    return m_current_file_size_;
                }

                void current_file_size(const ::dds::core::optional< ::rti::core::uint64 >& value) {
                    m_current_file_size_ = value;
                }

                int32_t& current_timestamp_sec() OMG_NOEXCEPT {
                    return m_current_timestamp_sec_;
                }

                const int32_t& current_timestamp_sec() const OMG_NOEXCEPT {
                    return m_current_timestamp_sec_;
                }

                void current_timestamp_sec(int32_t value) {
                    m_current_timestamp_sec_ = value;
                }

                uint32_t& current_timestamp_nanosec() OMG_NOEXCEPT {
                    return m_current_timestamp_nanosec_;
                }

                const uint32_t& current_timestamp_nanosec() const OMG_NOEXCEPT {
                    return m_current_timestamp_nanosec_;
                }

                void current_timestamp_nanosec(uint32_t value) {
                    m_current_timestamp_nanosec_ = value;
                }

                bool operator == (const SqliteDatabasePeriodic& other_) const;
                bool operator != (const SqliteDatabasePeriodic& other_) const;

                void swap(SqliteDatabasePeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< std::string > m_current_file_;
                ::dds::core::optional< ::rti::core::uint64 > m_current_file_size_;
                int32_t m_current_timestamp_sec_;
                uint32_t m_current_timestamp_nanosec_;

            };

            inline void swap(SqliteDatabasePeriodic& a, SqliteDatabasePeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const SqliteDatabasePeriodic& sample);

            class NDDSUSERDllExport ParticipantInfo {
              public:
                ParticipantInfo();

                explicit ParticipantInfo(
                    const std::string& name);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ParticipantInfo (ParticipantInfo&&) = default;
                ParticipantInfo& operator=(ParticipantInfo&&) = default;
                ParticipantInfo& operator=(const ParticipantInfo&) = default;
                ParticipantInfo(const ParticipantInfo&) = default;
                #else
                ParticipantInfo(ParticipantInfo&& other_) OMG_NOEXCEPT;  
                ParticipantInfo& operator=(ParticipantInfo&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& name() OMG_NOEXCEPT {
                    return m_name_;
                }

                const std::string& name() const OMG_NOEXCEPT {
                    return m_name_;
                }

                void name(const std::string& value) {
                    m_name_ = value;
                }

                bool operator == (const ParticipantInfo& other_) const;
                bool operator != (const ParticipantInfo& other_) const;

                void swap(ParticipantInfo& other_) OMG_NOEXCEPT ;

              private:

                std::string m_name_;

            };

            inline void swap(ParticipantInfo& a, ParticipantInfo& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ParticipantInfo& sample);

            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
            // On Windows, dll-export template instantiations of standard types used by
            // other dll-exported types
            template class NDDSUSERDllExport std::allocator< RTI::RecordingService::Monitoring::ParticipantInfo >;
            template class NDDSUSERDllExport std::vector< RTI::RecordingService::Monitoring::ParticipantInfo >;
            #endif
            class NDDSUSERDllExport ServiceConfig
            : public RTI::Service::Monitoring::EntityConfig {
              public:
                ServiceConfig();

                ServiceConfig(
                    const RTI::Service::ResourceId& resource_id,
                    const RTI::Service::XmlString& configuration,
                    const std::string& application_name,
                    const RTI::Service::Monitoring::ResourceGuid& application_guid,
                    const ::dds::core::optional< RTI::Service::Monitoring::HostConfig >& host,
                    const ::dds::core::optional< RTI::Service::Monitoring::ProcessConfig >& process,
                    const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseConfig >& builtin_sqlite,
                    const ::dds::core::optional< std::vector< RTI::RecordingService::Monitoring::ParticipantInfo > >& participants);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ServiceConfig (ServiceConfig&&) = default;
                ServiceConfig& operator=(ServiceConfig&&) = default;
                ServiceConfig& operator=(const ServiceConfig&) = default;
                ServiceConfig(const ServiceConfig&) = default;
                #else
                ServiceConfig(ServiceConfig&& other_) OMG_NOEXCEPT;  
                ServiceConfig& operator=(ServiceConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& application_name() OMG_NOEXCEPT {
                    return m_application_name_;
                }

                const std::string& application_name() const OMG_NOEXCEPT {
                    return m_application_name_;
                }

                void application_name(const std::string& value) {
                    m_application_name_ = value;
                }

                RTI::Service::Monitoring::ResourceGuid& application_guid() OMG_NOEXCEPT {
                    return m_application_guid_;
                }

                const RTI::Service::Monitoring::ResourceGuid& application_guid() const OMG_NOEXCEPT {
                    return m_application_guid_;
                }

                void application_guid(const RTI::Service::Monitoring::ResourceGuid& value) {
                    m_application_guid_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::HostConfig >& host() OMG_NOEXCEPT {
                    return m_host_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::HostConfig >& host() const OMG_NOEXCEPT {
                    return m_host_;
                }

                void host(const ::dds::core::optional< RTI::Service::Monitoring::HostConfig >& value) {
                    m_host_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::ProcessConfig >& process() OMG_NOEXCEPT {
                    return m_process_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::ProcessConfig >& process() const OMG_NOEXCEPT {
                    return m_process_;
                }

                void process(const ::dds::core::optional< RTI::Service::Monitoring::ProcessConfig >& value) {
                    m_process_ = value;
                }

                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseConfig >& builtin_sqlite() OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseConfig >& builtin_sqlite() const OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                void builtin_sqlite(const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseConfig >& value) {
                    m_builtin_sqlite_ = value;
                }

                ::dds::core::optional< std::vector< RTI::RecordingService::Monitoring::ParticipantInfo > >& participants() OMG_NOEXCEPT {
                    return m_participants_;
                }

                const ::dds::core::optional< std::vector< RTI::RecordingService::Monitoring::ParticipantInfo > >& participants() const OMG_NOEXCEPT {
                    return m_participants_;
                }

                void participants(const ::dds::core::optional< std::vector< RTI::RecordingService::Monitoring::ParticipantInfo > >& value) {
                    m_participants_ = value;
                }

                bool operator == (const ServiceConfig& other_) const;
                bool operator != (const ServiceConfig& other_) const;

                void swap(ServiceConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_application_name_;
                RTI::Service::Monitoring::ResourceGuid m_application_guid_;
                ::dds::core::optional< RTI::Service::Monitoring::HostConfig > m_host_;
                ::dds::core::optional< RTI::Service::Monitoring::ProcessConfig > m_process_;
                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseConfig > m_builtin_sqlite_;
                ::dds::core::optional< std::vector< RTI::RecordingService::Monitoring::ParticipantInfo > > m_participants_;

            };

            inline void swap(ServiceConfig& a, ServiceConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ServiceConfig& sample);

            class NDDSUSERDllExport ServiceEvent
            : public RTI::Service::Monitoring::EntityEvent {
              public:
                ServiceEvent();

                explicit ServiceEvent(
                    const RTI::Service::EntityStateKind& state,
                    const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseEvent >& builtin_sqlite);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ServiceEvent (ServiceEvent&&) = default;
                ServiceEvent& operator=(ServiceEvent&&) = default;
                ServiceEvent& operator=(const ServiceEvent&) = default;
                ServiceEvent(const ServiceEvent&) = default;
                #else
                ServiceEvent(ServiceEvent&& other_) OMG_NOEXCEPT;  
                ServiceEvent& operator=(ServiceEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseEvent >& builtin_sqlite() OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseEvent >& builtin_sqlite() const OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                void builtin_sqlite(const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseEvent >& value) {
                    m_builtin_sqlite_ = value;
                }

                bool operator == (const ServiceEvent& other_) const;
                bool operator != (const ServiceEvent& other_) const;

                void swap(ServiceEvent& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabaseEvent > m_builtin_sqlite_;

            };

            inline void swap(ServiceEvent& a, ServiceEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ServiceEvent& sample);

            class NDDSUSERDllExport ServicePeriodic {
              public:
                ServicePeriodic();

                ServicePeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::HostPeriodic >& host,
                    const ::dds::core::optional< RTI::Service::Monitoring::ProcessPeriodic >& process,
                    ::rti::core::int64 current_timestamp_nanos,
                    const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic >& builtin_sqlite);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ServicePeriodic (ServicePeriodic&&) = default;
                ServicePeriodic& operator=(ServicePeriodic&&) = default;
                ServicePeriodic& operator=(const ServicePeriodic&) = default;
                ServicePeriodic(const ServicePeriodic&) = default;
                #else
                ServicePeriodic(ServicePeriodic&& other_) OMG_NOEXCEPT;  
                ServicePeriodic& operator=(ServicePeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::HostPeriodic >& host() OMG_NOEXCEPT {
                    return m_host_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::HostPeriodic >& host() const OMG_NOEXCEPT {
                    return m_host_;
                }

                void host(const ::dds::core::optional< RTI::Service::Monitoring::HostPeriodic >& value) {
                    m_host_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::ProcessPeriodic >& process() OMG_NOEXCEPT {
                    return m_process_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::ProcessPeriodic >& process() const OMG_NOEXCEPT {
                    return m_process_;
                }

                void process(const ::dds::core::optional< RTI::Service::Monitoring::ProcessPeriodic >& value) {
                    m_process_ = value;
                }

                ::rti::core::int64& current_timestamp_nanos() OMG_NOEXCEPT {
                    return m_current_timestamp_nanos_;
                }

                const ::rti::core::int64& current_timestamp_nanos() const OMG_NOEXCEPT {
                    return m_current_timestamp_nanos_;
                }

                void current_timestamp_nanos(::rti::core::int64 value) {
                    m_current_timestamp_nanos_ = value;
                }

                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic >& builtin_sqlite() OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic >& builtin_sqlite() const OMG_NOEXCEPT {
                    return m_builtin_sqlite_;
                }

                void builtin_sqlite(const ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic >& value) {
                    m_builtin_sqlite_ = value;
                }

                bool operator == (const ServicePeriodic& other_) const;
                bool operator != (const ServicePeriodic& other_) const;

                void swap(ServicePeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::HostPeriodic > m_host_;
                ::dds::core::optional< RTI::Service::Monitoring::ProcessPeriodic > m_process_;
                ::rti::core::int64 m_current_timestamp_nanos_;
                ::dds::core::optional< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic > m_builtin_sqlite_;

            };

            inline void swap(ServicePeriodic& a, ServicePeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ServicePeriodic& sample);

            class NDDSUSERDllExport ConfigUnion {
              public:
                ConfigUnion();

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ConfigUnion (ConfigUnion&&) = default;
                ConfigUnion& operator=(ConfigUnion&&) = default;
                ConfigUnion& operator=(const ConfigUnion&) = default;
                ConfigUnion(const ConfigUnion&) = default;
                #else
                ConfigUnion(ConfigUnion&& other_) OMG_NOEXCEPT;  
                ConfigUnion& operator=(ConfigUnion&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Monitoring::ResourceKind& _d()  {
                    return m_d_;
                }

                const RTI::Service::Monitoring::ResourceKind& _d() const  {
                    return m_d_;
                }

                void _d(const RTI::Service::Monitoring::ResourceKind& value) {
                    m_d_ = value;
                }

                RTI::RecordingService::Monitoring::ServiceConfig& recording_service()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                const RTI::RecordingService::Monitoring::ServiceConfig& recording_service() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                void recording_service(const RTI::RecordingService::Monitoring::ServiceConfig& value) {
                    m_u_.m_recording_service_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE);
                }

                RTI::RecordingService::Monitoring::SessionConfig& recording_session()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                const RTI::RecordingService::Monitoring::SessionConfig& recording_session() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                void recording_session(const RTI::RecordingService::Monitoring::SessionConfig& value) {
                    m_u_.m_recording_session_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION);
                }

                RTI::RecordingService::Monitoring::TopicGroupConfig& recording_topic_group()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                const RTI::RecordingService::Monitoring::TopicGroupConfig& recording_topic_group() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                void recording_topic_group(const RTI::RecordingService::Monitoring::TopicGroupConfig& value) {
                    m_u_.m_recording_topic_group_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP);
                }

                RTI::RecordingService::Monitoring::TopicConfig& recording_topic()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                const RTI::RecordingService::Monitoring::TopicConfig& recording_topic() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::ConfigUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                void recording_topic(const RTI::RecordingService::Monitoring::TopicConfig& value) {
                    m_u_.m_recording_topic_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC);
                }

                bool operator == (const ConfigUnion& other_) const;
                bool operator != (const ConfigUnion& other_) const;

                static RTI::Service::Monitoring::ResourceKind default_discriminator();  

                void swap(ConfigUnion& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Monitoring::ResourceKind m_d_;
                struct NDDSUSERDllExport Union_ {
                    RTI::RecordingService::Monitoring::ServiceConfig m_recording_service_;
                    RTI::RecordingService::Monitoring::SessionConfig m_recording_session_;
                    RTI::RecordingService::Monitoring::TopicGroupConfig m_recording_topic_group_;
                    RTI::RecordingService::Monitoring::TopicConfig m_recording_topic_;
                    Union_();
                    Union_(
                        const RTI::RecordingService::Monitoring::ServiceConfig& recording_service,
                        const RTI::RecordingService::Monitoring::SessionConfig& recording_session,
                        const RTI::RecordingService::Monitoring::TopicGroupConfig& recording_topic_group,
                        const RTI::RecordingService::Monitoring::TopicConfig& recording_topic);
                };
                Union_ m_u_;

            };

            inline void swap(ConfigUnion& a, ConfigUnion& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ConfigUnion& sample);

            class NDDSUSERDllExport Config
            : public RTI::Service::Monitoring::KeyedResource {
              public:
                Config();

                explicit Config(
                    const RTI::Service::Monitoring::ResourceGuid& object_guid,
                    const RTI::Service::Monitoring::ResourceGuid& owner_guid,
                    const RTI::RecordingService::Monitoring::ConfigUnion& value);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                Config (Config&&) = default;
                Config& operator=(Config&&) = default;
                Config& operator=(const Config&) = default;
                Config(const Config&) = default;
                #else
                Config(Config&& other_) OMG_NOEXCEPT;  
                Config& operator=(Config&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::RecordingService::Monitoring::ConfigUnion& value() OMG_NOEXCEPT {
                    return m_value_;
                }

                const RTI::RecordingService::Monitoring::ConfigUnion& value() const OMG_NOEXCEPT {
                    return m_value_;
                }

                void value(const RTI::RecordingService::Monitoring::ConfigUnion& value) {
                    m_value_ = value;
                }

                bool operator == (const Config& other_) const;
                bool operator != (const Config& other_) const;

                void swap(Config& other_) OMG_NOEXCEPT ;

              private:

                RTI::RecordingService::Monitoring::ConfigUnion m_value_;

            };

            inline void swap(Config& a, Config& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Config& sample);

            class NDDSUSERDllExport EventUnion {
              public:
                EventUnion();

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                EventUnion (EventUnion&&) = default;
                EventUnion& operator=(EventUnion&&) = default;
                EventUnion& operator=(const EventUnion&) = default;
                EventUnion(const EventUnion&) = default;
                #else
                EventUnion(EventUnion&& other_) OMG_NOEXCEPT;  
                EventUnion& operator=(EventUnion&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Monitoring::ResourceKind& _d()  {
                    return m_d_;
                }

                const RTI::Service::Monitoring::ResourceKind& _d() const  {
                    return m_d_;
                }

                void _d(const RTI::Service::Monitoring::ResourceKind& value) {
                    m_d_ = value;
                }

                RTI::RecordingService::Monitoring::ServiceEvent& recording_service()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                const RTI::RecordingService::Monitoring::ServiceEvent& recording_service() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                void recording_service(const RTI::RecordingService::Monitoring::ServiceEvent& value) {
                    m_u_.m_recording_service_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE);
                }

                RTI::RecordingService::Monitoring::SessionEvent& recording_session()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                const RTI::RecordingService::Monitoring::SessionEvent& recording_session() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                void recording_session(const RTI::RecordingService::Monitoring::SessionEvent& value) {
                    m_u_.m_recording_session_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION);
                }

                RTI::RecordingService::Monitoring::TopicGroupEvent& recording_topic_group()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                const RTI::RecordingService::Monitoring::TopicGroupEvent& recording_topic_group() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                void recording_topic_group(const RTI::RecordingService::Monitoring::TopicGroupEvent& value) {
                    m_u_.m_recording_topic_group_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP);
                }

                RTI::RecordingService::Monitoring::TopicEvent& recording_topic()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                const RTI::RecordingService::Monitoring::TopicEvent& recording_topic() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::EventUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                void recording_topic(const RTI::RecordingService::Monitoring::TopicEvent& value) {
                    m_u_.m_recording_topic_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC);
                }

                bool operator == (const EventUnion& other_) const;
                bool operator != (const EventUnion& other_) const;

                static RTI::Service::Monitoring::ResourceKind default_discriminator();  

                void swap(EventUnion& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Monitoring::ResourceKind m_d_;
                struct NDDSUSERDllExport Union_ {
                    RTI::RecordingService::Monitoring::ServiceEvent m_recording_service_;
                    RTI::RecordingService::Monitoring::SessionEvent m_recording_session_;
                    RTI::RecordingService::Monitoring::TopicGroupEvent m_recording_topic_group_;
                    RTI::RecordingService::Monitoring::TopicEvent m_recording_topic_;
                    Union_();
                    Union_(
                        const RTI::RecordingService::Monitoring::ServiceEvent& recording_service,
                        const RTI::RecordingService::Monitoring::SessionEvent& recording_session,
                        const RTI::RecordingService::Monitoring::TopicGroupEvent& recording_topic_group,
                        const RTI::RecordingService::Monitoring::TopicEvent& recording_topic);
                };
                Union_ m_u_;

            };

            inline void swap(EventUnion& a, EventUnion& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EventUnion& sample);

            class NDDSUSERDllExport Event
            : public RTI::Service::Monitoring::KeyedResource {
              public:
                Event();

                explicit Event(
                    const RTI::Service::Monitoring::ResourceGuid& object_guid,
                    const RTI::Service::Monitoring::ResourceGuid& owner_guid,
                    const RTI::RecordingService::Monitoring::EventUnion& value);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                Event (Event&&) = default;
                Event& operator=(Event&&) = default;
                Event& operator=(const Event&) = default;
                Event(const Event&) = default;
                #else
                Event(Event&& other_) OMG_NOEXCEPT;  
                Event& operator=(Event&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::RecordingService::Monitoring::EventUnion& value() OMG_NOEXCEPT {
                    return m_value_;
                }

                const RTI::RecordingService::Monitoring::EventUnion& value() const OMG_NOEXCEPT {
                    return m_value_;
                }

                void value(const RTI::RecordingService::Monitoring::EventUnion& value) {
                    m_value_ = value;
                }

                bool operator == (const Event& other_) const;
                bool operator != (const Event& other_) const;

                void swap(Event& other_) OMG_NOEXCEPT ;

              private:

                RTI::RecordingService::Monitoring::EventUnion m_value_;

            };

            inline void swap(Event& a, Event& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Event& sample);

            class NDDSUSERDllExport PeriodicUnion {
              public:
                PeriodicUnion();

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                PeriodicUnion (PeriodicUnion&&) = default;
                PeriodicUnion& operator=(PeriodicUnion&&) = default;
                PeriodicUnion& operator=(const PeriodicUnion&) = default;
                PeriodicUnion(const PeriodicUnion&) = default;
                #else
                PeriodicUnion(PeriodicUnion&& other_) OMG_NOEXCEPT;  
                PeriodicUnion& operator=(PeriodicUnion&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Monitoring::ResourceKind& _d()  {
                    return m_d_;
                }

                const RTI::Service::Monitoring::ResourceKind& _d() const  {
                    return m_d_;
                }

                void _d(const RTI::Service::Monitoring::ResourceKind& value) {
                    m_d_ = value;
                }

                RTI::RecordingService::Monitoring::ServicePeriodic& recording_service()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                const RTI::RecordingService::Monitoring::ServicePeriodic& recording_service() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_service not selected by the discriminator" );
                    }
                    return m_u_.m_recording_service_;
                }

                void recording_service(const RTI::RecordingService::Monitoring::ServicePeriodic& value) {
                    m_u_.m_recording_service_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SERVICE);
                }

                RTI::RecordingService::Monitoring::SessionPeriodic& recording_session()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                const RTI::RecordingService::Monitoring::SessionPeriodic& recording_session() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_session not selected by the discriminator" );
                    }
                    return m_u_.m_recording_session_;
                }

                void recording_session(const RTI::RecordingService::Monitoring::SessionPeriodic& value) {
                    m_u_.m_recording_session_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_SESSION);
                }

                RTI::RecordingService::Monitoring::TopicGroupPeriodic& recording_topic_group()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                const RTI::RecordingService::Monitoring::TopicGroupPeriodic& recording_topic_group() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_topic_group not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_group_;
                }

                void recording_topic_group(const RTI::RecordingService::Monitoring::TopicGroupPeriodic& value) {
                    m_u_.m_recording_topic_group_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC_GROUP);
                }

                RTI::RecordingService::Monitoring::TopicPeriodic& recording_topic()  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                const RTI::RecordingService::Monitoring::TopicPeriodic& recording_topic() const  {
                    if ( _d() != (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC)) {
                        throw ::dds::core::PreconditionNotMetError(
                            "RTI::RecordingService::Monitoring::PeriodicUnion::recording_topic not selected by the discriminator" );
                    }
                    return m_u_.m_recording_topic_;
                }

                void recording_topic(const RTI::RecordingService::Monitoring::TopicPeriodic& value) {
                    m_u_.m_recording_topic_ = value;
                    m_d_= (RTI::Service::Monitoring::ResourceKind::RECORDING_TOPIC);
                }

                bool operator == (const PeriodicUnion& other_) const;
                bool operator != (const PeriodicUnion& other_) const;

                static RTI::Service::Monitoring::ResourceKind default_discriminator();  

                void swap(PeriodicUnion& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Monitoring::ResourceKind m_d_;
                struct NDDSUSERDllExport Union_ {
                    RTI::RecordingService::Monitoring::ServicePeriodic m_recording_service_;
                    RTI::RecordingService::Monitoring::SessionPeriodic m_recording_session_;
                    RTI::RecordingService::Monitoring::TopicGroupPeriodic m_recording_topic_group_;
                    RTI::RecordingService::Monitoring::TopicPeriodic m_recording_topic_;
                    Union_();
                    Union_(
                        const RTI::RecordingService::Monitoring::ServicePeriodic& recording_service,
                        const RTI::RecordingService::Monitoring::SessionPeriodic& recording_session,
                        const RTI::RecordingService::Monitoring::TopicGroupPeriodic& recording_topic_group,
                        const RTI::RecordingService::Monitoring::TopicPeriodic& recording_topic);
                };
                Union_ m_u_;

            };

            inline void swap(PeriodicUnion& a, PeriodicUnion& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PeriodicUnion& sample);

            class NDDSUSERDllExport Periodic
            : public RTI::Service::Monitoring::KeyedResource {
              public:
                Periodic();

                explicit Periodic(
                    const RTI::Service::Monitoring::ResourceGuid& object_guid,
                    const RTI::Service::Monitoring::ResourceGuid& owner_guid,
                    const RTI::RecordingService::Monitoring::PeriodicUnion& value);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                Periodic (Periodic&&) = default;
                Periodic& operator=(Periodic&&) = default;
                Periodic& operator=(const Periodic&) = default;
                Periodic(const Periodic&) = default;
                #else
                Periodic(Periodic&& other_) OMG_NOEXCEPT;  
                Periodic& operator=(Periodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::RecordingService::Monitoring::PeriodicUnion& value() OMG_NOEXCEPT {
                    return m_value_;
                }

                const RTI::RecordingService::Monitoring::PeriodicUnion& value() const OMG_NOEXCEPT {
                    return m_value_;
                }

                void value(const RTI::RecordingService::Monitoring::PeriodicUnion& value) {
                    m_value_ = value;
                }

                bool operator == (const Periodic& other_) const;
                bool operator != (const Periodic& other_) const;

                void swap(Periodic& other_) OMG_NOEXCEPT ;

              private:

                RTI::RecordingService::Monitoring::PeriodicUnion m_value_;

            };

            inline void swap(Periodic& a, Periodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const Periodic& sample);

        } // namespace Monitoring  
    } // namespace RecordingService  
} // namespace RTI  

namespace rti {
    namespace flat {
        namespace topic {
            using namespace ::RTI::Service;
            using namespace ::RTI::Service::Monitoring;
        }
    }
}
namespace dds {
    namespace topic {

        using namespace ::RTI::Service;
        using namespace ::RTI::Service::Monitoring;

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicGroupConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicGroupConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicGroupConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicGroupConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicGroupConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicGroupEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicGroupEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicGroupEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicGroupEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicGroupEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::TopicGroupPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::TopicGroupPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::TopicGroupPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::TopicGroupPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::TopicGroupPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SessionConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SessionConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SessionConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SessionConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SessionConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SessionEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SessionEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SessionEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SessionEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SessionEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SessionPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SessionPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SessionPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SessionPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SessionPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SqliteDatabaseConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SqliteDatabaseConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SqliteDatabaseConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SqliteDatabaseConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SqliteDatabaseConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SqliteDatabaseEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SqliteDatabaseEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SqliteDatabaseEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SqliteDatabaseEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SqliteDatabaseEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::SqliteDatabasePeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::SqliteDatabasePeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::SqliteDatabasePeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::ParticipantInfo > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::ParticipantInfo";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::ParticipantInfo > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::ParticipantInfo& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::ParticipantInfo& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::ServiceConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::ServiceConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::ServiceConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::ServiceConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::ServiceConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::ServiceEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::ServiceEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::ServiceEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::ServiceEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::ServiceEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::ServicePeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::ServicePeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::ServicePeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::ServicePeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::ServicePeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::ConfigUnion > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::ConfigUnion";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::ConfigUnion > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::ConfigUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::ConfigUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::Config > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::Config";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::Monitoring::Config > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::Config > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::Monitoring::Config& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::Monitoring::Config& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::Config& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::Config& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::EventUnion > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::EventUnion";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::EventUnion > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::EventUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::EventUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::Event > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::Event";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::Monitoring::Event > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::Event > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::Monitoring::Event& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::Monitoring::Event& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::Event& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::Event& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::PeriodicUnion > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::PeriodicUnion";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::PeriodicUnion > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::PeriodicUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::PeriodicUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::Monitoring::Periodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::Monitoring::Periodic";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::Monitoring::Periodic > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::Monitoring::Periodic > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::Monitoring::Periodic& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::Monitoring::Periodic& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::Monitoring::Periodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::Monitoring::Periodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        using namespace ::RTI::Service;

        using namespace ::RTI::Service::Monitoring;

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicGroupConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicGroupConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicGroupEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicGroupEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::TopicGroupPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::TopicGroupPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SessionConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SessionConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SessionEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SessionEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SessionPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SessionPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SqliteDatabaseConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SqliteDatabaseConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SqliteDatabaseEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SqliteDatabaseEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::SqliteDatabasePeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::ParticipantInfo > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::ParticipantInfo > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::ServiceConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::ServiceConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::ServiceEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::ServiceEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::ServicePeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::ServicePeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::ConfigUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::ConfigUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::Config > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::Config > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::EventUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::EventUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::Event > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::Event > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::PeriodicUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::PeriodicUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::Monitoring::Periodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::Monitoring::Periodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // RecordingServiceMonitoring_741490610_hpp

