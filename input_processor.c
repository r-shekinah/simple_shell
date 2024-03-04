#include "brain.h"

/**
 * token_processing - a buffer processor and tokenizer
 * @str: the string
 * @delim: the delim to break with
 * Return: an array of string containg the str
 */
char **token_processing(char *str, char *delim)
{
	char *buffer;
	char *found;
	char *temp;
	char **buffer_arr;
	int count;

	count = 0;
	buffer = malloc(strlen(str) + 1);
	if (buffer == NULL)
		return (NULL);
	strcpy(buffer, str);

	found = strtok(buffer, delim);

	while (found)
	{
		count++;
		found = strtok(NULL, delim);
	}
	buffer_arr = malloc(sizeof(char *) * (count + 1));
	if (buffer_arr == NULL)
	{
		return (NULL);
	}
	strcpy(buffer, str);
	found = strtok(buffer, delim);
	count = 0;
	while (found)
	{
		temp = malloc(strlen(found) + 1);
		/*if (count > 0)
		{
			for (i = 0; i < alloced; i++)
			{
				isequal = strcmp(buffer_arr[i], found);
				if (isequal == 0)
				{
					dont_add = 1;
					break;
				}
			}
		}
		if (dont_add == 1)
		{
			free(temp);
			dont_add = 0;
		}*/
		strcpy(temp, found);
		buffer_arr[count] = temp;
		count++;
		found = strtok(NULL, delim);
	
	}
	buffer_arr[count] = NULL;
	free(buffer);
	return (buffer_arr);
}
