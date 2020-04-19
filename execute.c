#include "shell.h"



/**
 * execute_bl_in - Builtin command management
 *@cmd: command builtin
 * Return: Return 1 if success.
 */

int execute_bl_in(char **av, char *line)
{
int c = 0;
if ((strcmp(av[0], "exit") == 0) && av[1] == NULL)
{
	free(line), free(av), exit(0);
	return (1);
}

if ((strcmp(av[0], "env") == 0) && av[1] == NULL)
{
	while (environ[c])
	{
		write(STDOUT_FILENO, environ[c], _strlen(environ[c]));
		write(STDOUT_FILENO, "\n", 1);
		c++;
	}
	return (1);
}

return (0);
}














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
