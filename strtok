#include "monty.h"

/**
 * **_strtok - strtok function
 * @argv: the entire command line
 * @table: the av commande
 * Return: double pointer
 */

char **_strtok(char *line, char **cmd)
{
	char *str;
	int i = 0, j;

	for (j = 0; line[j]; j++)
	{
		if (line[j] == '\n')
			line[j] = '\0';
	}
	str = strtok(line, " ");
	while (str && i < 100)
	{
		cmd[i++] = str;
		str = strtok(NULL, " ");
	}
	cmd[i] = NULL;
	return (cmd);
}
