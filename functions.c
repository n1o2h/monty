#include "monty.h"

/**
 * _push - a function that push an element to the stack
 * @node: the node to be added
 * @line_number: unused variable
 * Return: void
 */

void _push(stack_t **node, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	if (head == NULL)
	{
		head = *node;
		(*node)->next = NULL;
		(*node)->prev = NULL;
	}
	else
	{
		ptr = head;
		(*node)->next = ptr;
		ptr->prev = *node;
		head = *node;
		(*node)->prev = NULL;
	}
}

/**
 * _pall - a function that prints all the values on the stack
 * @line_number: unused variable
 * @node: the top of the stack
 * Return: void
 */


void _pall(stack_t **node, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	(void)node;
	if (head != NULL)
	{
		ptr = head;
		while (ptr)
		{
			printf("%d\n", ptr->n);
			fflush(stdout);
			ptr = ptr->next;
		}
	}
}

/**
 * _pint - a function that print the element in the top
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _pint(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
	fflush(stdout);
}

/**
 * _pop - a function that delete the top element
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _pop(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *pop;

	if (head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		pop = head;
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		free(pop);
	}
}
