#include "brain.h"

/**
 * command_handle - a function that processes the commands
 * @command: the user passed command
 * Return: 0 for sccess -1 for not
 */
int command_handle(char *command)
{
	char *dummy, *path_to_env, *command_first, *path_and_command;
	int index, beacon;
	char **ret_tokens_path, **ret_tokens_command;

	index = 1;
	path_to_env = getenv("PATH");
	dummy = malloc(sizeof(char) * strlen(path_to_env) + 1);
	if (dummy == NULL)
		return (-1);
	strcpy(dummy, path_to_env);
	ret_tokens_path = token_processing(dummy, ":");
	ret_tokens_command = token_processing(command, " ");
	command_first = ret_tokens_command[0];
	while (ret_tokens_path[index] != NULL)
	{
		path_and_command = malloc(sizeof(char) *
				strlen(*(ret_tokens_path + index)) + strlen(command_first) + 2);
		if (path_and_command == NULL)
			return (-1);
		strcpy(path_and_command, *(ret_tokens_path + index));
		strcat(path_and_command, "/");
		strcat(path_and_command, command_first);
		beacon = command_and_control(path_and_command, ret_tokens_command);
		if (beacon == 0)
		{
			free_memory(ret_tokens_path);
			free_memory(ret_tokens_command);
			free(path_and_command);
			free(dummy);
			return (0);
		}
		free(path_and_command);
		index++;
	}
	free_memory(ret_tokens_path);
	free_memory(ret_tokens_command);
	free(path_and_command);
	free(dummy);
	return (-1);
}
