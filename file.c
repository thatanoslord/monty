#include "monty.h"
/*
 * read_file - reads file content
 * @name: name of the file
 * Return: file pointer to the stream data
 */

FILE *read_file(char *name)
{
	FILE *data;

	data = fopen(name, "r");

	if (!data)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}

	return (data);
}
