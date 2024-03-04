#include "brain.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	int status, isexit, index, input_status, there_was_space, beacon;
	size_t count;

	input_status = isatty(0);
	while (1)
	{
		if (input_status == 1)
			printf("$ ");
		status = getline(&buffer, &count, stdin);
		strtok(buffer, "\n");
		isexit = strcmp(buffer, "exit");
		if (isexit == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (status == EOF)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			for (index = 0; *(buffer + index) != '\n'; index++)
			{
				if (*(buffer + index) == ' ' || *(buffer + index) == '\n')
					there_was_space = 1;
				else
					there_was_space = 0;
				if (there_was_space == 0)
				{
					if (*(buffer + index) == '/' || *(buffer + index) == '.')
					{
						beacon = path_handle(buffer);
					}
					else
						beacon = command_handle(buffer);
					break;
				}
			}
		}
		if (input_status == 0)
		{
			free(buffer);
			if (beacon == 0)
				exit(EXIT_SUCCESS);
			else
				exit(EXIT_FAILURE);
		}
	}
	return (0);
}
