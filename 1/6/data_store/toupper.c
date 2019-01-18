/*
 * =====================================================================================
 *
 *       Filename:  toupper.c
 *
 *    Description:  toupper c source file 
 *
 *        Version:  1.0
 *        Created:  01/18/2019 09:49:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char* str_toupper_bad(char* str)
{
    char* p = str;
    if(p != NULL)
    {
        while(*p != '\0')
        {
            if('a' <= *p && *p <= 'z')
            {
                *p = *p - ('a' - 'A');
            }
            p++;
        }
    }

    return str;
}

char* str_toupper_good(char* str)
{
    char* p = str;
    if(p != NULL)
    {
        while(*p != '\0')
        {
            if(islower(*p))
            {
                *p = toupper(*p);
            }
        }
    }

    return str;
}

int main(int argc,char* argv[])
{
    char str1[] = "It is ok.";
    char str2[] = "It is ok.";
    printf("%s\n",str_toupper_bad(str1));
    printf("%s\n",str_toupper_good(str2));
}
