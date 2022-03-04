/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_inlineTree.h    generated by: makeheader    Fri Apr 23 00:10:55 2021
 *
 *		built from:	inlineTree.ifc
 */

#ifndef reda_inlineTree_h
#define reda_inlineTree_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif

  #ifndef reda_inlineList_h
    #include "reda/reda_inlineList.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAInlineTree;


struct REDAInlineTree {
    struct REDAInlineListNode _node;
    
    /*i @brief back pointer to the parent tree. */
    struct REDAInlineTree * _parent;
    /*i @brief List of child nodes or sub-trees */
    struct REDAInlineList _children;
};

extern REDADllExport 
struct REDAInlineTree *
REDAInlineTree_getFirstChild(const struct REDAInlineTree * self);

extern REDADllExport 
struct REDAInlineTree *
REDAInlineTree_getNextSibling(const struct REDAInlineTree * self);

extern REDADllExport 
struct REDAInlineTree *
REDAInlineTree_getParent(const struct REDAInlineTree * self);

extern REDADllExport
RTIBool REDAInlineTree_isTop(struct REDAInlineTree * self);

extern REDADllExport
RTIBool REDAInlineTree_isLeaf(struct REDAInlineTree * self);

extern REDADllExport
void REDAInlineTree_addChildEA(
        struct REDAInlineTree * self,
        struct REDAInlineTree * node);

extern REDADllExport
void REDAInlineTree_removeChildEA(
        struct REDAInlineTree * self,
        struct REDAInlineTree * node);

extern REDADllExport
int REDAInlineTree_getChildCount(const struct REDAInlineTree * self);

extern REDADllExport
void REDAInlineTree_init(struct REDAInlineTree * self);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
 /* #include "reda/reda_inlineTree_impl.h" */

#endif /* reda_inlineTree_h */
