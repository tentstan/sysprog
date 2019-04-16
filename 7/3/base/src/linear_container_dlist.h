/*
 * =====================================================================================
 *
 *       Filename:  linear_container_dlist.h
 *
 *    Description:  linear_container_dlist head file 
 *
 *        Version:  1.0
 *        Created:  04/11/2019 06:16:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef LINEAR_CONTAINER_DLIST_H
#define LINEAR_CONTAINER_DLIST_H 

#include "linear_container.h"

LinearContainer* linear_container_dlist_create(DataDestroyFunc data_destroy,void* ctx);

#endif /* LINEAR_CONTAINER_DLIST_H */
