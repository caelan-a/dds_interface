

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ServiceAdmin.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ServiceAdmin_1325755636_hpp
#define ServiceAdmin_1325755636_hpp

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

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif
#include "ServiceCommon.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif
namespace RTI {
    namespace Service {
        namespace Admin {

            static const std::string COMMAND_REQUEST_TOPIC_NAME = "rti/service/admin/command_request";

            static const std::string COMMAND_REPLY_TOPIC_NAME = "rti/service/admin/command_reply";

            static const int32_t NAME_LENGTH_MAX = (RTI::Service::BOUNDED_STRING_LENGTH_MAX);

            typedef std::string EntityName;
            struct EntityName_AliasTag_t {};

            static const int32_t RESOURCE_IDENTIFIER_LENGTH_MAX = (RTI::Service::RESOURCE_IDENTIFIER_LENGTH_MAX);

            typedef std::string ResourceIdentifier;
            struct ResourceIdentifier_AliasTag_t {};

            typedef std::string StringBody;
            struct StringBody_AliasTag_t {};

            #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
            // On Windows, dll-export template instantiations of standard types used by
            // other dll-exported types
            template class NDDSUSERDllExport std::allocator< uint8_t >;
            template class NDDSUSERDllExport std::vector< uint8_t >;
            #endif
            typedef std::vector< uint8_t > OctetBody;
            struct OctetBody_AliasTag_t {};
            struct CommandActionKind_def {
                enum type {
                    CREATE_ACTION, 
                    GET_ACTION, 
                    UPDATE_ACTION, 
                    DELETE_ACTION
                };
                static type get_default(){ return CREATE_ACTION;}
            };

            typedef ::dds::core::safe_enum< CommandActionKind_def > CommandActionKind;
            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const CommandActionKind& sample);
            struct CommandReplyRetcode_def {
                enum type {
                    OK_RETCODE, 
                    ERROR_RETCODE
                };
                static type get_default(){ return OK_RETCODE;}
            };

            typedef ::dds::core::safe_enum< CommandReplyRetcode_def > CommandReplyRetcode;
            NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const CommandReplyRetcode& sample);

            class NDDSUSERDllExport CommandRequest {
              public:
                CommandRequest();

                CommandRequest(
                    int32_t instance_id,
                    const ::dds::core::optional< std::string >& application_name,
                    const RTI::Service::Admin::CommandActionKind& action,
                    const std::string& resource_identifier,
                    const std::string& string_body,
                    const RTI::Service::Admin::OctetBody& octet_body);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                CommandRequest (CommandRequest&&) = default;
                CommandRequest& operator=(CommandRequest&&) = default;
                CommandRequest& operator=(const CommandRequest&) = default;
                CommandRequest(const CommandRequest&) = default;
                #else
                CommandRequest(CommandRequest&& other_) OMG_NOEXCEPT;  
                CommandRequest& operator=(CommandRequest&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                int32_t& instance_id() OMG_NOEXCEPT {
                    return m_instance_id_;
                }

                const int32_t& instance_id() const OMG_NOEXCEPT {
                    return m_instance_id_;
                }

                void instance_id(int32_t value) {
                    m_instance_id_ = value;
                }

                ::dds::core::optional< std::string >& application_name() OMG_NOEXCEPT {
                    return m_application_name_;
                }

                const ::dds::core::optional< std::string >& application_name() const OMG_NOEXCEPT {
                    return m_application_name_;
                }

                void application_name(const ::dds::core::optional< std::string >& value) {
                    m_application_name_ = value;
                }

                RTI::Service::Admin::CommandActionKind& action() OMG_NOEXCEPT {
                    return m_action_;
                }

                const RTI::Service::Admin::CommandActionKind& action() const OMG_NOEXCEPT {
                    return m_action_;
                }

                void action(const RTI::Service::Admin::CommandActionKind& value) {
                    m_action_ = value;
                }

                std::string& resource_identifier() OMG_NOEXCEPT {
                    return m_resource_identifier_;
                }

                const std::string& resource_identifier() const OMG_NOEXCEPT {
                    return m_resource_identifier_;
                }

                void resource_identifier(const std::string& value) {
                    m_resource_identifier_ = value;
                }

                std::string& string_body() OMG_NOEXCEPT {
                    return m_string_body_;
                }

                const std::string& string_body() const OMG_NOEXCEPT {
                    return m_string_body_;
                }

                void string_body(const std::string& value) {
                    m_string_body_ = value;
                }

                RTI::Service::Admin::OctetBody& octet_body() OMG_NOEXCEPT {
                    return m_octet_body_;
                }

                const RTI::Service::Admin::OctetBody& octet_body() const OMG_NOEXCEPT {
                    return m_octet_body_;
                }

                void octet_body(const RTI::Service::Admin::OctetBody& value) {
                    m_octet_body_ = value;
                }

                bool operator == (const CommandRequest& other_) const;
                bool operator != (const CommandRequest& other_) const;

                void swap(CommandRequest& other_) OMG_NOEXCEPT ;

              private:

                int32_t m_instance_id_;
                ::dds::core::optional< std::string > m_application_name_;
                RTI::Service::Admin::CommandActionKind m_action_;
                std::string m_resource_identifier_;
                std::string m_string_body_;
                RTI::Service::Admin::OctetBody m_octet_body_;

            };

