#include "brain.h"


/**
 * free_memory - given an array free it
 * @ptr: a pointer to the string
 * Return: 0 on success
 */
int free_memory(char **ptr)
{
	int index;

	for (index = 0; ptr[index]; ++index)
	{
		free(ptr[index]);
	}
	free(ptr);
	return (0);
}
