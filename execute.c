#include "shell.h"

/**
 *execute - function exec command
 *@cmd: command
 *@av: arguments
 *Return: Always returns 1 on success.
 */

int execute(char *cmd, char **av)
{
pid_t pid;
int s;

pid = fork();
if (pid == 0)
{
	signal(SIGINT, SIG_DFL);
	if (execve(cmd, av, environ) < 0)
	{
		return (-1);
		exit(EXIT_FAILURE);
	}
}
else
	wait(&s);
return (1);
}
