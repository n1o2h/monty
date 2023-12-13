#include "monty.h"
stack_t *head = NULL;
void get_format(char **cmd, char *format);

/**
 * main - Entry point
 *@ac: number of args
 *@av: arguments passed to main
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	FILE *file;
	unsigned int line_count = 0;
	char **cmd, line[200], *format = _strdup("stack");
	int e, i;

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
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_count++;
		cmd = split(line, " ");
		if (cmd[0][0] == '\n' || cmd[0][0] == '#')
		{
			for (i = 0; cmd[i] != NULL; i++)
				free(cmd[i]);
			free(cmd);
			continue;
		}
		get_format(cmd, format);
		e = exec(cmd, line_count, format);
		for (i = 0; cmd[i] != NULL; i++)
			free(cmd[i]);
		free(cmd);
		if (e)
			exit(EXIT_FAILURE);
	}
	fclose(file);
	free(format);
	free_dlistint(head);
	return (0);
}

/**
 * get_format - a function that get format
 * @cmd: the cmd
 * @format: the format
 * Return: void
 */

void get_format(char **cmd, char *format)
{
	int i;

	for (i = 0; cmd[0][i]; i++)
	{
		if (cmd[0][i] == '\n')
			cmd[0][i] = '\0';
	}
	if (strcmp(cmd[0], "queue") == 0 || strcmp(cmd[0], "stack") == 0)
		strcpy(format, cmd[0]);
}
