#include "main.h"

/**
 * string_length - Takes a pointer to a string
 * and returns the length of string as integer value.
 * @str:  Pointer to a character array.
 * Return: value of the counter (length).
 */
int string_length(char *str)
{
	int length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}