            inline void swap(CommandRequest& a, CommandRequest& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CommandRequest& sample);

            class NDDSUSERDllExport CommandReply {
              public:
                CommandReply();

                CommandReply(
                    const RTI::Service::Admin::CommandReplyRetcode& retcode,
                    int32_t native_retcode,
                    const std::string& string_body,
                    const RTI::Service::Admin::OctetBody& octet_body);

                #ifdef RTI_CXX11_RVALUE_REFERENCES
                #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
                CommandReply (CommandReply&&) = default;
                CommandReply& operator=(CommandReply&&) = default;
                CommandReply& operator=(const CommandReply&) = default;
                CommandReply(const CommandReply&) = default;
                #else
                CommandReply(CommandReply&& other_) OMG_NOEXCEPT;  
                CommandReply& operator=(CommandReply&&  other_) OMG_NOEXCEPT;
                #endif
                #endif 

                RTI::Service::Admin::CommandReplyRetcode& retcode() OMG_NOEXCEPT {
                    return m_retcode_;
                }

                const RTI::Service::Admin::CommandReplyRetcode& retcode() const OMG_NOEXCEPT {
                    return m_retcode_;
                }

                void retcode(const RTI::Service::Admin::CommandReplyRetcode& value) {
                    m_retcode_ = value;
                }

                int32_t& native_retcode() OMG_NOEXCEPT {
                    return m_native_retcode_;
                }

                const int32_t& native_retcode() const OMG_NOEXCEPT {
                    return m_native_retcode_;
                }

                void native_retcode(int32_t value) {
                    m_native_retcode_ = value;
                }

                std::string& string_body() OMG_NOEXCEPT {
                    return m_string_body_;
                }

                const std::string& string_body() const OMG_NOEXCEPT {
                    return m_string_body_;
                }

                void string_body(const std::string& value) {
                    m_string_body_ = value;
                }

                RTI::Service::Admin::OctetBody& octet_body() OMG_NOEXCEPT {
                    return m_octet_body_;
                }

                const RTI::Service::Admin::OctetBody& octet_body() const OMG_NOEXCEPT {
                    return m_octet_body_;
                }

                void octet_body(const RTI::Service::Admin::OctetBody& value) {
                    m_octet_body_ = value;
                }

                bool operator == (const CommandReply& other_) const;
                bool operator != (const CommandReply& other_) const;

                void swap(CommandReply& other_) OMG_NOEXCEPT ;

              private:

                RTI::Service::Admin::CommandReplyRetcode m_retcode_;
                int32_t m_native_retcode_;
                std::string m_string_body_;
                RTI::Service::Admin::OctetBody m_octet_body_;

            };

            inline void swap(CommandReply& a, CommandReply& b)  OMG_NOEXCEPT 
            {
                a.swap(b);
            }

            NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const CommandReply& sample);

        } // namespace Admin  
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
        struct topic_type_name< RTI::Service::Admin::CommandRequest > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Admin::CommandRequest";
            }
        };

        template<>
        struct is_topic_type< RTI::Service::Admin::CommandRequest > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::Service::Admin::CommandRequest > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::Service::Admin::CommandRequest& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::Service::Admin::CommandRequest& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Admin::CommandRequest& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Admin::CommandRequest& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< RTI::Service::Admin::CommandReply > {
            NDDSUSERDllExport static std::string value() {
                return "RTI::Service::Admin::CommandReply";
            }
        };

        template<>
        struct is_topic_type< RTI::Service::Admin::CommandReply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< RTI::Service::Admin::CommandReply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const RTI::Service::Admin::CommandReply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(RTI::Service::Admin::CommandReply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(RTI::Service::Admin::CommandReply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(RTI::Service::Admin::CommandReply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::EntityName_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::ResourceIdentifier_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::StringBody_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::OctetBody_AliasTag_t > {
            typedef ::dds::core::xtypes::AliasType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::AliasType& get();
        };
        #endif

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::Admin::CommandActionKind>
        {
            static const RTI::Service::Admin::CommandActionKind value;
        };
        template<>
        struct dynamic_type< RTI::Service::Admin::CommandActionKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Admin::CommandActionKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<RTI::Service::Admin::CommandReplyRetcode>
        {
            static const RTI::Service::Admin::CommandReplyRetcode value;
        };
        template<>
        struct dynamic_type< RTI::Service::Admin::CommandReplyRetcode > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Admin::CommandReplyRetcode > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::CommandRequest > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Admin::CommandRequest > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< RTI::Service::Admin::CommandReply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< RTI::Service::Admin::CommandReply > {
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

#endif // ServiceAdmin_1325755636_hpp

