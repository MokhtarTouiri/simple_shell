#include "shell.h"

/**
 *read_line_backup - read a input line from user
 *
 *Return: pointer on readed line.
 */

char *read_line_backup(void)
{

#define RL_BUFSIZE 1024
int bufsize = RL_BUFSIZE;
int i = 0;
char *buffer = malloc(sizeof(char) * bufsize);
int c;

if (!buffer)
{
	perror("Allocation error\n");
	exit(EXIT_FAILURE);
}


while (1) {
c = getchar();
if (c == EOF) {
exit(EXIT_SUCCESS);
}
 else if (c == '\n')
{
	buffer[i] = '\0';
	return (buffer);
}
 else
{
	buffer[i] = c;
}
i++;

if (i >= bufsize)
{
	bufsize += RL_BUFSIZE;
	buffer = realloc(buffer, bufsize);
	if (!buffer)
	{
		perror("Allocation error\n");
        	exit(EXIT_FAILURE);
	}
}
}
}






