/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  stack head file 
 *
 *        Version:  1.0
 *        Created:  02/28/2019 09:46:01 AM
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

#ifndef STACK_H
#define STACK_H 

DECLS_BEGIN

struct _Stack;
typedef struct _Stack Stack;

Stack* stack_create(DataDestroyFunc data_destroy,void* ctx);

Ret stack_top(Stack* thiz,void** data);
Ret stack_push(Stack* thiz,void* data);
Ret stack_pop(Stack* thiz);
size_t stack_length(Stack* thiz);
Ret stack_foreach(Stack* thiz,DataVisitFunc visit,void* ctx);

void stack_destroy(Stack* thiz);

DECLS_END

#endif /* STACK_H */
