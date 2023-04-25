#include "main.h"

/**
 * compare_string - compare two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: 0.
 */
int compare_string(char *s1, char *s2)
{
	int counter;

	for (counter = 0; s1[counter] != '\0' && s2[counter] != '\0'; counter++)
	{
		if (s1[counter] != s2[counter])
		{
			return ((int)s1[counter] - s2[counter]);
		}
	}
	return (0);
}
