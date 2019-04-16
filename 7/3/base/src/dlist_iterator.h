/*
 * =====================================================================================
 *
 *       Filename:  dlist_iterator.h
 *
 *    Description:  dlist_iterator header file 
 *
 *        Version:  1.0
 *        Created:  04/11/2019 11:51:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef DLIST_ITERATOR_H
#define DLIST_ITERATOR_H 

#include "dlist.h"
#include "iterator.h"

DECLS_BEGIN

Iterator* dlist_iterator_create(DList* dlist);

DECLS_END

#endif /* DLIST_ITERATOR_H */
