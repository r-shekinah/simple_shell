#include "brain.h"
/**
 * path_handle - a function that handles a path to cmd
 * @buffer: contains the path + command
 * Return: 0
 */

int path_handle(char *buffer)
{
	char **ret_tokens;
	int beacon, i, ret;

	ret_tokens = token_processing(buffer, " ");
	i = 0;
	while (ret_tokens[i] != NULL)
	{
		ret = access(ret_tokens[i], F_OK);
		if (ret == 0)
			beacon = command_and_control(ret_tokens[i], ret_tokens);
		i++;
	}
	free_memory(ret_tokens);
	return (beacon);
}
