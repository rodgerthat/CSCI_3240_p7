/* 
 * Norris Joel R. 
 * CSCI_3240
 * Project 7
 * Dr. Butler
 * Zombies and reaping and children, oh my!
 */
  
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* include any other required header files here */
/* gonna need one for wait */

/* fill in the blanks */
/*  feel free to make this volatile */
/*  keeps compiler from whining about inf loops */
volatile int child_done;


/* put CHLD signal handler function here */
void child_signal_handler(int signal) {

    // check for code 17, which is exit
    if (signal == 17) {
        child_done = 1;
    }
}


int main(int argc, char *argv[])
{
    int pid, status;

    alarm(60);

    /* install CHLD signal handler here */
    /* one line of code to pass to signal handler */
    signal(SIGCHLD, child_signal_handler);

    child_done = 0;

    if ((pid = fork()) == -1)
    {
        printf("fork failed\n");
        exit(-1);
    }

    if (pid == 0)  // child
    {
        p7test();  // bases its actions on env vars
        exit(0);
    }

    /* exciting inf loop */
    while ( ! child_done) {

        ;
    }

    /* obtain child termination/signal/exit info and print it here */
    /*  
    use those wait macros to test status
    print NORMAL if terminated normall
    print ABEND if ended abnormally ( like segfault or whatevers )
        also print signal number and exit code it termed w/ 
    */
    
    wait(&status);

    if (WIFEXITED(status)) {
        printf("NORMAL %d\n", WEXITSTATUS(status));
    }

    if (WIFSIGNALED(status)) {
        printf("ABEND %d\n", WTERMSIG(status));
    }

    // So long and thanks for all the fish!

}
