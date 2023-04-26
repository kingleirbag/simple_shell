#include "main.h"

/**
 * concat_string - Function that concatenate the contents of
 * source onto the end of destination.
 * @destination: string to be copied to.
 * @source: string that will be copied from.
 * Return: A pointer to the concatenated string.
 */
char *concat_string(char *destination, char *source)
{
	int destination_counter = 0;
	int source_counter = 0;

	while (destination[destination_counter] != '\0')
	{
		destination_counter++;
	}
	while (source[source_counter] != '\0')
	{
		destination[destination_counter] = source[source_counter];
		destination_counter++;
		source_counter++;
	}
	destination[destination_counter] = '\0';
	return (destination);
}
