#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int docmd(char *cmd[], int num) {
    
    int i = 0;
    char *arg[10] = {"sh", "-c"};
    pid_t pid;
    
    for (i = 0; i < num; i++) {
        arg[2+i] = cmd[i];
    }
    arg[2+i] = NULL;
    
    pid = fork();
    
    switch (pid) {
        case 0 : {
            printf("just a test\n");
            execv("/bin/sh", arg);
        } break;
        case -1 : {
           printf("fork failure!\n");
           return 1;
        } break;
        default : {
            wait(NULL);
            printf("child process exec complete!\n");
        } break;
    }
    
}

int main (int argc, char *argv[]) {
    
    //if (argc <= 1) {
        //printf("argc error!\n");
        //exit(1);
    //}
    
    docmd(argv, argc);
    
    return 0;
}