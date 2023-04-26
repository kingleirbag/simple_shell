#include "main.h"

/**
 * retrieve_token - Takes a string user_input as input.
 * @user_input: Pointer to a character, which points
 * to a string of characters entered by the user.
 *
 * Return: Pointer to a char pointer which contains
 * the tokenized user input.
 */
char **retrieve_token(char *user_input)
{
	char **user_cmd = NULL, *user_token = NULL;
	int string_size = 0;
	size_t counter = 0;

	if (user_input == NULL)
	{
		return (NULL);
	}

	for (counter = 0; user_input[counter]; counter++)
	{
		if (user_input[counter] == ' ')
		{
			string_size++;
		}
	}
	if ((string_size + 1) == string_length(user_input))
	{
		return (NULL);
	}
	user_cmd = malloc(sizeof(char *) * (string_size + 2));
	if (user_cmd == NULL)
	{
		return (NULL);
	}

	user_token = string_token(user_input, " \n\t\r");
	for (counter = 0; user_token != NULL; counter++)
	{
		user_cmd[counter] = user_token;
		user_token = string_token(NULL, " \n\t\r");
	}
	user_cmd[counter] = NULL;
	return (user_cmd);
}
