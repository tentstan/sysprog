/*
 * =====================================================================================
 *
 *       Filename:  allocator_self_manage.h
 *
 *    Description:  allocator_self_manage head file 
 *
 *        Version:  1.0
 *        Created:  04/22/2019 04:20:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ALLOCATOR_SELF_MANAGE_H
#define ALLOCATOR_SELF_MANAGE_H 

#include "allocator.h"

DECLS_BEGIN

Allocator* allocator_self_manage_create(void* buffer,size_t length);

DECLS_END

#endif /* ALLOCATOR_SELF_MANAGE_H */
