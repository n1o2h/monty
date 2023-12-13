#include "monty.h"

int is_number(char *str);

/**
 * exec - execute command
 * @cmd: command
 * @line_number: number
 * @format: the format of the data
 * Return: 0 on sucess.
 */

int exec(char **cmd, unsigned int line_number, char *format)
{
	int i = 0, found = 0;
	stack_t *node;
	instruction_t inst[] = {
		{"push", _nop},
		{"pall", _pall},
		{"queue", _nop},
		{"stack", _nop},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"nop", _nop},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	(void)line_number;
	if (strcmp(cmd[0], "push") == 0)
	{
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (1);
		}
		if (is_number(cmd[1]) == 0 || cmd[1][0] == '\0')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(node);
			return (1);
		}
		node->n = atoi(cmd[1]);
	}
	if (strcmp(format, "queue") == 0 && strcmp(cmd[0], "push") == 0)
		_push_queue(&node, line_number);
	if (strcmp(format, "stack") == 0 && strcmp(cmd[0], "push") == 0)
		_push(&node, line_number);
	for (i = 0; inst[i].opcode; i++)
	{
		if (strcmp(inst[i].opcode, cmd[0]) == 0)
		{
			found = 1;
			inst[i].f(&node, line_number);
		}
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd[0]);
		return (1);
	}

	return (0);
}

/**
 * is_number - a function that check a string if it isn't an integer
 * @str: the string
 * Return: 0 or 1
 */

int is_number(char *str)
{
	int i = 0, j;

	if (str == NULL || str[0] == '\0')
		return (0);
	for (j = 0; str[j]; j++)
	{
		if (str[j] == '\n')
			str[j] = '\0';
	}
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
