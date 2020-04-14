#include "shell.h"

/**
 *readline - read a input line from user
 */

char *readline(void)
{
char *line = NULL;
ssize_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("readline error\n");
		exit(EXIT_FAILURE);
	}
}
return (line);
}


/**
 *split_line - Convert string to tokens
 *@str: Input string
 *Return: Array of tokens
 */
#define BUFSIZE 64
#define DELIM " \t\r\n\a:"

char **split_line(char *line)
{

int i = 0, bufsize = BUFSIZE;
char *token;
char **tokens = malloc(sizeof(char *) * BUFSIZE);
char **tokens_backup;

if (!tokens)
{
	perror("Allocation error\n");
	exit(EXIT_FAILURE);
}

token = strtok(str, DELIM);
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

tokens[i] = NULL;
return (tokens);
}



/**
 * main - the main shell program
 * @ac: Number of arguments
 * @av: Strings containing arguments
 * Return: 0 on success code error if failure.
 */

int main(int ac, char **av)
{
char *line1;
int status;

do {
write(STDOUT_FILENO, "hsh$ ", 4);
line1 = read_line();
args = split_line(line1);
status = execute(av);
free(line);
free(av);
} while (status);

return (0);
}
