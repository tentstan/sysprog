/*
 * =====================================================================================
 *
 *       Filename:  locker_pthread.h
 *
 *    Description:  locker_pthread head file 
 *
 *        Version:  1.0
 *        Created:  01/30/2019 11:51:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "locker.h"

#ifndef LOCKER_PTHREAD_H
#define LOCKER_PTHREAD_H 

DECLS_BEGIN

Locker* locker_pthread_create(void);

DECLS_END

#endif /* LOCKER_PTHREAD_H */
