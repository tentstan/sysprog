/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  autotest dlist header file 
 *
 *        Version:  1.0
 *        Created:  01/18/2019 04:50:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#ifndef DLIST_H
#define DLIST_H 

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum _DListRet
{
    DLIST_RET_OK,
    DLIST_RET_OOM,
    DLIST_RET_STOP,
    DLIST_RET_INVALID_PARAMS,
    DLIST_RET_FAIL
}DListRet;

struct _DList;
typedef struct _DList DList;

typedef void (*DListDataDestroyFunc)(void* ctx,void* data);
typedef int (*DListDataCompareFunc)(void* ctx,void* data);
typedef DListRet (*DListDataVisitFunc)(void* ctx,void* data);

DList* dlist_create(DListDataDestroyFunc data_destroy,void* data_destroy_ctx);

DListRet dlist_insert(DList* thiz,size_t index,void* data);
DListRet dlist_prepend(DList* thiz,void* data);
DListRet dlist_append(DList* thiz,void* data);
DListRet dlist_delete(DList* thiz,size_t index);
DListRet dlist_get_by_index(DList* thiz,size_t index,void** data);
DListRet dlsit_set_by_index(DList* thiz,size_t index,void* data);
size_t dlist_length(DList* thiz);
int dlist_find(DList* thiz,DListDataCompareFunc cmp,void* ctx);
DListRet dlist_foreach(DList* thiz,DListDataVisitFunc visit,void* ctx);

void dlist_destroy(DList* thiz);

#define return_if_fail(p) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed.\n", \
            __func__,__LINE__);return;}

#define return_val_if_fail(p,ret) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed. \n", \
            __func__,__LINE__);return (ret);}

#ifdef __cplusplus 
}
#endif /* __cplusplus */

#endif /* DLIST */

