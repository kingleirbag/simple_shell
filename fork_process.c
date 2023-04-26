#include "main.h"

/**
 * fork_process - Creates a child process.
 * @path_val: Array of strings with possible paths for execution.
 * @prgrm_nme: Array of strings with name of the program being executed.
 * @envp: Environment for the executed program.
 * @cmd_ln: String variable representing command line input entered.
 * @prcs_id: Variable that represents the process ID of current process.
 * @checker: Boolean flag that indicates whether path_val array
 * was dynamically allocated and needs to be freed.
 *
 * Return: 0(Always).
 */
int fork_process(char **path_val, char **prgrm_nme, char **envp,
		char *cmd_ln, int prcs_id, int checker)
{
	pid_t child_process;
	int exit_status;
	char *error_format = "%s: %d: %s: not found\n";

	child_process = fork();

	if (child_process == 0)
	{
		if (execve(path_val[0], path_val, envp) == -1)
		{
			fprintf(stderr, error_format, prgrm_nme[0], prcs_id, path_val[0]);
			if (!checker)
			{
				free(path_val[0]);
			}
			free(path_val);
			free(cmd_ln);
			exit(errno);
		}
	}
	else
	{
		wait(&exit_status);
		if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) != 0)
		{
			return (WEXITSTATUS(exit_status));
		}
	}
	return (0);
}
