/*
 * =====================================================================================
 *
 *       Filename:  dlist.c
 *
 *    Description:  dlist c source file 
 *
 *        Version:  1.0
 *        Created:  01/18/2019 11:12:27 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "dlist.h"

typedef struct _DListNode
{
    struct _DListNode* prev;
    struct _DListNode* next;

    void* data;
}DListNode;

struct _DList
{
    DListNode* first;
    DListDataDestroyFunc data_destroy;
    void* data_destroy_ctx;
};

static void dlist_destroy_data(DList* thiz,void* data)
{
    if(thiz->data_destroy != NULL)
    {
        thiz->data_destroy(thiz->data_destroy_ctx,data);
    }

    return;
}

static DListNode* dlist_create_node(DList* thiz,void* data)
{
    DListNode* node = malloc(sizeof(DListNode));

    if(node != NULL)
    {
        node->prev = NULL;
        node->next = NULL;
        node->data = data;
    }

    return node;
}

static void dlist_destroy_node(DList* thiz,DListNode* node)
{
    if(node != NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        dlist_destroy_data(thiz,node->data);
        free(node);
    }

    return;
}

DList* dlist_create(DListDataDestroyFunc data_destroy,void* data_destroy_ctx)
{
    DList* thiz = malloc(sizeof(DList));

    if(thiz != NULL)
    {
        thiz->first = NULL;
        thiz->data_destroy = data_destroy;
        thiz->data_destroy_ctx = data_destroy_ctx;
    }

    return thiz;
}

static DListNode* dlist_get_node(DList* thiz,size_t index,int fail_return_last)
{
    DListNode* iter = thiz->first;

    while(iter != NULL && iter->next != NULL && index > 0)
    {
        iter = iter->next;
        index--;
    }

    if(!fail_return_last)
    {
        iter = index > 0 ? NULL : iter;
    }

    return iter;
}        

DListRet dlist_insert(DList* thiz,size_t index,void* data)
{
    DListNode* node = NULL;
    DListNode* cursor = NULL;

    if((node = dlist_create_node(thiz,data)) == NULL)
    {
        return DLIST_RET_OOM;
    }

    if(thiz->first == NULL)
    {
        thiz->first = node;

        return DLIST_RET_OK;
    }

    cursor = dlist_get_node(thiz,index,1);

    if(index < dlist_length(thiz))
    {
        if(thiz->first == cursor)
        {
            thiz->first = node;
        }
        else 
        {
            cursor->prev->next = node;
            node->prev = cursor->prev;
        }

        node->next = cursor;
        cursor->prev = node;
    }
    else
    {
        cursor->next = node;
        node->prev = cursor;
    }

    return DLIST_RET_OK;
}

DListRet dlist_prepend(DList* thiz,void* data)
{
    return dlist_insert(thiz,0,data);
}

DListRet dlist_append(DList* thiz,void* data)
{
    return dlist_insert(thiz,-1,data);
}

DListRet dlist_delete(DList* thiz,size_t index)
{
    DListNode* cursor = dlist_get_node(thiz,index,0);

    if(cursor != NULL)
    {
        if(cursor == thiz->first)
        {
            thiz->first = cursor->next;
        }

        if(cursor->next != NULL)
        {
            cursor->next->prev = cursor->prev;
        }

        if(cursor->prev != NULL)
        {
            cursor->prev->next = cursor->next;
        }
    }

    return DLIST_RET_OK;
}

DListRet dlist_get_by_index(DList* thiz,size_t index,void** data)
{
    DListNode* cursor = dlist_get_node(thiz,index,0);

    if(cursor != NULL)
    {
        *data = cursor->data;
    }

    return cursor != NULL ? DLIST_RET_OK : DLIST_RET_FAIL;
}

DListRet dlist_set_by_index(DList* thiz,size_t index,void* data)
{
    DListNode* cursor = dlist_get_node(thiz,index,0);

    if(cursor != NULL)
    {
        cursor->data = data;
    }

    return cursor != NULL ? DLIST_RET_OK : DLIST_RET_FAIL;
}

size_t dlist_length(DList* thiz)
{
    size_t length = 0;
    DListNode* iter = thiz->first;

    while(iter != NULL)
    {
        length++;
        iter = iter->next;
    }

    return length;
}

DListRet dlist_foreach(DList* thiz,DListDataVisitFunc visit,void* ctx)
{
    DListRet ret = DLIST_RET_OK;
    DListNode* iter = thiz->first;

    while(iter != NULL && ret != DLIST_RET_STOP)
    {
        ret = visit(ctx,iter->data);

        iter = iter->next;
    }

    return ret;
}

int dlist_find(DList* thiz,DListDataCompareFunc cmp,void* ctx)
{
    int i = 0;
    DListNode* iter = thiz->first;

    while(iter != NULL)
    {
        if(cmp(ctx,iter->data) == 0)
        {
            break;
        }
        i++;
        iter = iter->next;
    }

    return i;
}

void dlist_destroy(DList* thiz)
{
    DListNode* iter = thiz->first;
    DListNode* next = NULL;

    while(iter != NULL)
    {
        next = iter->next;
        dlist_destroy_node(thiz,iter);
        iter = next;
    }

    thiz->first = NULL;
    free(thiz);

    return;
}
