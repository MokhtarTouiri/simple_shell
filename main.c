#include "shell.h"

/**
 * main - the main shell program
 * Return: 0 on success code error if failure.
 */

int main(void)
{
char *line = NULL, *cmd = NULL, **av = NULL;
size_t bufsize = 0;
int code =0, status = 1;

signal(SIGINT, SIG_DFL);

do {
free(av);
av = NULL;
if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "MCshell$ ", 10);

if (getline(&line, &bufsize, stdin) < 0)
{
	free(line);
	line = NULL;
	write(STDIN_FILENO, "\n", 1);
	break;
}

av = split_line(line);

if (av == NULL || *av == NULL)
	continue;

cmd = av[0];

if ((strcmp(cmd, "exit")) == 0)
{
	if (av[1] != NULL)
        	code = _atoi(av[1]);
	free(cmd),  exit(code);
	break;
}

if (execute(cmd, av) < 0)
{
	mem_free(av);
	perror("error");
	exit(127);
}
} while (status);
return (0);
}

