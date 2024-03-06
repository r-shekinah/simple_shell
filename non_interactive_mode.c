#include "brain.h"



int non_interactive_handle(char *buffer)
{
	int index, space, isexit;
	char *buffer_copy;

	buffer_copy = malloc(strlen(buffer) + 1);

	if (buffer_copy ==  NULL)
		return (-1);

	strcpy(buffer_copy, buffer);
	strtok(buffer_copy, "\n");
	isexit = strcmp(buffer_copy, "exit");
	if (isexit == 0)
	{
		free(buffer_copy);
		exit(EXIT_SUCCESS);
	}
	for (index = 0; *(buffer + index) != '\n'; index++)
	{
		if (*(buffer + index) == ' ' || *(buffer + index) == '\n')
			space = 1;
		else
			space = 0;

		if (space == 0)
		{
			strtok(buffer, "\n");
			index = 0;
			if (*(buffer + index) == '/' || *(buffer + index) == '.')
				path_handle(buffer);
			else
				command_handle(buffer);
			break;
		}
		free(buffer);
	}
	return (0);
}
