#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#define NULL (void *)0

/*
 *Headers
 */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *Functions From previous works
 */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

/*
 *NEW FUNCTIONS
 */

char **split_line(char *line);
int launch(char **av);
int execute(char **av);
char *read_line(void);


/*
 *BUILTIN COMMANDS
 */

int _cd(char **av);
int _help(char **av);
int newexit(char **av);

#endif

