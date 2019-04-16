/*
 * =====================================================================================
 *
 *       Filename:  darray_iterator.h
 *
 *    Description:  darray_iterator head file 
 *
 *        Version:  1.0
 *        Created:  04/03/2019 09:19:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef DARRAY_ITERATOR_H
#define DARRAY_ITERATOR_H 

#include "darray.h"
#include "iterator.h"

DECLS_BEGIN

Iterator* darray_iterator_create(DArray* thiz);

DECLS_END

#endif /* DARRAY_ITERATOR_H */
