

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceCommon.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ServiceCommon_1902812022_hpp
#define ServiceCommon_1902812022_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_COMMON)
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

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_COMMON)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_COMMON)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace Service {

        static const int32_t BOUNDED_STRING_LENGTH_MAX = 255L;

        typedef std::string BoundedString;
        struct BoundedString_AliasTag_t {};

        static const int32_t FILE_PATH_MAX_LENGTH = 1024L;

        typedef std::string FilePath;
        struct FilePath_AliasTag_t {};

        static const int32_t RESOURCE_IDENTIFIER_LENGTH_MAX = 2048L;

        typedef std::string ResourceId;
        struct ResourceId_AliasTag_t {};

        typedef std::string XmlString;
        struct XmlString_AliasTag_t {};
        struct EntityStateKind_def {
            enum type {
                INVALID, 
                ENABLED, 
                DISABLED, 
                STARTED, 
                STOPPED, 
                RUNNING, 
                PAUSED
            };
            static type get_default(){ return INVALID;}
        };

        typedef ::dds::core::safe_enum< EntityStateKind_def > EntityStateKind;
        NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const EntityStateKind& sample);

        class NDDSUSERDllExport EntityState {
          public:
            EntityState();

            explicit EntityState(
                const RTI::Service::EntityStateKind& state);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            EntityState (EntityState&&) = default;
            EntityState& operator=(EntityState&&) = default;
            EntityState& operator=(const EntityState&) = default;
            EntityState(const EntityState&) = default;
            #else
            EntityState(EntityState&& other_) OMG_NOEXCEPT;  
            EntityState& operator=(EntityState&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            RTI::Service::EntityStateKind& state() OMG_NOEXCEPT {
                return m_state_;
            }

            const RTI::Service::EntityStateKind& state() const OMG_NOEXCEPT {
                return m_state_;
            }

            void state(const RTI::Service::EntityStateKind& value) {
                m_state_ = value;
            }

            bool operator == (const EntityState& other_) const;
            bool operator != (const EntityState& other_) const;

            void swap(EntityState& other_) OMG_NOEXCEPT ;

          private:

            RTI::Service::EntityStateKind m_state_;

        };

        inline void swap(EntityState& a, EntityState& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityState& sample);

        static const int32_t BUILTIN_TOPIC_KEY_VALUE_LENGTH = 4L;

        class NDDSUSERDllExport BuiltinTopicKey {
          public:
            BuiltinTopicKey();

            explicit BuiltinTopicKey(
                const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            BuiltinTopicKey (BuiltinTopicKey&&) = default;
            BuiltinTopicKey& operator=(BuiltinTopicKey&&) = default;
            BuiltinTopicKey& operator=(const BuiltinTopicKey&) = default;
            BuiltinTopicKey(const BuiltinTopicKey&) = default;
            #else
            BuiltinTopicKey(BuiltinTopicKey&& other_) OMG_NOEXCEPT;  
            BuiltinTopicKey& operator=(BuiltinTopicKey&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value() OMG_NOEXCEPT {
                return m_value_;
            }

            const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value() const OMG_NOEXCEPT {
                return m_value_;
            }

            void value(const ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)>& value) {
                m_value_ = value;
            }

            bool operator == (const BuiltinTopicKey& other_) const;
            bool operator != (const BuiltinTopicKey& other_) const;

            void swap(BuiltinTopicKey& other_) OMG_NOEXCEPT ;

          private:

            ::dds::core::array< uint32_t, (RTI::Service::BUILTIN_TOPIC_KEY_VALUE_LENGTH)> m_value_;

        };

        inline void swap(BuiltinTopicKey& a, BuiltinTopicKey& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BuiltinTopicKey& sample);

        namespace Monitoring {

            static const int32_t RESOURCE_GUID_VALUE_LENGTH = 16L;

            class NDDSUSERDllExport ResourceGuid {
              public:
                ResourceGuid();

                explicit ResourceGuid(
                    const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ResourceGuid (ResourceGuid&&) = default;
                ResourceGuid& operator=(ResourceGuid&&) = default;
                ResourceGuid& operator=(const ResourceGuid&) = default;
                ResourceGuid(const ResourceGuid&) = default;
                #else
                ResourceGuid(ResourceGuid&& other_) OMG_NOEXCEPT;  
                ResourceGuid& operator=(ResourceGuid&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value() OMG_NOEXCEPT {
                    return m_value_;
                }

                const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value() const OMG_NOEXCEPT {
                    return m_value_;
                }

                void value(const ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)>& value) {
                    m_value_ = value;
                }

                bool operator == (const ResourceGuid& other_) const;
                bool operator != (const ResourceGuid& other_) const;

                void swap(ResourceGuid& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::array< uint8_t, (RTI::Service::Monitoring::RESOURCE_GUID_VALUE_LENGTH)> m_value_;

            };

            inline void swap(ResourceGuid& a, ResourceGuid& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ResourceGuid& sample);

            class NDDSUSERDllExport KeyedResource {
              public:
                KeyedResource();

                KeyedResource(
                    const RTI::Service::Monitoring::ResourceGuid& object_guid,
                    const RTI::Service::Monitoring::ResourceGuid& owner_guid);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                KeyedResource (KeyedResource&&) = default;
                KeyedResource& operator=(KeyedResource&&) = default;
                KeyedResource& operator=(const KeyedResource&) = default;
                KeyedResource(const KeyedResource&) = default;
                #else
                KeyedResource(KeyedResource&& other_) OMG_NOEXCEPT;  
                KeyedResource& operator=(KeyedResource&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Monitoring::ResourceGuid& object_guid() OMG_NOEXCEPT {
                    return m_object_guid_;
                }

                const RTI::Service::Monitoring::ResourceGuid& object_guid() const OMG_NOEXCEPT {
                    return m_object_guid_;
                }

                void object_guid(const RTI::Service::Monitoring::ResourceGuid& value) {
                    m_object_guid_ = value;
                }

                RTI::Service::Monitoring::ResourceGuid& owner_guid() OMG_NOEXCEPT {
                    return m_owner_guid_;
                }

                const RTI::Service::Monitoring::ResourceGuid& owner_guid() const OMG_NOEXCEPT {
                    return m_owner_guid_;
                }

                void owner_guid(const RTI::Service::Monitoring::ResourceGuid& value) {
                    m_owner_guid_ = value;
                }

                bool operator == (const KeyedResource& other_) const;
                bool operator != (const KeyedResource& other_) const;

                void swap(KeyedResource& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Monitoring::ResourceGuid m_object_guid_;
                RTI::Service::Monitoring::ResourceGuid m_owner_guid_;

            };

            inline void swap(KeyedResource& a, KeyedResource& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const KeyedResource& sample);

            class NDDSUSERDllExport StatisticMetrics {
              public:
                StatisticMetrics();

                StatisticMetrics(
                    ::rti::core::int64 period_ms,
                    ::rti::core::int64 count,
                    float mean,
                    float minimum,
                    float maximum,
                    float std_dev);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                StatisticMetrics (StatisticMetrics&&) = default;
                StatisticMetrics& operator=(StatisticMetrics&&) = default;
                StatisticMetrics& operator=(const StatisticMetrics&) = default;
                StatisticMetrics(const StatisticMetrics&) = default;
                #else
                StatisticMetrics(StatisticMetrics&& other_) OMG_NOEXCEPT;  
                StatisticMetrics& operator=(StatisticMetrics&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::rti::core::int64& period_ms() OMG_NOEXCEPT {
                    return m_period_ms_;
                }

                const ::rti::core::int64& period_ms() const OMG_NOEXCEPT {
                    return m_period_ms_;
                }

                void period_ms(::rti::core::int64 value) {
                    m_period_ms_ = value;
                }

                ::rti::core::int64& count() OMG_NOEXCEPT {
                    return m_count_;
                }

                const ::rti::core::int64& count() const OMG_NOEXCEPT {
                    return m_count_;
                }

                void count(::rti::core::int64 value) {
                    m_count_ = value;
                }

                float& mean() OMG_NOEXCEPT {
                    return m_mean_;
                }

                const float& mean() const OMG_NOEXCEPT {
                    return m_mean_;
                }

                void mean(float value) {
                    m_mean_ = value;
                }

                float& minimum() OMG_NOEXCEPT {
                    return m_minimum_;
                }

                const float& minimum() const OMG_NOEXCEPT {
                    return m_minimum_;
                }

                void minimum(float value) {
                    m_minimum_ = value;
                }

                float& maximum() OMG_NOEXCEPT {
                    return m_maximum_;
                }

                const float& maximum() const OMG_NOEXCEPT {
                    return m_maximum_;
                }

                void maximum(float value) {
                    m_maximum_ = value;
                }

                float& std_dev() OMG_NOEXCEPT {
                    return m_std_dev_;
                }

                const float& std_dev() const OMG_NOEXCEPT {
                    return m_std_dev_;
                }

                void std_dev(float value) {
                    m_std_dev_ = value;
                }

                bool operator == (const StatisticMetrics& other_) const;
                bool operator != (const StatisticMetrics& other_) const;

                void swap(StatisticMetrics& other_) OMG_NOEXCEPT ;

              private:

                ::rti::core::int64 m_period_ms_;
                ::rti::core::int64 m_count_;
                float m_mean_;
                float m_minimum_;
                float m_maximum_;
                float m_std_dev_;

            };

            inline void swap(StatisticMetrics& a, StatisticMetrics& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StatisticMetrics& sample);

            class NDDSUSERDllExport StatisticVariable {
              public:
                StatisticVariable();

                explicit StatisticVariable(
                    const RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                StatisticVariable (StatisticVariable&&) = default;
                StatisticVariable& operator=(StatisticVariable&&) = default;
                StatisticVariable& operator=(const StatisticVariable&) = default;
                StatisticVariable(const StatisticVariable&) = default;
                #else
                StatisticVariable(StatisticVariable&& other_) OMG_NOEXCEPT;  
                StatisticVariable& operator=(StatisticVariable&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics() OMG_NOEXCEPT {
                    return m_publication_period_metrics_;
                }

                const RTI::Service::Monitoring::StatisticMetrics& publication_period_metrics() const OMG_NOEXCEPT {
                    return m_publication_period_metrics_;
                }

                void publication_period_metrics(const RTI::Service::Monitoring::StatisticMetrics& value) {
                    m_publication_period_metrics_ = value;
                }

                bool operator == (const StatisticVariable& other_) const;
                bool operator != (const StatisticVariable& other_) const;

                void swap(StatisticVariable& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Monitoring::StatisticMetrics m_publication_period_metrics_;

            };

            inline void swap(StatisticVariable& a, StatisticVariable& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const StatisticVariable& sample);

            class NDDSUSERDllExport CountStatus {
              public:
                CountStatus();

                CountStatus(
                    ::rti::core::int64 total_count,
                    ::rti::core::int64 current_count,
                    ::rti::core::int64 current_count_peak);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                CountStatus (CountStatus&&) = default;
                CountStatus& operator=(CountStatus&&) = default;
                CountStatus& operator=(const CountStatus&) = default;
                CountStatus(const CountStatus&) = default;
                #else
                CountStatus(CountStatus&& other_) OMG_NOEXCEPT;  
                CountStatus& operator=(CountStatus&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::rti::core::int64& total_count() OMG_NOEXCEPT {
                    return m_total_count_;
                }

                const ::rti::core::int64& total_count() const OMG_NOEXCEPT {
                    return m_total_count_;
                }

                void total_count(::rti::core::int64 value) {
                    m_total_count_ = value;
                }

                ::rti::core::int64& current_count() OMG_NOEXCEPT {
                    return m_current_count_;
                }

                const ::rti::core::int64& current_count() const OMG_NOEXCEPT {
                    return m_current_count_;
                }

                void current_count(::rti::core::int64 value) {
                    m_current_count_ = value;
                }

                ::rti::core::int64& current_count_peak() OMG_NOEXCEPT {
                    return m_current_count_peak_;
                }

                const ::rti::core::int64& current_count_peak() const OMG_NOEXCEPT {
                    return m_current_count_peak_;
                }

                void current_count_peak(::rti::core::int64 value) {
                    m_current_count_peak_ = value;
                }

                bool operator == (const CountStatus& other_) const;
                bool operator != (const CountStatus& other_) const;

                void swap(CountStatus& other_) OMG_NOEXCEPT ;

              private:

                ::rti::core::int64 m_total_count_;
                ::rti::core::int64 m_current_count_;
                ::rti::core::int64 m_current_count_peak_;

            };

            inline void swap(CountStatus& a, CountStatus& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CountStatus& sample);

            class NDDSUSERDllExport ProcessConfig {
              public:
                ProcessConfig();

                explicit ProcessConfig(
                    ::rti::core::uint64 id);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ProcessConfig (ProcessConfig&&) = default;
                ProcessConfig& operator=(ProcessConfig&&) = default;
                ProcessConfig& operator=(const ProcessConfig&) = default;
                ProcessConfig(const ProcessConfig&) = default;
                #else
                ProcessConfig(ProcessConfig&& other_) OMG_NOEXCEPT;  
                ProcessConfig& operator=(ProcessConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::rti::core::uint64& id() OMG_NOEXCEPT {
                    return m_id_;
                }

                const ::rti::core::uint64& id() const OMG_NOEXCEPT {
                    return m_id_;
                }

                void id(::rti::core::uint64 value) {
                    m_id_ = value;
                }

                bool operator == (const ProcessConfig& other_) const;
                bool operator != (const ProcessConfig& other_) const;

                void swap(ProcessConfig& other_) OMG_NOEXCEPT ;

              private:

                ::rti::core::uint64 m_id_;

            };

            inline void swap(ProcessConfig& a, ProcessConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProcessConfig& sample);

            class NDDSUSERDllExport ProcessPeriodic {
              public:
                ProcessPeriodic();

                ProcessPeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& total_memory_kb,
                    int32_t uptime_sec);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ProcessPeriodic (ProcessPeriodic&&) = default;
                ProcessPeriodic& operator=(ProcessPeriodic&&) = default;
                ProcessPeriodic& operator=(const ProcessPeriodic&) = default;
                ProcessPeriodic(const ProcessPeriodic&) = default;
                #else
                ProcessPeriodic(ProcessPeriodic&& other_) OMG_NOEXCEPT;  
                ProcessPeriodic& operator=(ProcessPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_cpu_usage_percentage_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb() OMG_NOEXCEPT {
                    return m_physical_memory_kb_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& physical_memory_kb() const OMG_NOEXCEPT {
                    return m_physical_memory_kb_;
                }

                void physical_memory_kb(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_physical_memory_kb_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& total_memory_kb() OMG_NOEXCEPT {
                    return m_total_memory_kb_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& total_memory_kb() const OMG_NOEXCEPT {
                    return m_total_memory_kb_;
                }

                void total_memory_kb(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_total_memory_kb_ = value;
                }

                int32_t& uptime_sec() OMG_NOEXCEPT {
                    return m_uptime_sec_;
                }

                const int32_t& uptime_sec() const OMG_NOEXCEPT {
                    return m_uptime_sec_;
                }

                void uptime_sec(int32_t value) {
                    m_uptime_sec_ = value;
                }

                bool operator == (const ProcessPeriodic& other_) const;
                bool operator != (const ProcessPeriodic& other_) const;

                void swap(ProcessPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_physical_memory_kb_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_total_memory_kb_;
                int32_t m_uptime_sec_;

            };

            inline void swap(ProcessPeriodic& a, ProcessPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ProcessPeriodic& sample);

            class NDDSUSERDllExport ThreadPeriodic {
              public:
                ThreadPeriodic();

                ThreadPeriodic(
                    ::rti::core::uint64 id,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ThreadPeriodic (ThreadPeriodic&&) = default;
                ThreadPeriodic& operator=(ThreadPeriodic&&) = default;
                ThreadPeriodic& operator=(const ThreadPeriodic&) = default;
                ThreadPeriodic(const ThreadPeriodic&) = default;
                #else
                ThreadPeriodic(ThreadPeriodic&& other_) OMG_NOEXCEPT;  
                ThreadPeriodic& operator=(ThreadPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::rti::core::uint64& id() OMG_NOEXCEPT {
                    return m_id_;
                }

                const ::rti::core::uint64& id() const OMG_NOEXCEPT {
                    return m_id_;
                }

                void id(::rti::core::uint64 value) {
                    m_id_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_cpu_usage_percentage_ = value;
                }

                bool operator == (const ThreadPeriodic& other_) const;
                bool operator != (const ThreadPeriodic& other_) const;

                void swap(ThreadPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::rti::core::uint64 m_id_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;

            };

            inline void swap(ThreadPeriodic& a, ThreadPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ThreadPeriodic& sample);

            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_COMMON)
            // On Windows, dll-export template instantiations of standard types used by
            // other dll-exported types
            template class NDDSUSERDllExport std::allocator< RTI::Service::Monitoring::ThreadPeriodic >;
            template class NDDSUSERDllExport std::vector< RTI::Service::Monitoring::ThreadPeriodic >;
            #endif
            class NDDSUSERDllExport ThreadPoolPeriodic {
              public:
                ThreadPoolPeriodic();

                explicit ThreadPoolPeriodic(
                    const ::dds::core::optional< std::vector< RTI::Service::Monitoring::ThreadPeriodic > >& threads);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                ThreadPoolPeriodic (ThreadPoolPeriodic&&) = default;
                ThreadPoolPeriodic& operator=(ThreadPoolPeriodic&&) = default;
                ThreadPoolPeriodic& operator=(const ThreadPoolPeriodic&) = default;
                ThreadPoolPeriodic(const ThreadPoolPeriodic&) = default;
                #else
                ThreadPoolPeriodic(ThreadPoolPeriodic&& other_) OMG_NOEXCEPT;  
                ThreadPoolPeriodic& operator=(ThreadPoolPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< std::vector< RTI::Service::Monitoring::ThreadPeriodic > >& threads() OMG_NOEXCEPT {
                    return m_threads_;
                }

                const ::dds::core::optional< std::vector< RTI::Service::Monitoring::ThreadPeriodic > >& threads() const OMG_NOEXCEPT {
                    return m_threads_;
                }

                void threads(const ::dds::core::optional< std::vector< RTI::Service::Monitoring::ThreadPeriodic > >& value) {
                    m_threads_ = value;
                }

                bool operator == (const ThreadPoolPeriodic& other_) const;
                bool operator != (const ThreadPoolPeriodic& other_) const;

                void swap(ThreadPoolPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< std::vector< RTI::Service::Monitoring::ThreadPeriodic > > m_threads_;

            };

            inline void swap(ThreadPoolPeriodic& a, ThreadPoolPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ThreadPoolPeriodic& sample);

            class NDDSUSERDllExport HostPeriodic {
              public:
                HostPeriodic();

                HostPeriodic(
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_memory_kb,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb,
                    int32_t uptime_sec);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                HostPeriodic (HostPeriodic&&) = default;
                HostPeriodic& operator=(HostPeriodic&&) = default;
                HostPeriodic& operator=(const HostPeriodic&) = default;
                HostPeriodic(const HostPeriodic&) = default;
                #else
                HostPeriodic(HostPeriodic&& other_) OMG_NOEXCEPT;  
                HostPeriodic& operator=(HostPeriodic&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& cpu_usage_percentage() const OMG_NOEXCEPT {
                    return m_cpu_usage_percentage_;
                }

                void cpu_usage_percentage(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_cpu_usage_percentage_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_memory_kb() OMG_NOEXCEPT {
                    return m_free_memory_kb_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_memory_kb() const OMG_NOEXCEPT {
                    return m_free_memory_kb_;
                }

                void free_memory_kb(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_free_memory_kb_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb() OMG_NOEXCEPT {
                    return m_free_swap_memory_kb_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& free_swap_memory_kb() const OMG_NOEXCEPT {
                    return m_free_swap_memory_kb_;
                }

                void free_swap_memory_kb(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_free_swap_memory_kb_ = value;
                }

                int32_t& uptime_sec() OMG_NOEXCEPT {
                    return m_uptime_sec_;
                }

                const int32_t& uptime_sec() const OMG_NOEXCEPT {
                    return m_uptime_sec_;
                }

                void uptime_sec(int32_t value) {
                    m_uptime_sec_ = value;
                }

                bool operator == (const HostPeriodic& other_) const;
                bool operator != (const HostPeriodic& other_) const;

                void swap(HostPeriodic& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_cpu_usage_percentage_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_free_memory_kb_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_free_swap_memory_kb_;
                int32_t m_uptime_sec_;

            };

            inline void swap(HostPeriodic& a, HostPeriodic& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HostPeriodic& sample);

            class NDDSUSERDllExport HostConfig {
              public:
                HostConfig();

                HostConfig(
                    const std::string& name,
                    uint32_t id,
                    ::rti::core::int64 total_memory_kb,
                    ::rti::core::int64 total_swap_memory_kb,
                    const std::string& target);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                HostConfig (HostConfig&&) = default;
                HostConfig& operator=(HostConfig&&) = default;
                HostConfig& operator=(const HostConfig&) = default;
                HostConfig(const HostConfig&) = default;
                #else
                HostConfig(HostConfig&& other_) OMG_NOEXCEPT;  
                HostConfig& operator=(HostConfig&&  other_) OMG_NOEXCEPT;
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

                uint32_t& id() OMG_NOEXCEPT {
                    return m_id_;
                }

                const uint32_t& id() const OMG_NOEXCEPT {
                    return m_id_;
                }

                void id(uint32_t value) {
                    m_id_ = value;
                }

                ::rti::core::int64& total_memory_kb() OMG_NOEXCEPT {
                    return m_total_memory_kb_;
                }

                const ::rti::core::int64& total_memory_kb() const OMG_NOEXCEPT {
                    return m_total_memory_kb_;
                }

                void total_memory_kb(::rti::core::int64 value) {
                    m_total_memory_kb_ = value;
                }

                ::rti::core::int64& total_swap_memory_kb() OMG_NOEXCEPT {
                    return m_total_swap_memory_kb_;
                }

                const ::rti::core::int64& total_swap_memory_kb() const OMG_NOEXCEPT {
                    return m_total_swap_memory_kb_;
                }

                void total_swap_memory_kb(::rti::core::int64 value) {
                    m_total_swap_memory_kb_ = value;
                }

                std::string& target() OMG_NOEXCEPT {
                    return m_target_;
                }

                const std::string& target() const OMG_NOEXCEPT {
                    return m_target_;
                }

                void target(const std::string& value) {
                    m_target_ = value;
                }

                bool operator == (const HostConfig& other_) const;
                bool operator != (const HostConfig& other_) const;

                void swap(HostConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_name_;
                uint32_t m_id_;
                ::rti::core::int64 m_total_memory_kb_;
                ::rti::core::int64 m_total_swap_memory_kb_;
                std::string m_target_;

            };

            inline void swap(HostConfig& a, HostConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const HostConfig& sample);

            class NDDSUSERDllExport NetworkPerformance {
              public:
                NetworkPerformance();

                NetworkPerformance(
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& samples_per_sec,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec,
                    const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& latency_millisec);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                NetworkPerformance (NetworkPerformance&&) = default;
                NetworkPerformance& operator=(NetworkPerformance&&) = default;
                NetworkPerformance& operator=(const NetworkPerformance&) = default;
                NetworkPerformance(const NetworkPerformance&) = default;
                #else
                NetworkPerformance(NetworkPerformance&& other_) OMG_NOEXCEPT;  
                NetworkPerformance& operator=(NetworkPerformance&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& samples_per_sec() OMG_NOEXCEPT {
                    return m_samples_per_sec_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& samples_per_sec() const OMG_NOEXCEPT {
                    return m_samples_per_sec_;
                }

                void samples_per_sec(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_samples_per_sec_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec() OMG_NOEXCEPT {
                    return m_bytes_per_sec_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& bytes_per_sec() const OMG_NOEXCEPT {
                    return m_bytes_per_sec_;
                }

                void bytes_per_sec(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_bytes_per_sec_ = value;
                }

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& latency_millisec() OMG_NOEXCEPT {
                    return m_latency_millisec_;
                }

                const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& latency_millisec() const OMG_NOEXCEPT {
                    return m_latency_millisec_;
                }

                void latency_millisec(const ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable >& value) {
                    m_latency_millisec_ = value;
                }

                bool operator == (const NetworkPerformance& other_) const;
                bool operator != (const NetworkPerformance& other_) const;

                void swap(NetworkPerformance& other_) OMG_NOEXCEPT ;

              private:

                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_samples_per_sec_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_bytes_per_sec_;
                ::dds::core::optional< RTI::Service::Monitoring::StatisticVariable > m_latency_millisec_;

            };

            inline void swap(NetworkPerformance& a, NetworkPerformance& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const NetworkPerformance& sample);

            class NDDSUSERDllExport EntityConfig {
              public:
                EntityConfig();

                EntityConfig(
                    const std::string& resource_id,
                    const std::string& configuration);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                EntityConfig (EntityConfig&&) = default;
                EntityConfig& operator=(EntityConfig&&) = default;
                EntityConfig& operator=(const EntityConfig&) = default;
                EntityConfig(const EntityConfig&) = default;
                #else
                EntityConfig(EntityConfig&& other_) OMG_NOEXCEPT;  
                EntityConfig& operator=(EntityConfig&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                std::string& resource_id() OMG_NOEXCEPT {
                    return m_resource_id_;
                }

                const std::string& resource_id() const OMG_NOEXCEPT {
                    return m_resource_id_;
                }

                void resource_id(const std::string& value) {
                    m_resource_id_ = value;
                }

                std::string& configuration() OMG_NOEXCEPT {
                    return m_configuration_;
                }

                const std::string& configuration() const OMG_NOEXCEPT {
                    return m_configuration_;
                }

                void configuration(const std::string& value) {
                    m_configuration_ = value;
                }

                bool operator == (const EntityConfig& other_) const;
                bool operator != (const EntityConfig& other_) const;

                void swap(EntityConfig& other_) OMG_NOEXCEPT ;

              private:

                std::string m_resource_id_;
                std::string m_configuration_;

            };

            inline void swap(EntityConfig& a, EntityConfig& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityConfig& sample);

            class NDDSUSERDllExport EntityEvent {
              public:
                EntityEvent();

                explicit EntityEvent(
                    const RTI::Service::EntityStateKind& state);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                EntityEvent (EntityEvent&&) = default;
                EntityEvent& operator=(EntityEvent&&) = default;
                EntityEvent& operator=(const EntityEvent&) = default;
                EntityEvent(const EntityEvent&) = default;
                #else
                EntityEvent(EntityEvent&& other_) OMG_NOEXCEPT;  
                EntityEvent& operator=(EntityEvent&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::EntityStateKind& state() OMG_NOEXCEPT {
                    return m_state_;
                }

                const RTI::Service::EntityStateKind& state() const OMG_NOEXCEPT {
                    return m_state_;
                }

                void state(const RTI::Service::EntityStateKind& value) {
                    m_state_ = value;
                }

                bool operator == (const EntityEvent& other_) const;
                bool operator != (const EntityEvent& other_) const;

                void swap(EntityEvent& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::EntityStateKind m_state_;

            };

            inline void swap(EntityEvent& a, EntityEvent& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const EntityEvent& sample);

            struct DistributionTopicKind_def {
                enum type {
                    CONFIG, 
                    EVENT, 
                    PERIODIC
                };
                static type get_default(){ return CONFIG;}
            };

            typedef ::dds::core::safe_enum< DistributionTopicKind_def > DistributionTopicKind;
            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const DistributionTopicKind& sample);
            struct ResourceKindIndex_def {
                enum type {
                    DDS_INDEX = 1, 
                    ROUTING_INDEX = 10000, 
                    RECORDING_INDEX = 20000, 
                    CDS_INDEX = 30000
                };
                static type get_default(){ return DDS_INDEX;}
            };

            typedef ::dds::core::safe_enum< ResourceKindIndex_def > ResourceKindIndex;
            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ResourceKindIndex& sample);
            struct ResourceKind_def {
                enum type {
                    UNKNOWN, 
                    ROUTING_SERVICE = 10000, 
                    ROUTING_DOMAIN_ROUTE, 
                    ROUTING_SESSION, 
                    ROUTING_AUTO_ROUTE, 
                    ROUTING_ROUTE, 
                    ROUTING_INPUT, 
                    ROUTING_OUTPUT, 
                    RECORDING_SERVICE = 20000, 
                    RECORDING_SESSION, 
                    RECORDING_TOPIC_GROUP, 
                    RECORDING_TOPIC, 
                    CDS_SERVICE = 30000, 
                    CDS_FORWARDER, 
                    CDS_DATABASE, 
                    CDS_RECEIVER, 
                    CDS_SENDER
                };
                static type get_default(){ return UNKNOWN;}
            };

            typedef ::dds::core::safe_enum< ResourceKind_def > ResourceKind;
            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ResourceKind& sample);

            static const std::string CONFIG_TOPIC_NAME = "rti/service/monitoring/config";

            static const std::string EVENT_TOPIC_NAME = "rti/service/monitoring/event";

            static const std::string PERIODIC_TOPIC_NAME = "rti/service/monitoring/periodic";

            static const std::string CONFIG_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Config";

            static const std::string EVENT_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Event";

            static const std::string PERIODIC_REGISTERED_TYPE_NAME = "RTI::Service::Monitoring::Periodic";
        } // namespace Monitoring  
    } // namespace Service  
} // namespace RTI  

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< RTI::Service::EntityState > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::EntityState";
            }
        };

        template<>
        struct is_topic_type< RTI::Service::EntityState > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::Service::EntityState > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::Service::EntityState& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::Service::EntityState& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::EntityState& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::EntityState& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::BuiltinTopicKey > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::BuiltinTopicKey";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::BuiltinTopicKey > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::BuiltinTopicKey& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::BuiltinTopicKey& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::ResourceGuid > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ResourceGuid";
            }
        };

        template<>
        struct is_topic_type< RTI::Service::Monitoring::ResourceGuid > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::Service::Monitoring::ResourceGuid > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::Service::Monitoring::ResourceGuid& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::Service::Monitoring::ResourceGuid& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::ResourceGuid& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::ResourceGuid& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::KeyedResource > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::KeyedResource";
            }
        };

        template<>
        struct is_topic_type< RTI::Service::Monitoring::KeyedResource > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::Service::Monitoring::KeyedResource > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::Service::Monitoring::KeyedResource& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::Service::Monitoring::KeyedResource& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::KeyedResource& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::KeyedResource& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::StatisticMetrics > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::StatisticMetrics";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::StatisticMetrics > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::StatisticMetrics& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::StatisticMetrics& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::StatisticVariable > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::StatisticVariable";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::StatisticVariable > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::StatisticVariable& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::StatisticVariable& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::CountStatus > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::CountStatus";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::CountStatus > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::CountStatus& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::CountStatus& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::ProcessConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ProcessConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::ProcessConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::ProcessConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::ProcessConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::ProcessPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ProcessPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::ProcessPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::ProcessPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::ProcessPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::ThreadPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ThreadPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::ThreadPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::ThreadPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::ThreadPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::ThreadPoolPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::ThreadPoolPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::ThreadPoolPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::ThreadPoolPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::ThreadPoolPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::HostPeriodic > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::HostPeriodic";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::HostPeriodic > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::HostPeriodic& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::HostPeriodic& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::HostConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::HostConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::HostConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::HostConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::HostConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::NetworkPerformance > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::NetworkPerformance";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::NetworkPerformance > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::NetworkPerformance& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::NetworkPerformance& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::EntityConfig > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::EntityConfig";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::EntityConfig > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::EntityConfig& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::EntityConfig& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Monitoring::EntityEvent > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Monitoring::EntityEvent";
            }
        };

        template<>
        struct topic_type_support< RTI::Service::Monitoring::EntityEvent > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Monitoring::EntityEvent& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Monitoring::EntityEvent& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::BoundedString_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::FilePath_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::ResourceId_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::XmlString_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::EntityStateKind>
        {
            static const RTI::Service::EntityStateKind value;
        };
        template<>
        struct dynamic_type< RTI::Service::EntityStateKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::EntityStateKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::EntityState > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::EntityState > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::BuiltinTopicKey > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::BuiltinTopicKey > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::FINAL;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ResourceGuid > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ResourceGuid > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::FINAL;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::KeyedResource > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::KeyedResource > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::StatisticMetrics > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::StatisticMetrics > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::StatisticVariable > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::StatisticVariable > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::CountStatus > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::CountStatus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ProcessConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ProcessConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ProcessPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ProcessPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ThreadPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ThreadPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ThreadPoolPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ThreadPoolPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::HostPeriodic > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::HostPeriodic > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::HostConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::HostConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::NetworkPerformance > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::NetworkPerformance > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::EntityConfig > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::EntityConfig > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Monitoring::EntityEvent > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::EntityEvent > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::Monitoring::DistributionTopicKind>
        {
            static const RTI::Service::Monitoring::DistributionTopicKind value;
        };
        template<>
        struct dynamic_type< RTI::Service::Monitoring::DistributionTopicKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::DistributionTopicKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::Monitoring::ResourceKindIndex>
        {
            static const RTI::Service::Monitoring::ResourceKindIndex value;
        };
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ResourceKindIndex > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ResourceKindIndex > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::Monitoring::ResourceKind>
        {
            static const RTI::Service::Monitoring::ResourceKind value;
        };
        template<>
        struct dynamic_type< RTI::Service::Monitoring::ResourceKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Monitoring::ResourceKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::MUTABLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_COMMON)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // ServiceCommon_1902812022_hpp

