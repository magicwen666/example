#include <stdio.h>
#include <unistd.h>

int main(void) {
    
    char *arg[] = {"helloword", "hello", "world", NULL};
    
    printf("Executing\n");
    //execl("/bin/ls", "ls", "-al", NULL);
    //execlp("ls", "ls", "-al", NULL);
    //execv("/bin/ls", arg);
    execvp("/share/example/exec/helloword", arg);
    perror("exec failure to run\n");
    
    
    return 0;
}