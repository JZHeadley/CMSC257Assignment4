#include <stdio.h>
#include <string.h>

#include "jzshell.h"

char command[50];
char *shellName;
int main(int argc, char* argv[]){
    if(argc > 0){
        printf("parsing args\n");
        char* arg =strtok(argv," ");
        while(arg != NULL){

            if (strcmp(arg,"-p")!=0){
                printf("was passed a shell name\n");

                shellName=strtok(NULL," ");
            }
        }
    }

    printf("%s> ",shellName);
    while(1) {

        scanf("%s",command);
        int commandSize=sizeof(command) / sizeof(*command);

        handleInput(strlen(command),command);
    }
    return 0;
}

