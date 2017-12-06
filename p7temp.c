/*
 * =====================================================================================
 *
 *       Filename:  p7temp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2017 12:00:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    int rc, pid, status;

    pid = fork();
    if (pid==0) {
        
        rc = p7test();   
        printf("RC %d \n", rc );
        exit(0);
    }

    wait(&status);
    printf("STAT %d\n", status);    /* we'll use the WHF macros from wait */

    return 0;
}
