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
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("Error getline\n");
		exit(EXIT_FAILURE);
	}
}
return (line);
}






