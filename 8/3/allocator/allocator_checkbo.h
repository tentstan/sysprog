/*
 * =====================================================================================
 *
 *       Filename:  allocator_checkbo.h
 *
 *    Description:  allocator_checkbo head file 
 *
 *        Version:  1.0
 *        Created:  04/22/2019 02:52:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef ALLOCATOR_CHECKBO_H
#define ALLOCATOR_CHECKBO_H 

#include "allocator.h"

DECLS_BEGIN

Allocator* allocator_checkbo_create(Allocator* real_allocator);

DECLS_END 

#endif /* ALLOCATOR_CHECKBO_H */
