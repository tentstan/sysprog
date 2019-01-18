/*
 * =====================================================================================
 *
 *       Filename:  heap_error.c
 *
 *    Description:  heap_error c source file 
 *
 *        Version:  1.0
 *        Created:  01/18/2019 10:01:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>

/*# valgrind --tool=memcheck --leak-check=full ./heap_error */

int main(int argc, char* argv[])
{
    /*memory leak and buffer overflow.*/

    char* str = malloc(10);
    strcpy(str,"123456788900");

    return 0;
}
