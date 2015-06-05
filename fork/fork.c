#include <stdio.h>
#include <unistd.h>

int main(void) {
    
    pid_t pid;
    
    printf("Now only one process!\n");
    printf("Calling fork....\n");
    
    pid = fork();
    
    if (0 == pid) {
        printf("I'm the child!\n");
    } else if (pid > 0) {
        printf("I'm the parent, child's pid is %d\n", pid);
    } else {
        printf("Fork failure!\n");
    }
    
    
    return 0;
}