/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_psGroup.h    generated by: makeheader    Fri Nov 15 12:22:41 2019
 *
 *		built from:	psGroup.ifc
 */

#ifndef pres_psGroup_h
#define pres_psGroup_h


 #ifndef pres_dll_h
    #include "pres/pres_dll.h"
 #endif
 #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
 #endif
 #ifndef pres_common_h
    #include "pres/pres_common.h"
 #endif
 #ifndef pres_participant_h
    #include "pres/pres_participant.h"
 #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAWorker;

struct PRESPsWriterGroup;

struct PRESPsWriterGroupProperty;

struct PRESPsWriterGroupListener;

struct PRESPsReaderGroup;

struct PRESPsReaderGroupProperty;

struct PRESPsReaderGroupListener;

struct PRESPsReader;

extern PRESDllExport
RTIBool PRESGroup_objectKindMatch(
    struct PRESGroup *me, MIGRtpsObjectSuffix objKind);

extern PRESDllExport
PRESGroupSuffix PRESGroup_getGroupSuffixFromOid(MIGRtpsObjectId objectId);

extern PRESDllExport
struct PRESPsWriter* PRESPsWriterGroup_lookupWriter(
    struct PRESPsWriterGroup *me, const char *topicName,
    struct REDAWorker *worker);

extern PRESDllExport
struct PRESPsWriter* PRESPsWriterGroup_lookupWriterByGuid(
    struct PRESPsWriterGroup *me, const struct MIGRtpsGuid *guid,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_setProperty(
    struct PRESPsWriterGroup *me, int *failReason,
    const struct PRESPsWriterGroupProperty *property,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_getProperty(
    struct PRESPsWriterGroup *me, struct PRESPsWriterGroupProperty *property,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_setListener(
    struct PRESPsWriterGroup *me, int *failReason,
    const struct PRESPsWriterGroupListener *listener,
    PRESStatusKindMask mask,
    struct REDAWorker *worker);

extern PRESDllExport
struct PRESPsWriterGroupListener* PRESPsWriterGroup_getListener(
    struct PRESPsWriterGroup *me, struct REDAWorker *worker);

extern PRESDllExport 
PRESWord *PRESPsWriterGroup_getUserObject(struct PRESPsWriterGroup *me);


#define PRESPsWriterIterator REDACursor

extern PRESDllExport
RTIBool PRESPsWriterGroup_beginGetPsWriters(
                                  struct PRESPsWriterGroup *writerGroup,
                                  struct PRESPsWriterIterator ** iter,
                                  RTI_INT32 *maxPsWriters,
                                  struct REDAWorker *worker); 

extern PRESDllExport                                   
RTIBool PRESPsWriterGroup_endGetPsWriters(struct PRESPsWriterGroup *writerGroup,
                                  struct PRESPsWriterIterator * iter,
                                  struct REDAWorker *worker); 

extern PRESDllExport                                 
struct PRESPsWriter * PRESPsWriterGroup_getNextPsWriter(
                                  struct PRESPsWriterGroup *writerGroup,
                                  int* failReason,
                                  struct PRESPsWriterIterator * iter,
                                  struct REDAWorker *worker); 

extern PRESDllExport 
RTIBool PRESPsWriterGroup_enable(struct PRESPsWriterGroup *me,int *failReason,
				 struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESPsWriterGroup_isEnabled(struct PRESPsWriterGroup *me);

extern PRESDllExport void
PRESPsWriterGroup_getInstanceHandle(
    struct PRESPsWriterGroup *me,
    struct PRESInstanceHandle *handle);

extern PRESDllExport 
RTIBool PRESPsWriterGroup_destroyContainedLocalEndpoints(
    struct PRESPsWriterGroup *me,int *failReason, struct REDAWorker *worker);

extern PRESDllExport
int PRESPsWriterGroup_waitForAcknowledgments(struct PRESPsWriterGroup *me,
                                             struct RTINtpTime* timeout, 
                                             struct REDAWorker* worker);

extern PRESDllExport
int PRESPsWriterGroup_waitForAsynchPub(struct PRESPsWriterGroup *me,
                                             struct RTINtpTime* timeout, 
                                             struct REDAWorker* worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_beginCoherentChanges(
    struct PRESPsWriterGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_endCoherentChanges(
    struct PRESPsWriterGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_suspendPublications(
    struct PRESPsWriterGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsWriterGroup_resumePublications(
    struct PRESPsWriterGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport
struct PRESPsReader* PRESPsReaderGroup_lookupReader(
    struct PRESPsReaderGroup *me, const char *topicName,
    struct REDAWorker *worker);

extern PRESDllExport
struct PRESPsReader* PRESPsReaderGroup_lookupReaderByGuid(
    struct PRESPsReaderGroup *me, const struct MIGRtpsGuid *guid,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsReaderGroup_setProperty(
    struct PRESPsReaderGroup *me, int *failReason, 
    const struct PRESPsReaderGroupProperty *property, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsReaderGroup_getProperty(
    struct PRESPsReaderGroup *me, struct PRESPsReaderGroupProperty *property,
    struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsReaderGroup_setListener(
    struct PRESPsReaderGroup *me, int *failReason,
    const struct PRESPsReaderGroupListener *listener,
    PRESStatusKindMask mask,
    struct REDAWorker *worker);

extern PRESDllExport
struct PRESPsReaderGroupListener* PRESPsReaderGroup_getListener(
    struct PRESPsReaderGroup *me, struct REDAWorker *worker);

extern PRESDllExport 
PRESWord *PRESPsReaderGroup_getUserObject(struct PRESPsReaderGroup *me);

extern PRESDllExport 
RTIBool PRESPsReaderGroup_getSampleLostStatus(
    struct PRESPsReaderGroup *readerGroup, struct PRESSampleLostStatus *status,
    struct REDAWorker *worker);


#define PRESPsReaderIterator REDACursor

extern PRESDllExport
RTIBool PRESPsReaderGroup_beginGetPsReaders(
                                  struct PRESPsReaderGroup *readerGroup,
                                  void ** iter,
                                  RTI_INT32 *maxPsReaders,
                                  struct REDAWorker *worker); 

extern PRESDllExport                                   
RTIBool PRESPsReaderGroup_endGetPsReaders(struct PRESPsReaderGroup *readerGroup,
                                  void * iter,
                                  struct REDAWorker *worker); 

extern PRESDllExport                                 
struct PRESPsReader * PRESPsReaderGroup_getNextPsReader(
                                  struct PRESPsReaderGroup *readerGroup,
                                  int* failReason,
                                  void * iter,
                                  RTIBool useMasks,
                                  PRESSampleStateMask sMask,
                                  PRESViewStateMask vMask,
                                  PRESInstanceStateMask iMask,
                                  struct REDAWorker *worker); 

extern PRESDllExport 
RTIBool PRESPsReaderGroup_notifyPsReaders(struct PRESPsReaderGroup *readerGroup,
					  struct REDAWorker *worker);

extern PRESDllExport 
PRESStatusKindMask PRESPsReaderGroup_getStatusChange(
    struct PRESPsReaderGroup *readerGroup, struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESPsReaderGroup_enable(struct PRESPsReaderGroup *me,int *failReason,
				 struct REDAWorker *worker);

extern PRESDllExport 
RTIBool PRESPsReaderGroup_isEnabled(struct PRESPsReaderGroup *me);

extern PRESDllExport void
PRESPsReaderGroup_getInstanceHandle(
    struct PRESPsReaderGroup *me,
    struct PRESInstanceHandle *handle);

extern PRESDllExport 
RTIBool PRESPsReaderGroup_destroyContainedLocalEndpoints(
    struct PRESPsReaderGroup *me,int *failReason, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsReaderGroup_beginAccess(
    struct PRESPsReaderGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport
RTIBool PRESPsReaderGroup_endAccess(
    struct PRESPsReaderGroup *me, int *failReason, struct REDAWorker *worker);

extern PRESDllExport RTIBool
PRESPsReaderGroup_callListener(
    struct PRESPsReaderGroup *readerGroup, int *failReason, 
    PRESStatusKindMask mask, struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "pres/pres_psGroup_impl.h"

#endif /* pres_psGroup_h */
