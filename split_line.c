#include "shell.h"

#define BUFSIZE 64
#define DELIM " \t\r\n\a:"

/**
 *split_line - Convert string to tokens
 *@line: Input string
 *Return: Array of tokens
 */

char **split_line(char *line)
{
int i = 0;
int bufsize = BUFSIZE;
char *token;
char **tokens;
char **tokens_backup;

tokens = malloc(sizeof(char *) * BUFSIZE);

if (!tokens)
{
	perror("Allocation error\n");
	exit(EXIT_FAILURE);
}

token = strtok(line, DELIM);
while (token != NULL)
{
tokens[i] = token;
i++;

if (i >= bufsize)
{
	bufsize = bufsize + BUFSIZE;
	tokens_backup = tokens;
	tokens = realloc(tokens, sizeof(char *) * bufsize);
	if (!tokens)
	{
		free(tokens_backup);
		perror("Allocation error\n");
		exit(EXIT_FAILURE);
	}
}

token = strtok(NULL, DELIM);
}

tokens[i] = NULL;
return (tokens);
}
