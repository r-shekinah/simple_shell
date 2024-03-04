#include "brain.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	int status, isexit, index, input_status, there_was_space;
	size_t count;
	input_status = isatty(0);
	if (input_status == 1)
	{
		while (1)
		{
			printf("$ ");
			status = getline(&buffer, &count, stdin);
			strtok(buffer, "\n");
			
			/*isenv = strcmp(buffer, "env");*/
			/*if (isenv == 0)
			{
				for (env_index = 0; *(environ + env_index) != NULL; env_index++)
				{
					printf("%s\n", *(environ + env_index));
				}
			}*/
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
					there_was_space = 0;
				if (there_was_space == 0)
				{
					if (*(buffer + index) == '/' || *(buffer + index) == '.')
					{
						path_handle(buffer);
					}
					else
						command_handle(buffer);
					break;
				}
			}
		/*if (input_status == 0)
		{
			status = getline(&buffer, &count, stdin);
			non_interactive_handle(buffer);
		}*/
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
