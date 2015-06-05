#include "smallsh.h"

static char inputbuf[MAXBUF] = {0};
static char tokbuf[2 * MAXBUF] = {0};
static char *ptr = inputbuf;
static char *tok = tokbuf;

int userin(char *p) {
    
    int c = 0;
    int count = 0;
    
    ptr = inputbuf;
    tok = tokbuf;
    
    printf("%s", p);
    
    while (1) {
        if (EOF == (c = getchar())) {
            return EOF;
        }
        if (count < MAXBUF) {
            inputbuf[count++] = c;
        }
        if ('\n' == c && count < MAXBUF) {
            inputbuf[count] = '\0';
            return count;
        }
        if ('\n' == c) {
            printf("smallsh:input line too long\n");
            count = 0;
            printf("%s", p);
        }
    }
    
    return 0;
}

extern char **environ;

void main () {
    
    char **env = environ;
    
    while (*env) {
        printf("%s\n", *env++);
    }
    
}