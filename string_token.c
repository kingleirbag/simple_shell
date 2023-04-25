#include "main.h"

/**
 * string_token - splits the first string into tokens
 * @str: String to tokenize.
 * @str_delim: Delimiter string.
 *
 * Return: String.
 **/
char *string_token(char *str, const char *str_delim)
{
	static char *token;

	if (str)
	{
		token = str;
	}
	else if (!token)
	{
		return (0);
	}
	str = token + compute_string_segment(token, str_delim);
	token = str + compute_string_segment_str1(str, str_delim);
	if (token == str)
	{
		return (token = 0);
	}
	token = *token ? *token = 0, token + 1 : 0;
	return (str);
}
