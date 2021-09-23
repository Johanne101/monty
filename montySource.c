#include "monty.h"

/**
 *main - it's supposed to accept arguments and process files
 *@argc: will count arguments so we can hadle the arguments better
 *@argv: will point to an array of strings (arguments)
 *Return: will return 0 at the end if succcess or just exit if failed
 */

int main(int argc, char *argv[])
{
	FILE *fd;
	char *buffer;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	checkBuffer(fd, buffer);
	free(buffer);
	fclose(fd);
	return (0);
}
