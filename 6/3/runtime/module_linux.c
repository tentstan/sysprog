/*
 * =====================================================================================
 *
 *       Filename:  module_linux.c
 *
 *    Description:  module_linux c source file 
 *
 *        Version:  1.0
 *        Created:  03/07/2019 11:35:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <dlfcn.h>
#include "module.h"

struct _Module
{
    void* handle;
};

Module* module_create(const char* file_name,ModuleFlags flags)
{
    Module* thiz = NULL;
    return_val_if_fail(file_name != NULL,NULL);

    if((thiz == malloc(sizeof(Module))) != NULL)
    {
        thiz->handle = dlopen(file_name,flags & MODULE_FLAGS_DELAY ? RTLD_LAZY : RTLD_NOW);
        if(thiz->handle == NULL)
        {
            free(thiz);
            thiz = NULL;
            printf("%s \n",dlerror());
        }
    }

    return thiz;
}

void* module_sym(Module* thiz,const char* func_name)
{
    return_val_if_fail(thiz != NULL && thiz->handle != NULL && func_name != NULL,NULL);

    dlerror();
    return dlsym(thiz->handle,func_name);
}

void module_destroy(Module* thiz)
{
    if(thiz != NULL)
    {
        if(thiz->handle != NULL)
        {
            dlclose(thiz->handle);
        }

        free(thiz);
    }

    return;
}
