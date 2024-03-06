#include "brain.h"



int non_interactive_handle(char *buffer)
{
	int index, space;
	char **ret_tokens;

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
			{
				ret_tokens = token_processing(buffer,  " ");
				while (*(ret_tokens + index) != NULL)
				{
					command_and_control(ret_tokens[index], ret_tokens);
					index++;
				}
				free_memory(ret_tokens);
				return (0);
			}
			else
				command_handle(buffer);
			break;
		}
	}
	return (0);
}
