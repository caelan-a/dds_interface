/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_RECORDING_SERVICE_HPP_
#define RTI_RECORDING_SERVICE_HPP_

#include <dds/core/Reference.hpp>
#include <rti/config/Logger.hpp>

#include <rti/recording/Logger.hpp>
#include <rti/recording/ServiceProperty.hpp>
#include <rti/recording/detail/RecordingServiceImpl.hpp>

namespace rti { namespace recording {

/*e \defgroup RTI_RecordingServiceLibModule RTI Recording Service API
 *
 * @brief @product  can be deployed as a native library linked into your
 * application in select architectures.
 *
 * This API allows you to create, configure and start @product instances from
 * your application.
 *
 * The following code shows the typical use of the API:
 *
 * \code
 *
 * int main ()
 * {
 *     rti::recording::Service service(
 *             rti::recording::ServiceProperty()
 *             .cfg_file("MyRecorder.xml")
 *             .cfg_name("MyRecorder"));
 *     ...
 *
 *     service.start();
 *
 *     while(keep_running) {
 *         sleep();
 *         ...
 *     }
 *
 *     return 0;
 * }
 *
 * \endcode
 *
 * Instead of a file, you can use XML strings to configure @product.
 * See ServiceProperty for more information.
 * <p>
 * To build your application you need to link with the @product native library
 * in <b> &lt;@ndds home&gt;/bin/&lt;architecture&gt;/ </b>.
 *
 * ### Development Requirements
 *
 * |                 | Linux Systems                      | Windows Systems           |
 * | --------------: | :----------------:                      | :-------------:           |
 * | Shared Libraries| libnddscpp2.so                          | nddscpp2.dll              |
 * | Shared Libraries| librtiroutingservice.so                 | rtiroutingservice.dll     |
 * | ^               | librtirsinfrastructure.so               | rtirsinfrastructure.dll   |
 * | ^               | librtirecordingservice.so               | rtirecordingservice.dll   |
 * | ^               | librtidlc.so                            | rtidlc.dll                |
 * | ^               | libnddsmetp.so                          | nddsmetp.dll              |
 * | ^               | libnddsc.so                             | nddsc.dll                 |
 * | ^               | librtixml2.so                           | rtixml2.dll               |
 * | ^               | libnddscore.so                          | nddscore.dll              |
 * | Headers         | rti/recording/RecordingService.hpp      ||
 *
 */

/** \ingroup RTI_RecordingServiceLibModule
 *
 * @brief The @product.
 *
 */
class Service : public dds::core::Reference<RecordingServiceImpl> {
public:
    typedef RTI::Service::Admin::CommandRequest CommandRequest;
    typedef RTI::Service::Admin::CommandReply CommandReply;

    typedef dds::core::Reference<RecordingServiceImpl> Base;
    OMG_DDS_REF_TYPE_NOTYPENAME(
            Service,
            dds::core::Reference,
            RecordingServiceImpl);

    /**
     * @brief Creates a @product instance
     *
     * @param[in] property
     *            The property to configure @product instance.
     *
     */
    explicit Service(const ServiceProperty& property)
            : Base(new RecordingServiceImpl(property))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * @brief Creates a @product instance
     *
     * A callable shutdown hook can optionally be provided to handle the
     * shutdown command received through remote administration or upon execution
     * termination in the case of the REPLAY role. Upon reception
     * of this command, @product will notify the installed hook.
     *
     * The following example shows simple implementation of a shutdown hook
     * that sets a boolean flag to true when invoked:
     *
     * \code
     *
     * // Hook implmentation
     * struct FlagShutdownHook {
     * public:
     *     FlagShutdownHook(bool& the_flag) : flag(the_flag)
     *     {
     *         flag = false;
     *     }
     *     void operator()() {
     *         the_flag = true;
     *     }
     *
     *     bool& flag;
     * };
     *
     * // Instantiate service with hook
     * bool my_flag;
     * rti::recording::Service recording_service(
     *       property,
     *       FlagShutdownHook(my_flag));
     * ...
     *
     *
     * \endcode
     *
     * @param[in] property
     *            The property to configure @product instance.
     *
     * @param[in] shutdown_hook
     *            Callable object to handle the shutdown command. The expected
     *            type is a void operator()() (C++11 equivalent is
     *            std::function<void()>)
     *
     */
    template <typename HookFunc>
    explicit Service(
            const ServiceProperty& property,
            const HookFunc& shutdown_hook)
            : Base(new RecordingServiceImpl(
                property,
                new rti::routing::detail::ShutdownHookForwarder<HookFunc>(shutdown_hook)))
    {
        this->delegate()->remember_reference(this->delegate());
    }


