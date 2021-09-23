#include "montyLib.h"

/**
 *getOp - will get one of the function listed
 *@token: this token should be the comand after "push" and "int"
 *Return: will return a pointer to a function
 */

void (*getOp(char *token))(stack_t **head, unsigned int line)
{
	instruction_t funLst[] = {
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		/*{"add", _add},
		{"sub", _sub},
		{"div",  _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},*/
		{NULL, NULL}
	};

	int index = 0;

	while (funLst[index].f != NULL)
	{
		if (strcmp(token, funLst[index].opcode) == 0)
		{
			return (funLst[index].f);
		}
		index++;
	}
	return (NULL);
}
