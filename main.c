#include "shell.h"

/**
 * main - the main shell program
 * Return: 0 on success code error if failure.
 */

int main(void)
{
char *line = NULL, **av = NULL;
char *cmd = NULL, *btin_cmd[] = {"env", "exit"};
size_t bufsize = 0;

signal(SIGINT, SIG_DFL);

while (1)
{
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
if ((strcmp(cmd, btin_cmd[0]) == 0) && (av[1] == NULL))
	new_env();
else if ((strcmp(cmd, btin_cmd[1]) == 0) && (av[1] == NULL))
	new_exit();
else if (execute(av) < 0)
{
	mem_free(av);
	perror("error");
	exit(127);
}
}
return (0);
}

