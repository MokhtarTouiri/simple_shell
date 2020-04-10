#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

/*
 *Headers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *Functions
 */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char **tokenizer(char *str);

#endif