    explicit Service(Base::DELEGATE_REF_T reference) : Base(reference)
    {
        if (this->delegate()) {
            this->delegate()->remember_reference(this->delegate());
        }
    }

    /**
     * @brief Starts @product.
     *
     * This is a non-blocking operation. @product will create its own set of
     * threads to perform its tasks.
     */
    void start()
    {
        this->delegate()->start();
    }

    /**
     * @brief Stops @product.
     *
     * This operation will bloc the instance is fully stopped.
     */
    void stop()
    {
        this->delegate()->stop();
    }



    /**
     * @brief Executes an Administration command on this service.
     *
     * This operation directly executes the specified \p request in this
     * service as if it was directly received from an administration requester.
     *
     * The request can represent any of the available administration operations
     * as documented in the Administration chapter in the user's manual. This
     * operation gives you an alternative way to control the service using
     * the same remote administration interface but allowing you to call
     * the operation directly.
     *
     * This operation can also throw an exception if an internal error
     * occurs.
     *
     * Example:
     *
     * \code
     *
     *  using namespace rti::recording;
     *  using namespace RTI::Service;
     *  using namespace RTI::Service::Admin;
     *
     *  // Instantiate a RecordingService
     *  RecordingService service(...);
     *
     *  // Prepare a request for any command, for example stop the service
     *  CommandRequest request;
     *  request.action(CommandActionKind::UPDATE_ACTION);
     *  request.resource_identifier("/recording_services/MyRecorder");
     *  dds::topic::topic_type_support<EntityState>::to_cdr_buffer(
     *          reinterpret_cast<std::vector<char> &>(request.octet_body()),
     *          EntityState(EntityStateKind::DISABLED));
     * // Execute and check result
     * CommandReply reply = service.execute_command(request);
     * if (reply.retcode().underlying() != CommandReplyRetcode::OK_RETCODE) {
     *     Logger.instance().error(
     *             std::string("Command returned: ") + reply.string_body());
     *     //handle
     *     ...
     * }
     *
     * \endcode
     *
     * @param[in] request Representation of the command to be executed
     * @return The reply with the result of the command execution.
     *
     */
    CommandReply execute_command(const CommandRequest& request)
    {
        return this->delegate()->execute_command(request);
    }

    /**
     * @brief Executes an Administration command on this service.
     *
     * Similar to execute_command(const CommandRequest& request) except
     * the caller provides the CommandReply object.
     *
     * @param[out] reply Reppresentation of the reply containing the result of
     *             the operation
     * @param[in] request Representation of the command to be executed
     *
     * @return A reference to the same reply object provided as a parameter
     */
    CommandReply& execute_command(
            CommandReply& reply,
            const CommandRequest& request)
    {
        return this->delegate()->execute_command(reply, request);
    }


    /**
     * @brief Finalizes global resources that @product requires to operate.
     *
     * This operation releases resources specific to @product only. @ndds
     * global state shall be released separately through the
     * DomainParticipantFactory's finalize_instance().
     *
     * This operation should be called by your application only upon exit, after
     * all service instances have been deleted. Calling it at a different time may
     * cause the application to crash.
     *
     * @mtsafety unsafe. Applications are not allowed to call this operation
     * concurrently
     *
     * @throw std::exception
     */
    static void finalize_globals()
    {
        RecordingServiceImpl::finalize_globals();
    }
};


typedef Service RecordingService;

}}

#endif // RTI_RECORDING_SERVICE_HPP_
