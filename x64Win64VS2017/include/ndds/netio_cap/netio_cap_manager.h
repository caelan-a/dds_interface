/* $Id$

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/
#ifndef netio_cap_include_manager_h
#define netio_cap_include_manager_h

/**
 *  Functions and variables defined in the include folder as extern become
 *  'Public', that is, shared between modules
 */

#include "netio_cap/netio_cap_dll.h"
#include "netio_cap/netio_cap_infrastructure.h"

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * ****************************************************************************
 *                              MASKS
 * ****************************************************************************
 */
/* Traffic to capture (none/outbound/inbound/all) */
#define RTI_NETIO_CAP_TRAFFIC_BIT_OUT    (0x0001 << 0)
#define RTI_NETIO_CAP_TRAFFIC_BIT_IN     (0x0001 << 1)

#define RTI_NETIO_CAP_TRAFFIC_MASK_NONE  (0x0000)
#define RTI_NETIO_CAP_TRAFFIC_MASK_ALL \
        (RTI_NETIO_CAP_TRAFFIC_BIT_OUT | RTI_NETIO_CAP_TRAFFIC_BIT_IN)

#define RTI_NETIO_CAP_TRAFFIC_MASK_DEFAULT RTI_NETIO_CAP_TRAFFIC_MASK_ALL

/**
 *  These masks indicate a type of content from the RTPS frames.
 *
 *  They are used to specify what to remove from the capture (in order to
 *  reduce its size).
 */
#define RTI_NETIO_CAP_CONTENT_BIT_USER_SERIALIZED_DATA (0x0001 << 0)
#define RTI_NETIO_CAP_CONTENT_BIT_ENCRYPTED_DATA (0x0001 << 1)

#define RTI_NETIO_CAP_CONTENT_MASK_NONE (0x0000)
#define RTI_NETIO_CAP_CONTENT_MASK_ALL \
        (RTI_NETIO_CAP_CONTENT_BIT_USER_SERIALIZED_DATA \
                | RTI_NETIO_CAP_CONTENT_BIT_ENCRYPTED_DATA)
#define RTI_NETIO_CAP_CONTENT_MASK_DEFAULT RTI_NETIO_CAP_CONTENT_MASK_NONE

/**
 * ****************************************************************************
 *                              CONSTANTS
 * ****************************************************************************
 */
#define RTI_NETIO_CAP_TRANSPORTS_MAX_SIZE (128)
#define RTI_NETIO_CAP_FILEPATH_MAX_SIZE (512)

/**
 * ****************************************************************************
 *                             DATA TYPES
 * ****************************************************************************
 */
typedef RTINetioCapLong RTINetioCapTrafficKindMask;
typedef RTINetioCapLong RTINetioCapContentKindMask;

struct RTINetioCapManager;

#define RTINetioCapParams_INITIALIZER { \
    {'\0'}, /* transports */ \
    RTI_NETIO_CAP_CONTENT_MASK_DEFAULT, \
    RTI_NETIO_CAP_TRAFFIC_MASK_DEFAULT, \
    RTI_FALSE, /* parseEncryptedContent */ \
    RTI_NETIO_CAP_THREAD_SETTINGS_DEFAULT, \
    2097152, /* frameQueueSize (2 MB) */ \
}

struct RTINetioCapParams {
    /* List of transports to capture (comma-separated alias list). */
    RTINetioCapChar transports[RTI_NETIO_CAP_TRANSPORTS_MAX_SIZE];
    /* Mask that determines what contents to remove from each packet. */
    RTINetioCapContentKindMask droppedContentMask;
    /* Mask to control whether to capture inbout traffic, outbound or both. */
    RTINetioCapTrafficKindMask trafficMask;
    /* Whether to decrypt secured data or not. */
    RTIBool parseEncryptedContent;
    /* Properties for the checkpoint thread. */
    struct RTINetioCapThreadSettings checkpointThreadSettings;
    /* Size of the queue for frames, with overhead */
    RTINetioCapLong frameQueueSize;
};

typedef enum RTINetioCapManagerStatus {
    RTI_NETIO_CAP_MANAGER_STATUS_INVALID,
    RTI_NETIO_CAP_MANAGER_STATUS_STOPPED,
    RTI_NETIO_CAP_MANAGER_STATUS_PAUSED,
    RTI_NETIO_CAP_MANAGER_STATUS_STARTED,
    RTI_NETIO_CAP_MANAGER_STATUS_WRITING,
} RTINetioCapManagerStatus;

