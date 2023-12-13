#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point
 *@ac: number of args
 *@av: arguments passed to main
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	principal(file);
	return (0);
}
