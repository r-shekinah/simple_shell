#include "brain.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	int status, isexit, input_status, there_was_space, beacon;
	size_t count, index;
	input_status = isatty(0);
	if (input_status == 1)
	{
		while (1)
		{
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
			for (index = 0; index < strlen(buffer); index++)
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
						if (beacon == 0)
							break;
					}
					else
					{
						beacon = command_handle(buffer);
						if (beacon == 0)
							break;
					}
				}
			}
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
