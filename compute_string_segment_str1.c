#include "main.h"

/**
 * compute_string_segment_str1 - Locate different characters.
 * @str1: string1.
 * @str2: string 2.
 * Return: Computed difference.
 */
size_t compute_string_segment_str1(const char *str1, const char *str2)
{
	size_t counter = 0;

	while (*str1)
	{
		if (character_occurence(str2, *str1))
		{
			return (counter);
		}
		str1++, counter++;
	}
	return (counter);
}
