#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "jzshell.h"

char *cmdArgs;
char *cmdWithArgsForExec[50];
char *cmd;
const char delim[] = " ";
const char *builtins[]={"cd","exit","pid","ppid"};
int builtinSize=4;

int parseInput(int size, char args[]) {
    int i;
    int returnCode;
    cmd = strtok(args,delim);
    cmdWithArgsForExec[0] = cmd;
    cmdArgs=strtok(0,"\n");
    char *token=strtok(cmdArgs,delim);
    for(i=1;i<size;i++){
        if(token!=NULL){
            cmdWithArgsForExec[i] = token;
            token=strtok(cmdArgs,delim);
        }
    }

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
    pid_t childPid = fork();
    if ( childPid == 0){
        returnCode=execvp(cmdWithArgsForExec[0],cmdWithArgsForExec);
    }

    wait(&childPid);
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
