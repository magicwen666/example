#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static int ntimes = 0;

void p_action(int sig) {
    
    printf("Parent caught signal #%d\n", ++ntimes);
    
}

void c_action(int sig) {
    
    printf("Child  caught signal #%d\n", ++ntimes);
    
}

void main(void) {
    
    pid_t pid = 0;
    pid_t ppid = 0;
    
    signal(SIGUSR1, p_action);
    
    switch (pid = fork()) {
        case -1 : {
            perror("fork failure!\n");
            exit(1);
        } break;
        case 0 : {
            signal(SIGUSR1, c_action);
            ppid = getppid();
            while (1) {
                sleep(1);
                kill(ppid, SIGUSR1);
                pause();
            }
        } break;
        default : {
            while (1) {
                pause();
                sleep(1);
                kill(pid, SIGUSR1);
            }
        } break;
    }
    
}

