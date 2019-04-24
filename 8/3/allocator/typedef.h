/*
 * =====================================================================================
 *
 *       Filename:  typedef.h
 *
 *    Description:  typedef head file 
 *
 *        Version:  1.0
 *        Created:  04/22/2019 02:30:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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
{printf("%s:%d Warning: "#p" failed.\n", \
        __func__,__LINE__);return(ret);}

#define SAFE_FREE(p) if(P != NULL) {free(p); p = NULL;}

#endif /* TYPEDEF_H */
