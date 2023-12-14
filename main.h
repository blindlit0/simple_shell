#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void execmd(char **argv); /*Executes command passed to terminal*/

char *get_location(char *command);

int stat(const char *pathname, struct stat *statbuff);

#endif