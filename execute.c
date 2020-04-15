#include "shell.h"

/**
 *launch - function start prompt.
 *@av: arguments.
 *Return: Always returns 1.
 */

int launch(char **av)
{
pid_t pid;
int s;

pid = fork();
if (pid == 0)
{
	if (execvp(av[0], av) == -1)
	{
		perror("MChsh Error");
	}
	exit(EXIT_FAILURE);
}
else if (pid < 0)
	perror("MChsh Error");
else
{
do {
	waitpid(pid, &s, WUNTRACED);
} while (!WIFEXITED(s) && !WIFSIGNALED(s));
}
return (1);
}


/**
 *execute - function command Shell
 *@av: arguments
 *Return: 0 to exit, 1 to continue.
 */

int execute(char **av)
{
int i;
char *cmd[] = { "env", "exit" };

if (av[0] == NULL)
{
	return (1);
}

for (i = 0; i < 2; i++)
{
	if (strcmp(av[0], cmd[i]) == 0)
	{
	}
}

return (launch(av));
}
