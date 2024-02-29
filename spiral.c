#include "brain.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	int status, index, input_status, path_status, child_status, there_was_space;
	pid_t child_process;
	size_t count;

	there_was_space = 0;

	input_status = isatty(0);
	if (input_status == 1)
		printf("$ ");
	while ((status = getline(&buffer, &count, stdin)) != EOF)
	{
		if (input_status == 0)
		{
			non_stdin_handle(buffer);
			return (0);
		}
		for (index = 0; *(buffer + index) != '\n'; index++)
		{
			if (*(buffer + index) == ' ' || *(buffer + index) == '\n')
				there_was_space = 1;
			else
				there_was_space = 0;
			if (there_was_space == 0)
			{
				strtok(buffer, "\n");
				if (*(buffer + index) == '/')
					path_handle(buffer);
				else
					command_handle(buffer);
				break;
			}
		}
		printf("$ ");
	}
	if (status == EOF)
		free(buffer);
	return (0);
}
