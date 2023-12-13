#include "monty.h"
/**
 * free_dlistint - free dlistint_t list
 *@head: head
 * Return: nothing
 *
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	if (!head)
		return;
	while (head)
	{
		current = head;
		head = (head)->next;
		free(current);
	}
}
