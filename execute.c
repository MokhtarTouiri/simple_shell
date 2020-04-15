#include "shell.h"

/**
 *launch - function exec command
 *@cmd: command
 *@av: arguments
 *Return: Always returns 1 on success.
 */

int launch(char *cmd, char **av)
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


/**
 *execute - execute buitin function or user one
 *@av: arguments
 *Return: 1 to repeat prompt 0 to exit
 */

int execute(char **av)
{
char *cmd = av[0], *btin_cmd[] = {"env", "exit"};

if (cmd == NULL)
	return (1);

if (strcmp(cmd, btin_cmd[0]) == 0)
{
	new_env();
	return (1);
}
else if (strcmp(cmd, btin_cmd[1]) == 0)
{
	new_exit();
	return (1);
}
else
{
	return (launch(cmd, av));
}
}
