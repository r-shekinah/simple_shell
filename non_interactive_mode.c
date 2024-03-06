#include "brain.h"



int non_interactive_handle(char *buffer)
{
	int index, space, beacon;

	for (index = 0; *(buffer + index) != '\n'; index++)
	{
		if (*(buffer + index) == ' ' || *(buffer + index) == '\n')
			space = 1;
		else
			space = 0;

		if (space == 0)
		{
			strtok(buffer, "\n");
			if (*(buffer + index) == '/' || *(buffer + index) == '.')
			{
				beacon = path_handle(buffer);
				if (beacon == 0)
					break;
			}
			else
				command_handle(buffer);
			break;
		}
	}
	return (0);
}
