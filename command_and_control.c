#include "brain.h"


/**
 * command_and_control - a function that runs the commands
 * @path: the path to the binary file
 * @command_and_args: the commands or args
 * Return: 0 for success -1 for not
 */
int command_and_control(char *path, char **command_and_args)
{
	int child_status, path_status, exe_status;
	pid_t child_pid;
	struct stat st;

	path_status = stat(path, &st);
	if (path_status == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Something went wrong during process creation\n");
			return (-1);
		}
		if (child_pid == 0)
		{
			exe_status = execve(path, command_and_args, environ);
			if (exe_status == -1)
			{
				perror("Error: command does not exist");
				return (-1);
			}
		}
		else
		{
			waitpid(child_pid, &child_status, 0);
			if (WIFEXITED(child_status))
				return (0);
			else
				return (-1);
		}
	}
	return (-1);
}
