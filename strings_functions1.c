#include "shell.h"

/**
 * _strspn - Gets the length of substring (0x09)
 * @str: Given string
 * @accept: Substring bytes
 * Return: The number of bytes
 */
unsigned int _strspn(char *str, char *accept)
{
	unsigned int i;
	unsigned int j;
	int occurance;

	for (i = 0; str[i] != '\0'; i++)
	{
		occurance = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (str[i] == accept[j])
				occurance += 1;
		}
		if (occurance == 0)
		{
			break;
		}
	}
	return (i);
}

/**
 * _strlen - find the length of string (0x09)
 * @s: the streng to be sized
 *
 * Return: the length
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

/**
 * _strpbrk - searches a string fir any of set of bytes (0x09)
 * @str: Given string
 * @accept: Substring set of bytes
 *
 * Return: A pointer to the byte in @str
 */


char *_strpbrk(char *str, char *accept)
{
	int i;
	int occur;

	while (*str != '\0')
	{
		occur = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*str == accept[i])
				occur += 1;
		}
		if (occur > 0)
			break;
		str++;
	}
	if (*str == '\0')
		return (NULL);
	return (str);
}

/**
 * _strdup - copy of the string (0x0B)
 * @str: string to copy
 * Return: d.
*/
char *_strdup(char *str)
{
int i = 0, j;
char *d;

if (str == NULL)
	return (NULL);

while (str[i] != '\0')
	i++;

d = malloc(i * sizeof(char));

if (d == NULL)
	return (NULL);

for (j = 0; j < i; j++)
	d[j] = str[j];

return (d);

}

/**
 * _strcmp - compare 2 strings
 * @s1: parameter
 * @s2: parameter
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}


