#include "monty.h"

/**
 * *_strdup - newly allocated space in memory
 * @str: string given as a parameter.
 * Return: p or Null
*/

char *_strdup(char *str)
{
	char *p;
	int i, size;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size]; size++)
		;
	p = (char *)malloc(size + 1);
	if (p == NULL)
	{	fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i <= size; i++)
		p[i] = str[i];
	return (p);
}
