#include "monty.h"

/**
 *_pall - will print the nodes of the list
 *@head: will point to first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _pall(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	(void)line;

	if (head == NULL || *head == NULL)
	{
		return;
	}

	temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 *_pint - will print an integer after insert in stack
 *@head: will point to first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _pint(stack_t **head, unsigned int line)
{
	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 *_pop - will delete the first node of the list
 *@head: will point to first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _pop(stack_t **head, unsigned int line)
{
	stack_t *nodeDel;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	nodeDel = *head;

	if ((*head)->next == NULL) /* check if next node after head is null */
	{
		*head = NULL; /* Assign null to head */
		free(nodeDel); /* Free nodeDel with head prev addrs */
	}

	else
	{
		*head = (*head)->next; /* Move head to next node */
		(*head)->prev = NULL; /* Change address of prev to NULL */
		free(nodeDel); /* Free nodeDel with prev addrs of head */
	}
}

/**
 *_nop - will do nothing
 *@head: will point to first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}


/**
 *_swap - will swap two nodes except if there's only one
 *@head: will point to first node of the list
 *@line: is the count of lines
 *Return: will return nothing (void)
 */

void _swap(stack_t **head, unsigned int line)
{
	stack_t *temp, *temp2;

	if ((*head == NULL && head == NULL) || (list_len(*head) < 2))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*head)->next->next == NULL)
	{
		temp = (*head)->next; /* Get the next node */
		temp->next = *head; /* Put the addrs of head at temp next */
		temp->prev = NULL; /* Now temp is head, put prev NULL */
		*head = temp; /* Now head will be temp */
		/* Now the node who was first will point to null */
		(*head)->next->next = NULL;
	}

	else
	{
		temp = *head;
		temp2 = (*head)->next;
		temp->next = temp2->next;
		temp2->next->prev = temp;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		*head = temp2;
	}
}
