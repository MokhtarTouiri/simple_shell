#include "shell.h"

#define BUFSIZE 256
#define DELIM " \t\r\n\a\v:"

/**
 *split_line - Convert string to tokens
 *@line: Input string
 *Return: Array of tokens
 */

char **split_line(char *line)
{
int i = 0;
char *token;
char **tokens;

if (line == NULL)
	return (NULL);

tokens = malloc(sizeof(char *) * BUFSIZE);

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
token = strtok(NULL, DELIM);

}
if (*tokens == NULL && tokens == NULL)
{
	free(tokens);
	free(token);
	return (NULL);
}


tokens[i] = NULL;
return (tokens);
}
