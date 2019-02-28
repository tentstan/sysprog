/*
 * =====================================================================================
 *
 *       Filename:  test_helper.c
 *
 *    Description:  test_helper c source file 
 *
 *        Version:  1.0
 *        Created:  02/28/2019 09:43:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

static int cmp_int(void* ctx,void* data)
{
    return (int)ctx - (int)data;
}

static Ret print_int(void* ctx,void* data)
{
    printf("%d ",(int)(data));

    return RET_OK;
}
