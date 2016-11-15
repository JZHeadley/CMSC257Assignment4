#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "jzshell.h"


int handleInput(int size, char* args[]) {
    char *string;
    const char delim[] = " ";

    string = strtok(args,delim);

    while (string != NULL){
        printf("%s\n",string);
        string = strtok(NULL,delim);
    }
    return 0;
}
