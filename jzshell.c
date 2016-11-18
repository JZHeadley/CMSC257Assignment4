#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "jzshell.h"


#define RED "\x1b[31m"
#define RESET "\x1b[0m"


void printEndStatus(int statusCode){
    if (statusCode == 0){
        fprintf(stdout,"The command worked with status code %i\n",statusCode);
    } else {
        fprintf(stderr,RED"The command failed with status code %i\n"RESET,statusCode);
    }
}

int main(int argc, char* argv[]){
    int i;
    char *shellName="257sh";
    char command[50];
    char cwd[100];
    int status;
    if(argc > 0){
        for(i=1;i<argc;i++){
            if (strcmp(argv[i],"-p")!=0){
                shellName=argv[i];
            }
        }
    }

    while(1) {
        getcwd(cwd,100);
        printf("%s:%s> ",shellName,cwd);
        fgets(command,sizeof(command),stdin);
        command[strlen(command)-1]='\0';
        status = parseInput(strlen(command),command);
        printEndStatus(status);
    }

    return 0;
}


