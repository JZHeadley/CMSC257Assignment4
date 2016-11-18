#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "jzshell.h"

void printEndStatus(int statusCode){
    if (statusCode == 0){
        printf("The command worked with status code %i\n",statusCode);
    } else {
        printf("The command failed with status code %i\n",statusCode);
    }
}

int main(int argc, char* argv[]){
    int i;
    char *shellName="shell";
    char command[50];
    int status;
    if(argc > 0){
        for(i=1;i<argc;i++){
            if (strcmp(argv[i],"-p")!=0){
                //printf("was passed a shell name\n");
                shellName=argv[i];
            }
        }
    }

    while(1) {
        printf("%s> ",shellName);
        fgets(command,sizeof(command),stdin);
        status = parseInput(strlen(command),command);
        printEndStatus(status);
    }

    return 0;
}


