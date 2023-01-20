#include"monty.h"

/**
 * args_err - a function that prints error message if user does not give
 * 2 arguments
 * Return: void
 **/
void args_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * open_err - a function that prints error message if it is not possible to
 * open the file
 * @av: arguments received by main, in this case the filename
 * Return: void
 **/
void open_err(char **av)
{
	char *filename = av[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * instruction_err - a function that prints error message to stderr if the file
 * openned has an invalid instruction
 * @instruction: instruction
 * @line: line number
 * Return: void
 **/
void instruction_err(char *instruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, instruction);
	exit(EXIT_FAILURE);
}

/**
 * num_err - a function that prints error message if parameter received
 * is not a digit
 * @line: line number
 * Return: void
 **/
void num_err(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - a function that prints error message if malloc fails
 *
 * Return: void
 **/
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
