#include "monty.h"

/**
 * div_err - a function that prints error message if the stack contains less
 * than two elements
 * @line: line read
 * Return: void
 */
void div_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * div_err2 - a function that prints error message if the top element of the
 * stack is 0
 * @line: line read
 * Return: void
 */
void div_err2(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mul_err - a function that prints error message if the stack contains less
 * than two elements
 * @line: line read
 * Return: void
 */
void mul_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mod_err - a function that prints error message if the stack contains less
 * than two elements
 * @line: line read
 * Return: void
 */
void mod_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}
