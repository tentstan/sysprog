/*
 * =====================================================================================
 *
 *       Filename:  dlist.h
 *
 *    Description:  dlist head file 
 *
 *        Version:  1.0
 *        Created:  03/05/2019 02:16:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "typedef.h"

#ifndef DLIST_H
#define DLIST_H 

DECLS_BEGIN

struct _DList;
typedef struct _DList DList;

DList* dlist_create(DataDestroyFunc data_destroy,void* ctx);

Ret dlist_insert(DList* thiz,size_t index,void* data);
Ret dlist_prepend(DList* thiz,void* data);
Ret dlist_append(DList* thiz,void* data);
Ret dlist_delete(DList* thiz,size_t index);
Ret dlist_get_by_index(DList* thiz,size_t index,void** data);
Ret dlist_set_by_index(DList* thiz,size_t index,void* data);
size_t dlist_length(DList* thiz);
int dlist_find(DList* thiz,DataCompareFunc cmp,void* ctx);
Ret dlist_foreach(DList* thiz,DataVisitFunc visit,void* ctx);

void dlist_destroy(DList* thiz);

DECLS_END

#endif /* DLIST_H */
