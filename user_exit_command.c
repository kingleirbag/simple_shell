#include "main.h"

/**
 * user_exit_command - Closes the prompt when the exit command is passed.
 * @alloc_mem: Pointer to the allocated memory.
 * @input_cmd: User input command.
 * @exit_cmd: The exit value.
 */
void user_exit_command(char **alloc_mem, char *input_cmd, int exit_cmd)
{
	int exit_status = 0;

	if (!alloc_mem[1])
	{
		free(input_cmd);
		free(alloc_mem);
		exit(exit_cmd);
	}
	exit_status = atoi(alloc_mem[1]);

	free(input_cmd);
	free(alloc_mem);
	exit(exit_status);
}
