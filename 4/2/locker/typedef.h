/*
 * =====================================================================================
 *
 *       Filename:  typedef.h
 *
 *    Description:  typedef head file 
 *
 *        Version:  1.0
 *        Created:  01/29/2019 10:43:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#ifndef TYPEDEF_H
#define TYPEDEF_H 

typedef enum _Ret
{
    RET_OK,
    RET_OOM,
    RET_STOP,
    RET_INVALID_PARAMS,
    RET_FAIL
}Ret;

#ifdef __cplusplus
#define DECLS_BEGIN extern "C" {
#define DECLS_END }
#else 
#define DECLS_BEGIN 
#define DECLS_END 
#endif /* __cplusplus */

#define return_if_fail(p) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed.\n", \
            __func__,__LINE__);return;}

#define return_val_if_fail(p,ret) if(!(p)) \
    {printf("%s:%d Warning: "#p" failed.\n",\
            __func__,__LINE__);return (ret);}

#define SAFE_FREE(p) if(p != NULL) {free(p); p = NULL;}

#endif /* TYPEDEF_H */

