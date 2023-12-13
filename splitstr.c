#include "monty.h"
/**
 * split - SPLIT STRING
 *@txt: string to split
 *@sep: separator
 * Return: pointer to words.
 */
char **split(char *txt, char *sep)
{
	char *tok;
	char **ptr;
	int i = 0, j;

	ptr = malloc(sizeof(char **) * strlen(txt));
	if (ptr == NULL)
		return (NULL);
	tok = strtok(txt, sep);
	while (tok != NULL)
	{
		ptr[i] = malloc(strlen(tok) + 1);
		if (ptr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(ptr[j]);
			free(ptr);
			return (NULL);
		}
		strcpy(ptr[i], tok);
		i++;
		tok = strtok(NULL, sep);
	}
	ptr[i] = NULL;
	return (ptr);
}