/**
 *  The function that translates the alias string into a transport class id
 *  list is given as a pointer when creating the manager (and will be called
 *  when enabling it).
 *  The reason behind using the transport plugin (instead of just creating and
 *  calling a function from within the module) is that this function responsible
 *  of translating the string to a RTINetioCapTransportClassIdList may need
 *  information not available at the netio_cap.1.0 module (e.g., the
 *  RTINetioConfigurator).
 */
typedef RTIBool (*RTINetioCapTransportAliasToClassIdFunction) (
        struct RTINetioCapTransportClassIdList *transportClassIdList,
        void *userData,
        const RTINetioCapChar *alias);

#define RTINetioCapTransportPlugin_INITIALIZER {NULL, NULL}
struct RTINetioCapTransportPlugin {
    void *userData;
    RTINetioCapTransportAliasToClassIdFunction transportAliasToClassIdFnc;
};

/**
 * ****************************************************************************
 *                             ENABLING/DISABLING
 * ****************************************************************************
 */

/**
 *  @brief Enable Network Capture.
 *
 *  Important!: This is not thread safe.
 *  It should only be called once, at the beginning of the user application.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCap_enableNetworkCapture(void);

/**
 *  @brief Disable Network Capture.
 *
 *  Important!: This is not thread safe.
 *  It should only be called once, at the end of the user application.
 *
 *  We must make sure that no Network Capture method is called after disabling
 *  it.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCap_disableNetworkCapture(void);

/**
 *  @brief Indicate if Network Capture is enabled.
 *
 *  This function is thread safe.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCap_isNetworkCaptureEnabled(void);

/**
 * ****************************************************************************
 *                             MANAGER API
 * ****************************************************************************
 */
/**
 *  @brief Set the default parameters for Network Capture.
 *
 *  @param params \b in. Default parameters that we want to set.
 *
 *  Important: This function requires a mutex that protects the globals.
 *  See RTINetioCap_enableNetworkCapture.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_setDefaultParams(
        const struct RTINetioCapParams *params);

/**
 *  @brief Get the default parameters for Network Capture.
 *
 *  @param params \b out. Default parameters.
 *
 *  Important: This function requires a mutex that protects the globals.
 *  See RTINetioCap_enableNetworkCapture.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_getDefaultParams(struct RTINetioCapParams *params);

/**
 *  @brief Create a new Network Capture Manager and allocate resources needed
 *  for it.
 *
 *  To start capturing with Network Capture the first step is to
 *  call RTINetioCapManager_new and then RTINetioCapManager_start.
 *
 *  @param threadParticipantId \b in. Thread participant indentification. Used
 *  to build the names of the threads created by the RTINetioCapManager.
 *
 *  @param participantGuidPrefix \b in. GUID of the participant associated to
 *  the manager. The participant GUID will be written for every frame captured
 *  by the manager.
 *
 *  @param transportPlugin \b in. Structure containing a pointer to the function
 *  that will get the transport class id list from a string of comma-separted
 *  aliases. It also has a "userData" member with additional information that
 *  the function may require. If the value of the transportPlugin passes is
 *  NULL, all transports will be captured.
 *
 *  @return Created network manager.
 *
 *  @section Notes:
 *
 *  - This function is automatically called when the participant is created
 *    (even if Network Capture is not enabled).
 */
extern RTINetioCapDllExport
struct RTINetioCapManager * RTINetioCapManager_new(
        const char *threadParticipantId,
        const struct RTINetioCapGuidPrefix *participantGuidPrefix,
        const struct RTINetioCapTransportPlugin *transportPlugin);

/**
 *  @brief Delete a Network Capture manager and all memory allocated by it.
 *
 *  When started, Network Capture has some memory allocated (pool of buffers,
 *  semaphores, etc). This memory is allocated with the function
 *  RTINetioCapManager_start and deallocated with
 *  RTINetioCapManager_stop.
 *
 *  That is why RTINetioCapManager_delete first stops network Capture.
 *  It then frees the participant RTINetioCapManager structure that was
 *  allocated with RTINetioCapManager_new.
 *
 *  @param me \b in/out. Network manager that we want to delete.
 *
 *  @section Notes.
 *
 *  - Important!: Do not forget to set the pointer to the manager equal to NULL
 *   from the function calling RTINetioCapManager_delete.
 *
 *  - This function is automatically called when the participant is deleted.
 */
extern RTINetioCapDllExport
void RTINetioCapManager_delete(struct RTINetioCapManager *me);

