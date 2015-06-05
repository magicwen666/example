#include <stdio.h>
#include <unistd.h>


void main(void) {
    
    pid_t pid;
    
    pid = fork();
    
    if (0 == pid) { /* child process */
        printf("exec ls commond !\n");
        execl("/bin/ls", "ls", "-al", NULL);
    } else if (pid > 0) {  /* parent process */
        wait(NULL);
        printf("commod 'ls' exec complete!\n");
    } else {
        printf("fork failure!\n");
    }
    
}
