#include "main.h"

/**
 * get_environment_path - Function that gets the
 * path of the environment variable.
 * @envp: The environment variable.
 * Return: Environment path value.
 */
char *get_environment_path(char **envp)
{
	size_t counter = 0, path_var = 0, path_counter = 5;
	char *env_path = NULL;

	for (counter = 0; compare_nchar_string(envp[counter], "PATH=", 5); counter++)
		;
	if (envp[counter] == NULL)
	{
		return (NULL);
	}
	for (path_counter = 5; envp[counter][path_var]; path_var++, path_counter++)
		;
	env_path = malloc(sizeof(char) * (path_counter + 1));

	if (env_path == NULL)
	{
		return (NULL);
	}

	for (path_var = 5, path_counter = 0; envp[counter][path_var];
			path_var++, path_counter++)
	{
		env_path[path_counter] = envp[counter][path_var];
	}

	env_path[path_counter] = '\0';
	return (env_path);
}
