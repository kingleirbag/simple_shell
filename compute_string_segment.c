#include "main.h"

/**
 * compute_string_segment - Checking if each character in
 * first string is present in the second string.
 * @str1: First string.
 * @str2: Second string.
 * Return: If a character is encountered that is present
 * in the second string, it returns the number of
 * characters that were iterated through before that point.
 */
size_t compute_string_segment(const char *str1, const char *str2)
{
	size_t counter = 0;

	while (*str1 && character_occurence(str2, *str1++))
	{
		counter++;
	}
	return (counter);
}
