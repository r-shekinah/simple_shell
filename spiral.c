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
	if (input_status == 1)
	{
		while (1)
		{
			printf("$ ");
			status = getline(&buffer, &count, stdin);
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
			for (index = 0; *(buffer + index) != '\n'; index++)
			{
				if (*(buffer + index) == ' ' || *(buffer + index) == '\n')
					there_was_space = 1;
				else
				{
					there_was_space = 0;
					strtok(buffer, "\n");
				}
				if (there_was_space == 0)
				{
					if (*(buffer + index) == '/' || *(buffer + index) == '.')
					{
						beacon = path_handle(buffer);
						if (beacon == 0)
							break;
					}
					if (*(buffer + index) != ' '  && *(buffer + index) != '/')
						command_handle(buffer);
					index++;
				}
			}
			free(buffer);
		}
	}
	if (input_status == 0)
	{
		status = getline(&buffer, &count, stdin);
		non_interactive_handle(buffer);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
