#include "main.h"

/**
 * compare_string - Compares two strings
 * up to a specified number of characters.
 *
 * @string1: Pointer to string 1.
 * @string2: Pointer to string 2.
 * @nchar: The max number of characters to be compared.
 *
 * Return: The result of the comparison.
 */
size_t compare_nchar_string(char *string1, char *string2, size_t nchar)
{
	size_t compare_value, counter;

	for (counter = 0; string1[counter] != '\0' && counter < nchar; counter++)
	{
		compare_value = string1[counter] - string2[counter];
		if (compare_value != 0)
		{
			return (compare_value);
		}
	}
	return (0);
}
