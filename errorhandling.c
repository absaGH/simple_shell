#include "shell.h"

/**
 * print_e - produces output of simple_shell
 * @av: pointer arrays for free
 * @buffer: pointer arrays for free
 * @cont: integer point
 * Return: void
 */

int print_e(char *av, char *buffer, unsigned int cont)
{
	char *count;

	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	count = _uitos(cont);
	write(STDERR_FILENO, count, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, _strlen(buffer));
	write(STDERR_FILENO, ": No such file or directory/n", 27);
	free(count);
	return (127);
}

/**
 * _uitos - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */

char *_uitos(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
