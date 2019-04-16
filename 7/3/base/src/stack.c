/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  stack c source file 
 *
 *        Version:  1.0
 *        Created:  04/16/2019 05:17:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "stack.h"
#include "dlist.h"

struct _Stack
{
    DList* dlist;
};

Stack* stack_create(DataDestroyFunc data_destroy,void* ctx)
{
    Stack* thiz = (Stack*)malloc(sizeof(Stack));

    if(thiz != NULL)
    {
        if((thiz->dlist = dlist_create(data_destroy,ctx)) == NULL)
        {
            free(thiz);
            thiz = NULL;
        }
    }

    return thiz;
}

Ret stack_top(Stack* thiz,void** data)
{
    return_val_if_fail(thiz != NULL && data != NULL,RET_INVALID_PARAMS);

    return dlist_get_by_index(thiz->dlist,0,data);
}

Ret stack_push(Stack* thiz,void* data)
{
    return_val_if_fail(thiz != NULL,RET_INVALID_PARAMS);

    return dlist_prepend(thiz->dlist,data);
}

Ret stack_pop(Stack* thiz)
{
    return_val_if_fail(thiz != NULL,RET_INVALID_PARAMS);

    return dlist_delete(thiz->dlist,0);
}

size_t stack_length(Stack* thiz)
{
    return_val_if_fail(thiz != NULL,0);

    return dlist_length(thiz->dlist);
}

Ret stack_foreach(Stack* thiz,DataVisitFunc visit,void*  ctx)
{
    return_val_if_fail(thiz != NULL && visit != NULL,RET_INVALID_PARAMS);

    return dlist_foreach(thiz->dlist,visit,ctx);
}

void stack_destroy(Stack* thiz)
{
    if(thiz != NULL)
    {
        dlist_destroy(thiz->dlist);
        thiz->dlist = NULL;

        free(thiz);
    }

    return;
}


#ifdef STACK_TEST

#include "test_helper.c"

int main(int argc,char* argv[])
{
    int i = 0;
    int n = 1000;
    int ret_data = 0;

    Stack* stack = stack_create(NULL,NULL);

    for(i = 0; i < n; i++)
    {
        assert(stack_push(stack,(void*)i) == RET_OK);
        assert(stack_top(stack,(void**)&ret_data) == RET_OK);
        assert(stack_length(stack) == (i+1));
    }

    stack_foreach(stack,print_int,NULL);

    for(i = 0; i < n; i++)
    {
        assert(statck_top(stack,(void**)&ret_data) == RET_OK);
        assert(ret_data == (n - i - 1));
        assert(stack_length(stack) == (n- i));
        assert(stack_pop(stack) == RET_OK);
    }

    stack_destroy(stack);

    return 0;
}

#endif /* STACK_TEST */
