#include "brain.h"


/**
 * non_stdin_handle - this function handles the
 * non stdin input
 * @buffer: the input string
 * Return: 0 on sucess -1 on failure
 */
int non_stdin_handle(char *buffer)
{
	char **ret_path;
	unsigned int index;
	pid_t child_pid;
	int child_status;

	strtok(buffer, "\n");
	ret_path = token_processing(buffer, " ");
	for (index = 0; *(ret_path + index) != NULL; index++)
		path_handle(*(ret_path + index));
	free_memory(ret_path);
	return (0);
}
