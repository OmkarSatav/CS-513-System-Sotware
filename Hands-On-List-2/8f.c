/*============================================================================
Name : 8f.c
Author : Omkar Satav
Description : Write a separate program using signal system call to catch the following signals.
            f. SIGVTALRM (use setitimer system call).
Date: 17th Sept, 2024.
============================================================================
*/


#include <stdio.h>      // For using Standard Input Output functions like printf().
#include <signal.h>     // For using signal handling functions like signal().
#include <stdlib.h>     // For using exit().
#include <sys/time.h>   // For using setitimer() and itimerval.
#include <unistd.h>     // For using pause().


void virtualTimerHandler(int signum) {            // Signal handler for SIGVTALRM
    printf("Caught Virtual Timer Signal.\n");
    exit(0);
}

int main() {
    struct itimerval clock;

    signal(SIGVTALRM, virtualTimerHandler);   // Set signal handler for SIGVTALRM


    clock.it_value.tv_sec = 5;                // Set the timer. First expiration in 2 seconds
    clock.it_value.tv_usec = 0;

    clock.it_interval.tv_sec = 0;             // No repeat
    clock.it_interval.tv_usec = 0;
    
    setitimer(ITIMER_VIRTUAL, &clock, NULL); // Set the virtual timer

    pause();                                 // Wait for the signal

    return 0;
}



/*


Caught Virtual Timer Signal.


*/