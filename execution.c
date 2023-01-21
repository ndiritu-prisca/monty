#include "monty.h"

opret_q queue_t;

/**
 * open_read - a function that opens, reads and executes monty files.
 * @av: filename received as argument
 * Return: void
 **/
void open_read(char **av)
{
	void (*func_p)(stack_t **, unsigned int);
	FILE *fp;
	char *token = NULL, command[1024];
	char *buf = malloc(sizeof(char) * 1024);
	int len = 1024;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	fp = fopen(av[1], "r");
	if (fp == NULL)
		open_err(av);
	while (fgets(buf, len, fp) != NULL)
	{
		token = strtok(buf, "\n\t\r ");
		if (token == NULL)
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || is_num(token) == -1)
				num_err(line_counter);
			queue_t.number = atoi(token);
			func_p = get_op_code(command, line_counter);
			func_p(&top, line_counter);
		}
		else
		{
			func_p = get_op_code(token, line_counter);
			func_p(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	free_stack(top);
}

/**
* is_num - a function that checks if string received is a number or not
* @token: string to check
* Return: 1 if string is a number, else -1
*/
int is_num(char *token)
{
	int i;

	if (token == NULL)
		return (-1);

	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && isdigit(token[i]) == 0)
			return (-1);
	}
	return (1);
}

/**
* is_comment - a function that checks if string received is a comment or not
* @token: string to check
* @line_counter: line number
* Return: 1 if string is a comment, else -1s
*/
int is_comment(char *token, int line_counter)
{
	if (token == NULL || token[0] == '#')
	{
		line_counter++;
		return (1);
	}
	return (-1);
}
