/*
 * =====================================================================================
 *
 *       Filename:  allocator_pool.h
 *
 *    Description:  allocator_pool head file 
 *
 *        Version:  1.0
 *        Created:  04/22/2019 03:49:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ALLOCATOR_POOL_H
#define ALLOCATOR_POOL_H 

#include "allocator.h"

DECLS_BEGIN

Allocator* allocator_pool_create(size_t expand_delta);

DECLS_END

#endif /* ALLOCATOR_POOL_H */
