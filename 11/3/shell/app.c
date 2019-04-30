/*
 * =====================================================================================
 *
 *       Filename:  app.c
 *
 *    Description:  app c source file 
 *
 *        Version:  1.0
 *        Created:  04/30/2019 12:22:01 PM
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
#include <unistd.h>

int main(int argc,char* argv[])
{
    int n = 0;
     
    printf("Input number:\n");
    fflush(stdout);
    scanf("%d",&n);
    prinf("Your input is %d \n",n);

    return 0;
}
