/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  dlist head file 
 *
 *        Version:  1.0
 *        Created:  02/19/2019 09:35:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "locker.h"

#ifndef DLIST_H
#define DLIST_H 

DECLS_BEGIN

struct _DList;
typedef struct _DList DList;

typedef void (*DListDataDestroyFunc)(void* ctx,void* data);
typedef int (*DListDataCompareFunc)(void* ctx,void* data);
typedef Ret (DListDataVisitFunc)(void* ctx,void* data);

DList* dlist_create(DListDataDestroyFunc data_destroy,void* ctx,Locker* locker);

Ret dlist_insert(DList* thiz,size_t index,void* data);
Ret dlist_prepend(DList* thiz,void* data);
Ret dlist_append(DList* thiz,void* data);
Ret dlist_delete(DList* thiz,size_t index);
Ret dlist_get_by_index(DList* thiz,size_t index,void** data);
Ret dlist_set_by_index(DList* thiz,size_t index,void* data);
size_t dlist_length(DList* thiz);
int dlist_find(DList* thiz,DListDataCompareFunc cmp,void* ctx);
Ret dlist_foreach(DList* thiz,DListDataVisitFunc visit,void* ctx);

void dlist_destroy(DList* thiz);

DECLS_END

#endif /* DLIST_H */
