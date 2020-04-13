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
 * @s: char to convert to an int
 * Return: int @out
*/

int _atoi(char *s)
{
	int i = 0;
	int j;
	int sign = -1;
	int out = 0;

	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i++;
	for (j = 0; j < i; j++)
	{
		if (s[j] == '-')
			sign = sign * -1;
		if ((s[j] >= '0') && (s[j] <= '9'))
			break;
	}
	for (j = 0; j < i; j++)
	{
		if ((s[j] >= '0') && (s[j] <= '9') && (s[j] != '\0'))
			{
			out = (out * 10) - (s[j] - '0');
			if ((s[j + 1] < '0') || (s[j + 1] > '9'))
				break;
			}
	}
	out = out * sign;
	return (out);
}
