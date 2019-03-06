/*
 * =====================================================================================
 *
 *       Filename:  dlist_iterator.h
 *
 *    Description:  dlist_iterator head file 
 *
 *        Version:  1.0
 *        Created:  03/05/2019 02:26:02 PM
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
