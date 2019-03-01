/*
 * =====================================================================================
 *
 *       Filename:  hash_table.h
 *
 *    Description:  hash_table head file 
 *
 *        Version:  1.0
 *        Created:  02/28/2019 04:06:15 PM
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

#ifndef HASH_TABLE_H
#define HASH_TABLE_H 

DECLS_BEGIN

struct _HashTable;
typedef struct _HashTable HashTable;

HashTable* hash_table_create(DataDestroyFunc data_destroy,void* ctx,DataHashFunc hash,int slot_nr);

size_t hash_table_length(HashTable* thiz);
Ret hash_table_insert(HashTable* thiz,void* data);
Ret hash_table_delete(HashTable* thiz,DataCompareFunc cmp,void* data);
Ret hash_table_find(HashTable* thiz,DataCompareFunc cmp,void* data,void** ret_data);
Ret hash_table_foreach(HashTable* thiz,DataVisitFunc visit,void* ctx);

void hash_table_destroy(HashTable* thiz);

DECLS_END

#endif /* HASH_TABLE_H */
