/*
 * =====================================================================================
 *
 *       Filename:  locker_nest.h
 *
 *    Description:  locker_nest head file 
 *
 *        Version:  1.0
 *        Created:  01/30/2019 03:34:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "locker.h"

#ifndef LOCKER_NEST_H
#define LOCKER_NEST_H 

DECLS_BEGIN

typedef int (*TaskSelfFunc)(void);
Locker* locker_nest_create(Locker* real_locker,TaskSelfFunc task_self);

DECLS_END

#endif /* LOCKER_NEST_H */
