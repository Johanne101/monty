#include "monty.h"

/*
 * _add - Adds the top two elements of the stack.
 * @head: first node of the list.
 * @line: Is count of lines.
 */
void _add(stack_t **head, unsigned int line)
{
	int sum;

	if ((*head == NULL) || ((*head)->next->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short", line);
			exit(EXIT_FAILURE);
	}
	sum = (*head)->n;
	(*head) = (*head)->next;
	(*head)->n += sum;
	free((*head)->prev);
	(*head)->prev = NULL;
	

}
