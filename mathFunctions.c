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

	temp = *head; /* Take the first node addrs */
	temp2 = (*head)->next; /* take next node addrs */
	temp2->n += temp->n; /* Add first value to the second node val */
	*head = (*head)->next; /* Move head to the next node (temp2 pos */
	(*head)->prev = NULL; /* Make prev node, after moving head, null */
	free(temp); /* Free temp who was first node */
}


/**
 *_sub - will substract a value from another one
 *@head: is the first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _sub(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *head; /* Take the addrs of the next node */
	(*head)->next->n -= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 *_mul - will multiply the first two nodes
 *@head: is the first node of the stack
 *@line: is the number of the line
 *Return: will return nothing (void)
 */


void _mul(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL || list_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	(*head)->next->n *= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}
