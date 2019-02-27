/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  queue head file 
 *
 *        Version:  1.0
 *        Created:  02/27/2019 11:18:00 AM
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

#ifndef QUEUE_H
#define QUEUE_H 

DECLS_BEGIN

struct _Queue;
typedef struct _Queue Queue;

Queue* queue_create(DataDestroyFunc data_destroy,void* ctx);

Ret queue_head(Queue* thiz,void** data);
Ret queue_push(Queue* thiz,void* data);
Ret queue_pop(Queue* thiz);
size_t queue_length(Queue* thiz);
Ret queue_foreach(Queue* thiz,DataVisitFunc visit,void* ctx);

void queue_destroy(Queue* thiz);

DECLS_END

#endif /* QUEUE_H */
