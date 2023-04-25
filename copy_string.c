#include "main.h"

/**
 * copy_string - Function that copies a string from source to destination.
 * @destination: Destination string.
 * @source:  Source string.
 *
 * Return: Destination.
 */
char *copy_string(char *destination, char *source)
{
	int counter = 0;

	while (*(source + counter) != '\0')
	{
		*(destination + counter) = *(source + counter);
		++counter;
	}
	*(destination + counter) = *(source + counter);

	return (destination);
}
