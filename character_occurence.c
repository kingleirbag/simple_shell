#include "main.h"

/**
 * character_occurence - A Function that searches for the
 * first occurrence of a specified character in a string.
 *
 * @chtr: The character to be searched for.
 * @str: A pointer to the string to be searched.
 *
 * Return: Pointer to location of character in the string.
 */
char *character_occurence(const char *str, int chtr)
{
	while (*str != (char)chtr)
	{
		if (!*str++)
		{
			return (0);
		}
	}
	return ((char *)str);
}
