#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @head: first node of the list.
 * @line: Is count of lines.
 */
void _add(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	temp2 = (*head)->next;
	temp2->n += temp->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
