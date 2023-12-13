#include "monty.h"

/**
 * _rotl - a function that rotates the stack to the top.
 * @node: unused variable
 * @line_number: unused variable
 * Return: void
 */

void _rotl(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (head != NULL && head->next != NULL)
	{
		last = head;
		while (last->next)
			last = last->next;
		last->next = head;
		head->prev = last;
		head = head->next;
		head->prev = NULL;
		last->next->next = NULL;
	}
}
/**
 * _rotr - a function that rotates the stack to the bottom.
 * @node: unused variable
 * @line_number: unused variable
 * Return: void
 */

void _rotr(stack_t __attribute__((unused)) **node, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (head != NULL && head->next != NULL)
	{
		last = head;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = head;
		head->prev = last;
		head = last;
	}
}

/**
 * _push_queue - a function that push an element to the stack (FIFO)
 * @node: the node to be added
 * @line_number: unused variable
 * Return: void
 */

void _push_queue(stack_t **node, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (head == NULL)
	{
		head = *node;
		(*node)->next = NULL;
		(*node)->prev = NULL;
	}
	else
	{
		ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = *node;
		(*node)->prev = ptr;
		(*node)->next = NULL;
	}
}

/**
 * _Qpall - a function that prints all the values on the stack(FIFO)
 * @line_number: unused variable
 * @node: the top of the stack
 * Return: void
 */


void _Qpall(stack_t **node, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	(void)node;
	if (head != NULL)
	{
		ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		while (ptr)
		{
			printf("%d\n", ptr->n);
			fflush(stdout);
			ptr = ptr->prev;
		}
	}
}
