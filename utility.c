#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */

unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcmp - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */

int _strcmp(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */

ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}

	return (len);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of str.
 * @str: string
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int x, y;
	char *copy = NULL;

	x = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	else
	{
		while (str[x] != '\0')
		{
			x++;
		}
	}
	copy = malloc(sizeof(char) * (x + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	else
	{
		for (y = 0; str[y] != 0; y++)
		{
			copy[y] = str[y];
		}
		copy[y] = '\0';
	}
	return (copy);
}