/**
 *  @brief Starts Network Capture for the specified manager.
 *
 *  @param me \b in/out. Network manager that we want to enable.
 *
 *  @param filename \b in. Name for the capture file (without extension).
 *
 *  @param params \b in. Input configuration parameters that control the
 *  behaviour of Network Capture.
 *
 *  @return RTI_TRUE if successful.
 *  If the manager is already started (or writing frames or paused), then
 *  RTI_TRUE is returned. RTI_FALSE is returned if the manager was stopped and
 *  the attempt to start it failed.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_start(
        struct RTINetioCapManager *me,
        const char *filename,
        const struct RTINetioCapParams *params);

/**
 *  @brief Stop Network Capture for the specified manager.
 *
 *  All resources are freed except the RTINetioCapManager structure
 *  associated to the participant (and created with RTINetioCapManager_new).
 *
 *  The RTINetioCapManager structure is not deleted so that we can start
 *  Network Capture again if desired.
 *
 *  To also delete the RTINetioCapManager structure associated to the
 *  participant, call RTINetioCapManager_delete instead.
 *
 *  @param me \b in/out. Network Manager that we want to disable.
 */
extern RTINetioCapDllExport
void RTINetioCapManager_stop(struct RTINetioCapManager *me);

/**
 *  @brief Resume capturing traffic.
 *
 *  @param me \b in/out. Network manager for which we wan to resume capturing
 *  traffic.
 *
 *  @return RTI_TRUE if successful.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_resume(struct RTINetioCapManager *me);

/**
 *  @brief Pause capturing traffic.
 *
 *  @param me \b in/out. Network Manager for which we want to pause capturing.
 *
 *  @return RTI_TRUE if successful.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_pause(struct RTINetioCapManager *me);

/**
 *  @brief Get the current status of the network manager.
 *
 *  @param me \b in. Manager to get the status from.
 *
 *  @return Status.
 */
extern RTINetioCapDllExport
RTINetioCapManagerStatus RTINetioCapManager_getStatus(
        struct RTINetioCapManager *me);

/**
 *  @brief Get the parameters of the Network Capture Manager.
 *
 *  This can be useful for deciding whether to enqueue or not RTPS frames
 *  (RTINetioCapManager_enqueueRtpsFrame) depending on the manager's
 *  configuration. For example, we can compare the traffic direction of the RTPS
 *  frame (inbound/outbound) and capture it or not depending on whether the
 *  manager should capture that direction.
 *
 *  @param me \b in/out. Network manager for which we want to get the
 *  parameters.
 *
 *  @return Pointer to a structure containing the parameters of the manager
 *  (NULL if input manager was NULL).
 */
extern RTINetioCapDllExport
const struct RTINetioCapParams * RTINetioCapManager_getParams(
        struct RTINetioCapManager *me);

/**
 *  @brief Queue an RTPS frame.
 *
 *  @param me \b in/out. Network manager in which we will enqueue an RTPS frame.
 *
 *  @param rtpsBuffer \b in. RTPS message to be enqueued as received from the
 *  network.
 *
 *  @param rtpsDecodedBuffer \b in. Decrypted RTPS message to be enqueued.
 *  If security is off, this is NULL (to avoid duplication of information).
 *  Otherwise it corresponds to the decryption of the rtpsBuffer parameter at
 *  message level. That is, it may contain encrypted submessages and/or
 *  serialized payload.
 *
 *  @param rtpsDecodedSubmessagesBuffer \b in. Decrypted RTPS submessages.
 *  If security is off, this is NULL (to avoid duplication of information).
 *  Otherwise, it contains the original, unencrypted RTPS message.
 *  In the case of outbound traffic this information comes as an unique message
 *  and in the case of inbound traffic this comes as a series of submessages.
 *
 *  Note that decryption of serialized data payload is (at least not yet)
 *  supported. As a consequence, if data payload is secured, the resulting RTPS
 *  frame in the network capture will still contain the protected payload.
 *
 *  @param timestamp \b in. Timestamp for the pcap packet header.
 *
 *  @param transport \b in. Tranport context information to include in the
 *  capture.
 *
 *  @param trafficMask \b in. Whether the traffic is inbound or outbound.
 *
 *  @return RTI_TRUE if successful.
 */
extern RTINetioCapDllExport
RTIBool RTINetioCapManager_enqueueRtpsFrame(
        struct RTINetioCapManager *me,
        const struct RTINetioCapTransportGatherBuffer *rtpsBuffer,
        const struct RTINetioCapTransportGatherBuffer *rtpsDecodedBuffer,
        const struct RTINetioCapTransportGatherBuffer
                *rtpsDecodedSubmessagesBuffer,
        const struct RTINetioCapNtpTime *timestamp,
        const struct RTINetioCapTransportContext *transport,
        RTINetioCapTrafficKindMask trafficMask);

#ifdef __cplusplus
}    /* extern "C" */
#endif

#endif /* netio_cap_include_manager_h */
/* end of $Id$ */
