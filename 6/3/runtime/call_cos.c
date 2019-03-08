/*
 * =====================================================================================
 *
 *       Filename:  call_cos.c
 *
 *    Description:  call_cos c source file 
 *
 *        Version:  1.0
 *        Created:  03/07/2019 11:46:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc,char* argv[])
{
    void* handle = NULL;

    double (*cosine)(double) = NULL;

    handle = dlopen("libm.so",RTLD_LAZY);
    *(void**)(&cosine) = dlsym(handle,"cos");
    printf("%f\n",(*cosine)(2.0));

    dlclose(handle);

    return 0;

}
