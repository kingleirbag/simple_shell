#include "main.h"

/**
 * get_environment - A function that takes in the envp argument.
 * @envp: Environment variable.
 *
 * Return: Void.
 */
void get_environment(char **envp)
{
	size_t run_counter = 0;

	while (envp[run_counter])
	{
		write(STDOUT_FILENO, envp[run_counter], string_length(envp[run_counter]));
		write(STDOUT_FILENO, "\n", 1);
		run_counter++;
	}
}
