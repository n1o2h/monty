#include "monty.h"

/**
 * _swap - a function that swaps the top 2 elements
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _swap(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *tmp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} else
	{
		tmp = head->next;
		head->next = tmp->next;
		head->prev = tmp;
		tmp->next = head;
		tmp->prev = NULL;
		head = tmp;
	}
}
/**
 * _sub - a function that subs the top 2 elements
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _sub(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} else
	{
		head->next->n -= head->n;
		_pop(NULL, line_number);
	}
}
/**
 * _add - a function that adds the top 2 elements
 * @node: unused variable
 * @line_number: the line number
 * Return: void
 */

void _add(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} else
	{
		head->next->n += head->n;
		_pop(NULL, line_number);
	}
}

/**
 * _nop - a function that doesn't do anything
 * @node: unused variable
 * @line_number: unused variable
 * Return: void
 */

void _nop(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	(void)line_number;
}
