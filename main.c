#include "main.h"

/**
 * main - Entry point of the program.
 * @acounter: Integer that represents the number
 * of arguments passed to the program.
 *
 * @avector: Pointer to an array of strings representing
 * command-line arguments passed to program.
 *
 * @env: Pointer to an array of strings representing
 * the environment variables.
 *
 * Return: Always 0.
 */
int main(int acounter, char **avector, char **env)
{
	char *get_prompt = NULL, **input_cmd = NULL;
	int counter = 0, path_value = 0, user_exit = 0;
	(void)acounter;

	while (1)
	{
		get_prompt = prompt();
		if (get_prompt)
		{
			path_value++;
			input_cmd = retrieve_token(get_prompt);
			if (!input_cmd)
			{
				free(get_prompt);
				continue;
			}
			if ((!compare_string(input_cmd[0], "exit")) && input_cmd[1] == NULL)
				user_exit_command(input_cmd, get_prompt, user_exit);
			if (!compare_string(input_cmd[0], "env"))
				get_environment(env);
			else
			{
				counter = get_path_value(&input_cmd[0], env);
				user_exit = fork_process(input_cmd, avector, env,
						get_prompt, path_value, counter);
				if (counter == 0)
					free(input_cmd[0]);
			}
			free(input_cmd);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(user_exit);
		}
		free(get_prompt);
	}
	return (user_exit);
}
