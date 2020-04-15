#include "shell.h"

#define BUFSIZE 1024
#define DELIM " \t\r\n\a\v:"

/**
 *split_line - Convert string to tokens
 *@line: Input string
 *Return: Array of tokens
 */

char **split_line_backup(char *line)
{
int i = 0;
int bufsize = BUFSIZE;
char *token;
char **tokens;
char **tokens_backup;

if (line == NULL)
	return (NULL);

tokens = malloc(sizeof(char *) * bufsize);

if (tokens == NULL)
{
	return (NULL);
}

*tokens = NULL;
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
