#include "monty.h"

/**
 *addNode - will add a node at the top of the list (stack)
 *@head: is the address of head and will point to the first node
 *@n: is the integer to add in the list
 *Return: will return the new node
 */

stack_t *addNode(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n; /* Give the value to new_node */
	new_node->next = *head; /* Head is NULL but later it will not */
	/* this way we can always check if there's something in the next node */
	new_node->prev = NULL;
	*head = new_node;

	if (new_node->next) /* if there's something in the next node */
	{
		new_node->next->prev = new_node;
		/* If there's something, we will put him at the bottom */
	}
	return (new_node);
}

/**
 *freeList - will free the nodes in the list
 *@head: the first node in the list
 *Return: will return nothing (void)
 */

void freeList(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * list_len - Function returns numbers of elements in a linked list.
 * @h: Pointers with string elements.
 *
 * Return: number of elements.
 */
size_t list_len(stack_t *h)
{
	size_t total_l = 0;

	while (h)
	{
		h = h->next;
		total_l++;
	}
	return (total_l);
}
