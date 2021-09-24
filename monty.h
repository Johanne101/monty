#ifndef MONTILIB_H
#define MONTILIB_H

#define  _GNU_SOURCE

/* LIST OF LIBRARIES BELOW */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/* DOUBLY LINKED LIST STRUCT BELOW */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* FUNCTION POINTER STRUCT BELOW */

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Monty Commands Functions */

void _pall(stack_t **head, unsigned int line);
void _pint(stack_t **head, unsigned int line);
void _pop(stack_t **head, unsigned int line);
void _swap(stack_t **head, unsigned int line);
void _nop(stack_t **head, unsigned int line);

/* AUXILIARY FUNCTIONS BELOW */

void checkBuffer(FILE *fd, char *buffer);
int _isanum(char *token, unsigned int line);

/* LINKED FUNCTIONS BELOW */

stack_t *addNode(stack_t **head, const int n);
void freeList(stack_t *head);
size_t list_len(stack_t *h);

/* MATH FUNCTIONS BELOW */

void _add(stack_t **head, unsigned int line);
void _sub(stack_t **head, unsigned int line);
void _mul(stack_t **head, unsigned int line);
void _div(stack_t **head, unsigned int line);

/* GET OP FUNCTION BELOW */

void (*getOp(char *token))(stack_t **head, unsigned int line);

#endif /* MONTYLIB_H */
