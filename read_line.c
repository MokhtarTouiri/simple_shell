#include "shell.h"

/**
 *read_line - read a input line from user
 *
 *Return: pointer on readed line.
 */

char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;

if (getline(&line, &bufsize, stdin) < 0)
{
	free(line);
	line = NULL;
	write(STDIN_FILENO, "\n", 1);
}

return (line);
}
