#include "shell.h"

/**
 * new_exit - Builtin command exit
 *
 * Return: Always 0.
 */

int new_exit(void)
{
	exit(EXIT_SUCCESS);
}



/**
 * new_env - Builtin command env
 *
 * Return: Return 1 if success.
 */

void new_env(void)
{
int c = 0;
while (environ[c])
{
	write(STDOUT_FILENO, environ[c], _strlen(environ[c]));
	write(STDOUT_FILENO, "\n", 1);
	c++;
}

}

/**
 * execute_bl_in - Builtin command management
 *@av: arguments
 * Return: Return 1 if success.
 */

int execute_bl_in(char **av)
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
return (0);
}
