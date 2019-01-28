/*
 * =====================================================================================
 *
 *       Filename:  sort.h
 *
 *    Description:  sort head file 
 *
 *        Version:  1.0
 *        Created:  01/25/2019 05:55:39 PM
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

Ret bubble_sort(void** array,size_t nr,DataCompareFunc cmp);
Ret quick_sort(void** array,size_t nr,DataCompareFunc cmp);
Ret merge_sort(void** array,size_t nr,DataCompareFunc cmp);

#endif /* SORT_H */
