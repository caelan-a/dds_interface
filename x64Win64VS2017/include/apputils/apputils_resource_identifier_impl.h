/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_resource_identifier_impl_h
#define apputils_resource_identifier_impl_h

#ifndef apputils_resource_identifier_h
  #include "apputils/apputils_resource_identifier.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct APPUTILSRelativeResourceInfo {
    /* @birief Node for the hierarchy list*/
    struct REDAInlineListNode _node;

    /* @brief reference to the owner */
    struct APPUTILSResourceIdentifier *_owner;
    /*i @brief offset to the kind name */
    DDS_Long _kindOffset;
    /*i @brief offset to the entity name */
    DDS_Long _nameOffset;
};

struct APPUTILSResourceIdentifier {
    /* @brief Hierarchy of resources */
    struct REDAInlineList _relativeResourceList;

    /* @brief formatted identifier*/
    struct APPUTILSStringBuffer *_formatted;
    /* @brief scratch pad that contains the resource identifier */
    struct APPUTILSDynamicArray *_scratchpad;

    /* @brief hierarchy of relative resources */
    struct APPUTILSRelativeResourceInfo
        _relativeResources[APPUTILSResourceIdentifier_RELATIVE_RESOURCE_COUNT_MAX];

    /* @brief Fully qualified name of the resource */
    struct APPUTILSStringBuffer *fullyQualifiedName;

    /* @brief Fully qualified kind of the resource */
    struct APPUTILSStringBuffer *fullyQualifiedKind;

    /* @brief Custom method (optional) */
    const char *_customMethod;
};

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_resource_identifier_impl_h */
