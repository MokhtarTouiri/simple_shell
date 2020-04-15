#include "shell.h"

/**
 * backupmain - the main shell program
 * Return: 0 on success code error if failure.
 */

int backupmain(void)
{
char *cmd, *line = NULL, **av = NULL;
size_t bufsize = 0;
int c, status = 1;

signal(SIGINT, SIG_DFL);

do {
av = NULL;
if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "MCshell$ ", 10);


if (getline(&line, &bufsize, stdin) < 0)
{
	free(line);
	line = NULL;
	write(STDIN_FILENO, "error\n", 6);
	break;
}

av = split_line(line);

if (av == NULL || *av == NULL)
	continue;

cmd = av[0];

c = execute(cmd, av);

if (strcmp(cmd, "exit") != 0)
        continue;

if (c < 0)
{
	free_av(av);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 13);
	exit(EXIT_FAILURE);
}
} while (status);
return (0);
}
