#include "shell.h"

/**
 * main - the main shell program
 * Return: 0 on success code error if failure.
 */

int main(void)
{
char *cmd, *line = NULL, **av = NULL;
__attribute__ ((unused)) int status = 1;

while (1)
{
av = NULL;
if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "#cisfun$ ", 9);

line = read_line();
av = split_line(line);

if (av == NULL || *av == NULL)
	continue;

cmd = av[0];
if (execute(cmd, av) < 0)
{
	if (strcmp(cmd, "exit") != 0)
	{
		free(av);
	}
	perror("error");
	exit(EXIT_FAILURE);
}
free(line);
}
return (0);
}
