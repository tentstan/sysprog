/*
 * =====================================================================================
 *
 *       Filename:  rw_locker.h
 *
 *    Description:  rw_locker header file 
 *
 *        Version:  1.0
 *        Created:  02/15/2019 10:15:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "locker.h"

#ifndef RW_LOCKER_H
#define RW_LOCKER_H 

struct _RwLocker;
typedef struct _RwLocker RwLocker;

RwLocker* rw_locker_create(Locker* rw_locker,Locker* rd_locker);

Ret rw_locker_wrlock(RwLocker* thiz);
Ret rw_locker_rdlock(RwLocker* thiz);
Ret rw_locker_unlock(RwLocker* thiz);

void rw_locker_destroy(RwLocker* thiz);

#endif /* RW_LOCKER_H */
