#ifndef BRAIN_H
#define BRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int command_and_control(char *path, char **command);
unsigned int tokenizer(char *str, char *delim);
char **token_processing(char *str, char *delim);
int command_handle(char *command);
int path_handle(char *buffer);
int free_memory(char **ptr);
int non_stdin_handle(char *buffer);
int non_interactive_handle(char *buffer);
#endif /*BRAIN_H*/
