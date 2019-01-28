/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  sort head file 
 *
 *        Version:  1.0
 *        Created:  01/28/2019 02:46:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef SORT_H
#define SORT_H 

#include "typedef.h"

DECLS_BEGIN

Ret bubble_sort(void** array,size_t nr,DataCompareFunc cmp);
Ret quick_sort(void** array,size_t nr,DataCompareFunc cmp);
Ret merge_sort(void** array,size_t nr,DataCompareFunc cmp);

DECLS_END

#endif /* SORT_H */
