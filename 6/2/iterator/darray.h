/*
 * =====================================================================================
 *
 *       Filename:  darray.h
 *
 *    Description:  daray head file 
 *
 *        Version:  1.0
 *        Created:  03/05/2019 11:41:19 AM
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

#ifndef DARRAY_H
#define DARRAY_H 

DECLS_BEGIN

struct _DArray;
typedef struct _DArray DArray;

DArray* darray_create(DataDestroyFunc data_destroy,void* ctx);

Ret darray_insert(DArray* thiz,size_t index,void* data);
Ret darray_prepend(DArray* thiz,void* data);
Ret darray_append(DArray* thiz,void* data);
Ret darray_delete(DArray* thiz,size_t index);
Ret darray_get_by_index(DArray* thiz,size_t index,void** data);
Ret darray_set_by_index(DArray* thiz,size_t index,void* data);
size_t darray_length(DArray* thiz);
int darray_find(DArray* thiz,DataCompareFunc cmp,void* ctx);
Ret darray_foreach(DArray* thiz,DataVisitFunc visit,void* ctx);
Ret darray_sort(DArray* thiz,SortFunc sort,DataCompareFunc cmp);

void darray_destroy(DArray* thiz);

DECLS_END

#endif /* DARRAY_H */
