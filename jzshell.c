#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "jzshell.h"


#define RED "\x1b[31m"
#define RESET "\x1b[0m"

char *shellName="257sh";

void printEndStatus(int statusCode){
    if (statusCode == 0){
        fprintf(stdout,"The command worked with status code %i\n",statusCode);
    } else {
        fprintf(stderr,RED"The command failed with status code %i\n"RESET,statusCode);
    }
}

void printPrompt(){
    char cwd[100];
    getcwd(cwd,100);
    printf("%s:%s> ",shellName,cwd);

}

void signal_handler(int sigNum){
    printf("\n");
    printPrompt();
    return;
}

int main(int argc, char* argv[]){
    int i;
    char command[50];
    signal(SIGINT,signal_handler);
    int status;
    if(argc > 0){
        for(i=1;i<argc;i++){
            if (strcmp(argv[i],"-p")!=0){
                shellName=argv[i];
            }
        }
    }

    while(1) {
        printPrompt();
        fgets(command,sizeof(command),stdin);
        command[strlen(command)-1]='\0';
        status = parseInput(strlen(command),command);
        printEndStatus(status);
    }

    return 0;
}


