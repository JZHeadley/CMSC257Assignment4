#include <stdio.h>
#include <string.h>

#include "jzshell.h"


int main(int argc, char* argv[]){
    int i;
    char *shellName="shell";
    char command[50];


    if(argc > 0){
        for(i=1;i<argc;i++){
            //printf("comparison between arg and -p:\t%i\n",strcmp(argv[i],"-p"));
            if (strcmp(argv[i],"-p")!=0){
                //printf("was passed a shell name\n");
                shellName=argv[i];
            }
        }
    }

    while(1) {
        printf("%s> ",shellName);
        gets(command);
        handleInput(strlen(command),command);
    }
    return 0;
}

