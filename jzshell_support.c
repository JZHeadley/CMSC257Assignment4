#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "jzshell.h"

char *cmdArgs;
char *cmd;
const char delim[] = " ";
const char *builtins[]={"cd","exit","pid","ppid"};
int builtinSize=4;
int parseInput(int size, char args[]) {
    int returnCode;
    cmd = strtok(args,delim);
    cmdArgs=strtok(0,"\n");
    //strncpy(cmdArgs,args+strlen(cmd),size-strlen(cmd));
    returnCode=handleCommands(cmd,cmdArgs,size);

    return 0;
}

int handleCommands(char *cmd,char *args, int argsSize){
    char *string;
    printf("cmd:\t%s\n",cmd);
    printf("args:\t%s\n",args);
    string = strtok(args,delim);
    while (string != NULL){
        printf("%s\n",string);
        string = strtok(NULL,delim);
    }
    if (isCommandBuiltin(cmd)!=0){// not a builtin
        /*handleNonBuiltin();*/
    }else{
        handleBuiltin(cmd,args);
        return 0;
    }
}


int isCommandBuiltin(char *cmd){
    int i;
    for(i=0;i<builtinSize;i++){
        if(builtins[i] == cmd);
        return 1;
    }
    return 0;
}
int handleNonBuiltin(char *cmd, char* args){
    if(strcmp(cmd,"cd")) {

    } else if(strcmp(cmd,"exit")) {
        exit(0);
    } else if(strcmp(cmd,"pid")) {

    } else if(strcmp(cmd,"ppid")) {

    }
    return 0;
}
int handleBuiltin(char *cmd,char* args){
    return 0;
}
