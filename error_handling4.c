#include "monty.h"

/**
 * pchar_err - a function that prints error message if value is not
 * in the ascii table
 * @line: line read
 * Return: void
 */
void pchar_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pchar_err2 - a function that prints error message if the stack is empty
 * @line: line read
 * Return: void
 */
void pchar_err2(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
	exit(EXIT_FAILURE);
}
