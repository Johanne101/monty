#include "monty.h"

/**
 *_isanum - will check if the next token is a digit
 *@token: is the next token to check
 *@line: is the number of the line we are
 *Return: will return 0 if success or exit if failed
 */

int _isanum(char *token, unsigned int line)
{
	int index;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	for (index = 0; token[index] != '\0'; index++)
	{
		if (token[index] == '-')
		{
			if (isdigit(token[index + 1]) != 0)
			{
				continue;
			}
			if (isdigit(token[index + 1] == 0))
			{
				fprintf(stderr, "L%d: usage: push integer\n",
						line);
				exit(EXIT_FAILURE);
			}
		}
		if (isdigit(token[index]) != 0)
		{
			continue;
		}
		if (token[index] < '0' || token[index] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

/**
 *checkBuffer - will pass the strings one by one to a buffer and check them
 *@fd: is the input of the file to pass into the buffer
 *@buffer: will be the lines, one by one, to check and tokenize
 *Return: will return nothing (void)
 */

void checkBuffer(FILE *fd, char *buffer)
{
	char *delim = "\n\t\r ,.;:", *token = NULL;
	stack_t *head = NULL;
	unsigned int line = 1;
	size_t getSize = 1024;

	while (getline(&buffer, &getSize, fd) != EOF) /* Get a line from fd */
	{
		token = strtok(buffer, delim);
		if (token == NULL) /* If they pass an empty line */
		{
			line++; /* count the line even if is empty */
			continue; /* Get to "while" again and get a new line */
		}
		if (token[0] != '#')
		{
			if (strcmp(token, "push") == 0)
			{
				token = strtok(NULL, delim);
				_isanum(token, line);
				addNode(&head, atoi(token));
			}
			else
			{
				if (getOp(token) != 0) /*Chk if token != null*/
				{
					/* check if tok is an opFun */
					getOp(token)(&head, line);
				}
				else
				{
					/* If not then free all nodes */
					freeList(head);
					fprintf(stderr, "L%d: unknown instruction %s\n",
						line, buffer);
					exit(EXIT_FAILURE);
				}
			}
		}
		line++; /* Count a new line before get next line */
	}
	freeList(head); /* Free if done getting all lines */
}
