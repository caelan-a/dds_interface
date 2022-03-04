

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from RecordingServiceTypes.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef RecordingServiceTypes_164879633_hpp
#define RecordingServiceTypes_164879633_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
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

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace RecordingService {

        static const int32_t DATA_TAG_MAX_STRING_SIZE = 256L;

        class NDDSUSERDllExport DataTagParams {
          public:
            DataTagParams();

            DataTagParams(
                float timestamp_offset,
                const std::string& tag_name,
                const std::string& tag_description);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            DataTagParams (DataTagParams&&) = default;
            DataTagParams& operator=(DataTagParams&&) = default;
            DataTagParams& operator=(const DataTagParams&) = default;
            DataTagParams(const DataTagParams&) = default;
            #else
            DataTagParams(DataTagParams&& other_) OMG_NOEXCEPT;  
            DataTagParams& operator=(DataTagParams&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            float& timestamp_offset() OMG_NOEXCEPT {
                return m_timestamp_offset_;
            }

            const float& timestamp_offset() const OMG_NOEXCEPT {
                return m_timestamp_offset_;
            }

            void timestamp_offset(float value) {
                m_timestamp_offset_ = value;
            }

            std::string& tag_name() OMG_NOEXCEPT {
                return m_tag_name_;
            }

            const std::string& tag_name() const OMG_NOEXCEPT {
                return m_tag_name_;
            }

            void tag_name(const std::string& value) {
                m_tag_name_ = value;
            }

            std::string& tag_description() OMG_NOEXCEPT {
                return m_tag_description_;
            }

            const std::string& tag_description() const OMG_NOEXCEPT {
                return m_tag_description_;
            }

            void tag_description(const std::string& value) {
                m_tag_description_ = value;
            }

            bool operator == (const DataTagParams& other_) const;
            bool operator != (const DataTagParams& other_) const;

            void swap(DataTagParams& other_) OMG_NOEXCEPT ;

          private:

            float m_timestamp_offset_;
            std::string m_tag_name_;
            std::string m_tag_description_;

        };

        inline void swap(DataTagParams& a, DataTagParams& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DataTagParams& sample);

        struct BreakpointFormat_def {
            enum type {
                TIMESTAMP = 0, 
                TAG_NAME
            };
            static type get_default(){ return TIMESTAMP;}
        };

        typedef ::dds::core::safe_enum< BreakpointFormat_def > BreakpointFormat;
        NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const BreakpointFormat& sample);

        class NDDSUSERDllExport BreakpointUnion {
          public:
            BreakpointUnion();

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            BreakpointUnion (BreakpointUnion&&) = default;
            BreakpointUnion& operator=(BreakpointUnion&&) = default;
            BreakpointUnion& operator=(const BreakpointUnion&) = default;
            BreakpointUnion(const BreakpointUnion&) = default;
            #else
            BreakpointUnion(BreakpointUnion&& other_) OMG_NOEXCEPT;  
            BreakpointUnion& operator=(BreakpointUnion&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            RTI::RecordingService::BreakpointFormat& _d()  {
                return m_d_;
            }

            const RTI::RecordingService::BreakpointFormat& _d() const  {
                return m_d_;
            }

            void _d(const RTI::RecordingService::BreakpointFormat& value) {
                m_d_ = value;
            }

            ::rti::core::int64& timestamp_nanos()  {
                if ( _d() != (RTI::RecordingService::BreakpointFormat::TIMESTAMP)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::BreakpointUnion::timestamp_nanos not selected by the discriminator" );
                }
                return m_u_.m_timestamp_nanos_;
            }

            const ::rti::core::int64& timestamp_nanos() const  {
                if ( _d() != (RTI::RecordingService::BreakpointFormat::TIMESTAMP)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::BreakpointUnion::timestamp_nanos not selected by the discriminator" );
                }
                return m_u_.m_timestamp_nanos_;
            }

            void timestamp_nanos(::rti::core::int64 value) {
                m_u_.m_timestamp_nanos_ = value;
                m_d_= (RTI::RecordingService::BreakpointFormat::TIMESTAMP);
            }

            std::string& tag_name()  {
                if ( _d() != (RTI::RecordingService::BreakpointFormat::TAG_NAME)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::BreakpointUnion::tag_name not selected by the discriminator" );
                }
                return m_u_.m_tag_name_;
            }

            const std::string& tag_name() const  {
                if ( _d() != (RTI::RecordingService::BreakpointFormat::TAG_NAME)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::BreakpointUnion::tag_name not selected by the discriminator" );
                }
                return m_u_.m_tag_name_;
            }

            void tag_name(const std::string& value) {
                m_u_.m_tag_name_ = value;
                m_d_= (RTI::RecordingService::BreakpointFormat::TAG_NAME);
            }

            bool operator == (const BreakpointUnion& other_) const;
            bool operator != (const BreakpointUnion& other_) const;

            static RTI::RecordingService::BreakpointFormat default_discriminator();  

            void swap(BreakpointUnion& other_) OMG_NOEXCEPT ;

          private:

            RTI::RecordingService::BreakpointFormat m_d_;
            struct NDDSUSERDllExport Union_ {
                ::rti::core::int64 m_timestamp_nanos_;
                std::string m_tag_name_;
                Union_();
                Union_(
                    ::rti::core::int64 timestamp_nanos,
                    const std::string& tag_name);
            };
            Union_ m_u_;

        };

        inline void swap(BreakpointUnion& a, BreakpointUnion& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BreakpointUnion& sample);

        class NDDSUSERDllExport BreakpointParams {
          public:
            BreakpointParams();

            BreakpointParams(
                const ::dds::core::optional< std::string >& label,
                const RTI::RecordingService::BreakpointUnion& value);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            BreakpointParams (BreakpointParams&&) = default;
            BreakpointParams& operator=(BreakpointParams&&) = default;
            BreakpointParams& operator=(const BreakpointParams&) = default;
            BreakpointParams(const BreakpointParams&) = default;
            #else
            BreakpointParams(BreakpointParams&& other_) OMG_NOEXCEPT;  
            BreakpointParams& operator=(BreakpointParams&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            ::dds::core::optional< std::string >& label() OMG_NOEXCEPT {
                return m_label_;
            }

            const ::dds::core::optional< std::string >& label() const OMG_NOEXCEPT {
                return m_label_;
            }

            void label(const ::dds::core::optional< std::string >& value) {
                m_label_ = value;
            }

            RTI::RecordingService::BreakpointUnion& value() OMG_NOEXCEPT {
                return m_value_;
            }

            const RTI::RecordingService::BreakpointUnion& value() const OMG_NOEXCEPT {
                return m_value_;
            }

            void value(const RTI::RecordingService::BreakpointUnion& value) {
                m_value_ = value;
            }

            bool operator == (const BreakpointParams& other_) const;
            bool operator != (const BreakpointParams& other_) const;

            void swap(BreakpointParams& other_) OMG_NOEXCEPT ;

          private:

            ::dds::core::optional< std::string > m_label_;
            RTI::RecordingService::BreakpointUnion m_value_;

        };

        inline void swap(BreakpointParams& a, BreakpointParams& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const BreakpointParams& sample);

        struct ContinueFormat_def {
            enum type {
                OFFSET = 0, 
                SLICE
            };
            static type get_default(){ return OFFSET;}
        };

        typedef ::dds::core::safe_enum< ContinueFormat_def > ContinueFormat;
        NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ContinueFormat& sample);

        class NDDSUSERDllExport ContinueUnion {
          public:
            ContinueUnion();

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            ContinueUnion (ContinueUnion&&) = default;
            ContinueUnion& operator=(ContinueUnion&&) = default;
            ContinueUnion& operator=(const ContinueUnion&) = default;
            ContinueUnion(const ContinueUnion&) = default;
            #else
            ContinueUnion(ContinueUnion&& other_) OMG_NOEXCEPT;  
            ContinueUnion& operator=(ContinueUnion&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            RTI::RecordingService::ContinueFormat& _d()  {
                return m_d_;
            }

            const RTI::RecordingService::ContinueFormat& _d() const  {
                return m_d_;
            }

            void _d(const RTI::RecordingService::ContinueFormat& value) {
                m_d_ = value;
            }

            ::rti::core::int64& offset()  {
                if ( _d() != (RTI::RecordingService::ContinueFormat::OFFSET)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::ContinueUnion::offset not selected by the discriminator" );
                }
                return m_u_.m_offset_;
            }

            const ::rti::core::int64& offset() const  {
                if ( _d() != (RTI::RecordingService::ContinueFormat::OFFSET)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::ContinueUnion::offset not selected by the discriminator" );
                }
                return m_u_.m_offset_;
            }

            void offset(::rti::core::int64 value) {
                m_u_.m_offset_ = value;
                m_d_= (RTI::RecordingService::ContinueFormat::OFFSET);
            }

            ::rti::core::int64& slices()  {
                if ( _d() != (RTI::RecordingService::ContinueFormat::SLICE)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::ContinueUnion::slices not selected by the discriminator" );
                }
                return m_u_.m_slices_;
            }

            const ::rti::core::int64& slices() const  {
                if ( _d() != (RTI::RecordingService::ContinueFormat::SLICE)) {
                    throw ::dds::core::PreconditionNotMetError(
                        "RTI::RecordingService::ContinueUnion::slices not selected by the discriminator" );
                }
                return m_u_.m_slices_;
            }

            void slices(::rti::core::int64 value) {
                m_u_.m_slices_ = value;
                m_d_= (RTI::RecordingService::ContinueFormat::SLICE);
            }

            bool operator == (const ContinueUnion& other_) const;
            bool operator != (const ContinueUnion& other_) const;

            static RTI::RecordingService::ContinueFormat default_discriminator();  

            void swap(ContinueUnion& other_) OMG_NOEXCEPT ;

          private:

            RTI::RecordingService::ContinueFormat m_d_;
            struct NDDSUSERDllExport Union_ {
                ::rti::core::int64 m_offset_;
                ::rti::core::int64 m_slices_;
                Union_();
                Union_(
                    ::rti::core::int64 offset,
                    ::rti::core::int64 slices);
            };
            Union_ m_u_;

        };

        inline void swap(ContinueUnion& a, ContinueUnion& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ContinueUnion& sample);

        class NDDSUSERDllExport ContinueParams {
          public:
            ContinueParams();

            explicit ContinueParams(
                const RTI::RecordingService::ContinueUnion& value);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            ContinueParams (ContinueParams&&) = default;
            ContinueParams& operator=(ContinueParams&&) = default;
            ContinueParams& operator=(const ContinueParams&) = default;
            ContinueParams(const ContinueParams&) = default;
            #else
            ContinueParams(ContinueParams&& other_) OMG_NOEXCEPT;  
            ContinueParams& operator=(ContinueParams&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            RTI::RecordingService::ContinueUnion& value() OMG_NOEXCEPT {
                return m_value_;
            }

            const RTI::RecordingService::ContinueUnion& value() const OMG_NOEXCEPT {
                return m_value_;
            }

            void value(const RTI::RecordingService::ContinueUnion& value) {
                m_value_ = value;
            }

            bool operator == (const ContinueParams& other_) const;
            bool operator != (const ContinueParams& other_) const;

            void swap(ContinueParams& other_) OMG_NOEXCEPT ;

          private:

            RTI::RecordingService::ContinueUnion m_value_;

        };

        inline void swap(ContinueParams& a, ContinueParams& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ContinueParams& sample);

        struct TimerState_def {
            enum type {
                WORKING = 0, 
                PAUSED, 
                BREAKPOINT
            };
            static type get_default(){ return WORKING;}
        };

        typedef ::dds::core::safe_enum< TimerState_def > TimerState;
        NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const TimerState& sample);

        class NDDSUSERDllExport DebugStatus {
          public:
            DebugStatus();

            explicit DebugStatus(
                const RTI::RecordingService::TimerState& status);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            DebugStatus (DebugStatus&&) = default;
            DebugStatus& operator=(DebugStatus&&) = default;
            DebugStatus& operator=(const DebugStatus&) = default;
            DebugStatus(const DebugStatus&) = default;
            #else
            DebugStatus(DebugStatus&& other_) OMG_NOEXCEPT;  
            DebugStatus& operator=(DebugStatus&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            RTI::RecordingService::TimerState& status() OMG_NOEXCEPT {
                return m_status_;
            }

            const RTI::RecordingService::TimerState& status() const OMG_NOEXCEPT {
                return m_status_;
            }

            void status(const RTI::RecordingService::TimerState& value) {
                m_status_ = value;
            }

            bool operator == (const DebugStatus& other_) const;
            bool operator != (const DebugStatus& other_) const;

            void swap(DebugStatus& other_) OMG_NOEXCEPT ;

          private:

            RTI::RecordingService::TimerState m_status_;

        };

        inline void swap(DebugStatus& a, DebugStatus& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const DebugStatus& sample);

        class NDDSUSERDllExport TimestampHolder {
          public:
            TimestampHolder();

            explicit TimestampHolder(
                ::rti::core::int64 timestamp_nanos);

            #ifdef RTI_CXX11_RVALUE_REFERENCES
            #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
            TimestampHolder (TimestampHolder&&) = default;
            TimestampHolder& operator=(TimestampHolder&&) = default;
            TimestampHolder& operator=(const TimestampHolder&) = default;
            TimestampHolder(const TimestampHolder&) = default;
            #else
            TimestampHolder(TimestampHolder&& other_) OMG_NOEXCEPT;  
            TimestampHolder& operator=(TimestampHolder&&  other_) OMG_NOEXCEPT;
            #endif
            #endif 

            ::rti::core::int64& timestamp_nanos() OMG_NOEXCEPT {
                return m_timestamp_nanos_;
            }

            const ::rti::core::int64& timestamp_nanos() const OMG_NOEXCEPT {
                return m_timestamp_nanos_;
            }

            void timestamp_nanos(::rti::core::int64 value) {
                m_timestamp_nanos_ = value;
            }

            bool operator == (const TimestampHolder& other_) const;
            bool operator != (const TimestampHolder& other_) const;

            void swap(TimestampHolder& other_) OMG_NOEXCEPT ;

          private:

            ::rti::core::int64 m_timestamp_nanos_;

        };

        inline void swap(TimestampHolder& a, TimestampHolder& b)  OMG_NOEXCEPT 
        {
            a.swap(b);
        }

        NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TimestampHolder& sample);

    } // namespace RecordingService  
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
        struct topic_type_name< RTI::RecordingService::DataTagParams > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::DataTagParams";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::DataTagParams > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::DataTagParams > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::DataTagParams& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::DataTagParams& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::DataTagParams& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::DataTagParams& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::BreakpointUnion > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::BreakpointUnion";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::BreakpointUnion > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::BreakpointUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::BreakpointUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::BreakpointParams > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::BreakpointParams";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::BreakpointParams > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::BreakpointParams > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::BreakpointParams& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::BreakpointParams& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::BreakpointParams& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::BreakpointParams& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::ContinueUnion > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::ContinueUnion";
            }
        };

        template<>
        struct topic_type_support< RTI::RecordingService::ContinueUnion > {
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::ContinueUnion& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::ContinueUnion& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::ContinueParams > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::ContinueParams";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::ContinueParams > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::ContinueParams > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::ContinueParams& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::ContinueParams& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::ContinueParams& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::ContinueParams& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::DebugStatus > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::DebugStatus";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::DebugStatus > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::DebugStatus > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::DebugStatus& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::DebugStatus& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::DebugStatus& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::DebugStatus& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::RecordingService::TimestampHolder > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::RecordingService::TimestampHolder";
            }
        };

        template<>
        struct is_topic_type< RTI::RecordingService::TimestampHolder > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::RecordingService::TimestampHolder > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::RecordingService::TimestampHolder& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::RecordingService::TimestampHolder& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::RecordingService::TimestampHolder& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::RecordingService::TimestampHolder& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::DataTagParams > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::DataTagParams > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::RecordingService::BreakpointFormat>
        {
            static const RTI::RecordingService::BreakpointFormat value;
        };
        template<>
        struct dynamic_type< RTI::RecordingService::BreakpointFormat > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::BreakpointFormat > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::BreakpointUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::BreakpointUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::BreakpointParams > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::BreakpointParams > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::RecordingService::ContinueFormat>
        {
            static const RTI::RecordingService::ContinueFormat value;
        };
        template<>
        struct dynamic_type< RTI::RecordingService::ContinueFormat > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::ContinueFormat > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::ContinueUnion > {
            typedef ::dds::core::xtypes::UnionType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::UnionType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::ContinueUnion > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::ContinueParams > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::ContinueParams > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::RecordingService::TimerState>
        {
            static const RTI::RecordingService::TimerState value;
        };
        template<>
        struct dynamic_type< RTI::RecordingService::TimerState > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::TimerState > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::DebugStatus > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::DebugStatus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::RecordingService::TimestampHolder > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::RecordingService::TimestampHolder > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // RecordingServiceTypes_164879633_hpp

