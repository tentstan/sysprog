/*
 * =====================================================================================
 *
 *       Filename:  allocator_shmem.h
 *
 *    Description:  allocator_shmem head file 
 *
 *        Version:  1.0
 *        Created:  04/24/2019 04:55:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ALLOCATOR_SHMEM_H
#define ALLOCATOR_SHMEM_H 

#include "allocator.h"

DECLS_BEGIN

Allocator* allocator_shmem_create(void* addr,size_t init_size);

DECLS_END

#endif /* ALLOCATOR_SHMEM_H */
