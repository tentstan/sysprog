/*
 * =====================================================================================
 *
 *       Filename:  atomic.c
 *
 *    Description:  atomic c source file 
 *
 *        Version:  1.0
 *        Created:  02/18/2019 04:08:02 PM
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
#include <pthread.h>
#include "iatomic.h"

#ifdef ATOMIC_TEST

atomic_t g_count = {0};

#define NR 1000000

static void* thread_inc(void* param)
{
    int i = 0;

    for(i = 0; i < NR; i++)
    {
        atomic_inc(&g_count);
    }

    return NULL;
}

static void* thread_dec(void* param)
{
    int i = 0;
    for(i = 0; i < NR; i++)
    {
        atomic_dec(&g_count);
    }

    return NULL;
}

int main(int argc,char* argv[])
{
    pthread_t inc_tid = 0;
    pthread_t dec_tid = 0;

    pthread_create(&inc_tid,NULL,thread_inc,NULL);
    pthread_create(&dec_tid,NULL,thread_dec,NULL);

    pthread_join(inc_tid,NULL);
    pthread_join(dec_tid,NULL);

    printf("count = %d \n",g_count.counter);

    return 0;
}

#endif /* ATOMIC_TEST */
