#include "brain.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *buffer = NULL;
	size_t count = 0;
	int status;

	printf("$ ");

	while ((status = getline(&buffer, &count, stdin)) != EOF)
	{
		strtok(buffer, "\n");
		if (buffer[0] == '/')
		{
			path_handle(buffer);
		}
		else
		{
			comand_handle(buffer);
		}
		printf("$ ");
	}
	if (status)
	{
		free(buffer);
	}
	return (0);
}
