#include "shell.h"

/**
*_strchr -  locates a character in a string. (0x09)
*overwriting the terminating null byte (\0) at the end of dest, and then adds a
*terminating null byte.
*
*@s: Pointer to the array.
*@c: A char byte to look for.
*Return: Returns a pointer to the first occurrence of the character c in the
*string s, or NULL if the character is not found
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
		{
			return (s);
		}
	} while (*s++);
	return (0);
}

/**
 * _strcat - concate 2 strings (0x09)
 * @src: parameter
 * @dest: parameter
 *
 * Return: string
 */
char *_strcat(char *dest, char *src)
{
int i;
int l;
for (l = 0; dest[l] != '\0'; l++)
{
}
for (i = 0; src[i] != '\0'; i++)
{
dest[l + i] = src[i];
}
dest[l + i] = '\0';
return (dest);
}

/**
 * _atoi - that convert a string to an integer. (0x09)
 * @s: string to convert to an int
 * Return: int @out
*/


int _atoi(char *s)
{
int i, sign = 1, n = 0, r;

for (i = 0; s[i] != '\0';)
{
	if (s[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}

	else if ((s[i] >= '0') && (s[i] <= '9'))
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	else
	i++;
}
r = sign * n;
return (r);
}
