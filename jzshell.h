#include <stdio.h>


#ifndef JZSHELL_INCLUDED
#define JZSHELL_INCLUDED


int parseInput(int size, char* args);

int handleCommands(char *cmd,char * args, int argsSize);

int handleNonBuiltin(char *cmd,char *args);

int handleBuiltin(char *cmd,char *args);
#endif
