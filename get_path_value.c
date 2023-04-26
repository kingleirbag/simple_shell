#include "main.h"

/**
 * get_path_value - Trys to find the full path to a command stored.
 * @path: Path variable.
 * @envp: Environment varibale.
 * Return: Path value.
 */
int get_path_value(char **path, char **envp)
{
	char *absolute_path = NULL, *token_value = NULL, *relative_path = NULL;
	size_t value_path, cmd;
	struct stat stat_cmd;

	if (stat(*path, &stat_cmd) == 0)
	{
		return (-1);
	}
	relative_path = get_environment_path(envp);
	if (!relative_path)
	{
		return (-1);
	}
	token_value = string_token(relative_path, ":");
	cmd = string_length(*path);
	while (token_value)
	{
		value_path = string_length(token_value);
		absolute_path = malloc(sizeof(char) * (value_path + cmd + 2));
		if (!absolute_path)
		{
			free(relative_path);
			return (-1);
		}
		absolute_path = copy_string(absolute_path, token_value);
		concat_string(absolute_path, "/");
		concat_string(absolute_path, *path);

		if (stat(absolute_path, &stat_cmd) == 0)
		{
			*path = absolute_path;
			free(relative_path);
			return (0);
		}
		free(absolute_path);
		token_value = string_token(NULL, ":");
	}
	free(relative_path);
	return (-1);
}
