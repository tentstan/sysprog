/*
 * =====================================================================================
 *
 *       Filename:  linear_container_dlist.h
 *
 *    Description:  linear_container_dlist head file 
 *
 *        Version:  1.0
 *        Created:  03/04/2019 09:46:36 AM
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

DECLS_BEGIN

LinearContainer* linear_container_dlist_create(DataDestroyFunc data_destroy,void* ctx);

DECLS_END

#endif /* LINEAR_CONTAINER_DLIST_H */
