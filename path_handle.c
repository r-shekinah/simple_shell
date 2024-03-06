#include "brain.h"
/**
 * path_handle - a function that handles a path to cmd
 * @buffer: contains the path + command
 * Return: 0
 */

int path_handle(char *buffer)
{
	char **ret_tokens;
	int beacon, ret, idx;

	ret_tokens = token_processing(buffer, " ");
	for (idx = 0; ret_tokens[idx] != NULL; idx++)
	{
		ret = access(ret_tokens[idx], F_OK);
		if (ret == 0)
			beacon = command_and_control(ret_tokens[idx], ret_tokens);
	}
	free_memory(ret_tokens);
	return (beacon);
}
