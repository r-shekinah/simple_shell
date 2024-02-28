#include "brain.h"
/**
 * path_handle - a function that handles a path to cmd
 * @buffer: contains the path + command
 * Return: 0
 */
int path_handle(char *buffer)
{
	char **ret_tokens;
	char *path;

	ret_tokens = token_processing(buffer, " ");
	path = ret_tokens[0];
	command_and_control(path, ret_tokens);
	free_memory(ret_tokens);
	return (0);
}
