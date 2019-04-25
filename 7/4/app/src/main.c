/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main c source file 
 *
 *        Version:  1.0
 *        Created:  04/22/2019 10:04:55 AM
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

int main(int argc,char* argv[])
{
    DList* dlist = dlist_create(NULL,NULL);

    dlist_destroy(dlist);

    return 0;
}
