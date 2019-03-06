/*
 * =====================================================================================
 *
 *       Filename:  linear_container_darray.h
 *
 *    Description:  linear_container_darray head file 
 *
 *        Version:  1.0
 *        Created:  03/05/2019 05:55:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef LINEAR_CONTAINER_DARRAY_H
#define LINEAR_CONTAINER_DARRAY_H 

#include "linear_container.h"

LinearContainer* linear_container_darray_create(DataDestroyFunc data_destroy,void* ctx);

#endif /* LINEAR_CONTAINER_DARRAY_H */
