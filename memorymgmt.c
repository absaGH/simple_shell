#include "shell.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */

char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*size) + LSH_TOK_BUFSIZE));
	if (new == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new[i] = ptr[i];
	}
	*size += LSH_TOK_BUFSIZE;
	free(ptr);

	return (new);
}

/**
 * dobfreer - free double pointer
 * @dblptr: double pointer to free
 * Return: nothing
 */

void dobfreer(char **dblptr)
{
	int count = 0;

	while (dblptr[count] != NULL)
	{
		free(dblptr[count]);
		count++;
	}
	free(dblptr);
}
