#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "jzshell.h"

char *cmdArgs;
char * cmdWithArgsForExec;
char *cmd;
const char delim[] = " ";
const char *builtins[]={"cd","exit","pid","ppid"};
int builtinSize=4;

int parseInput(int size, char args[]) {
    int returnCode;
    cmdWithArgsForExec = args;
    cmd = strtok(args,delim);
    cmdArgs=strtok(0,"\n");
    returnCode=handleCommands(cmd,cmdArgs,size);
    return returnCode;
}

int isCommandBuiltin(char *cmd){
    int i;
    for(i=0;i<builtinSize;i++){
        if(strcmp(cmd,builtins[i]) == 0)
            return 1;
    }
    return 0;
}

int handleCommands(char *cmd,char *args, int argsSize){
    char *string;
    int returnCode=0;
    string = strtok(args,delim);
    while (string != NULL){
        //printf("%s\n",string);
        string = strtok(NULL,delim);
    }
    if (isCommandBuiltin(cmd)==1){
        returnCode = handleBuiltin(cmd,args);
    } else{ // Not a builtin Command
        returnCode = handleNonBuiltin(cmd,args);
    }
    return returnCode;
}

int handleNonBuiltin(char *cmd, char* args){
    int returnCode=0;
    printf("handlingnonbuiltins\n");

    execvp(cmd,cmdWithArgsForExec);
    return returnCode;
}


int handleBuiltin(char *cmd,char* args){
    char cwd[100];
    int returnCodeue=0;
    printf("handlingbuiltins\n");
    if(strcmp(cmd,"cd")==0) {
        if(args==NULL)
            getcwd(cwd,100);
        else
            returnCodeue=chdir(args);
        printf("%s\n",cwd);
    } else if(strcmp(cmd,"exit")==0) {
        raise(SIGKILL);
    } else if(strcmp(cmd,"pid")==0) {
        printf("The pid of the shell is %i\n",getpid());
    } else if(strcmp(cmd,"ppid")==0) {
        printf("The pid of the parent process is %i\n",getppid());
    }

    return returnCodeue;
}
