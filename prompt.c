#include "main.h"

/**
 * prompt - Displays the prompt "cisfun$ ".
 * Return: User input string.
 */
char *prompt(void)
{
	char *print_line = NULL;
	size_t character = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 8);

	if (getline(&print_line, &character, stdin) == -1)
	{
		free(print_line);
		return (NULL);
	}
	return (print_line);
}
