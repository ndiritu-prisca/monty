#include"monty.h"

/**
 * pint_err - a function that prints error message if the stack is empty
 * @line: line read
 * Return: void
 */
void pint_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pop_err - a function that prints error message if the stack is empty
 * @line: line read
 * Return: void
 */
void pop_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}

/**
 * swap_err -a function that prints error message if stack contains less
 * than two elements
 * @line: line read
 * Return: void
 */
void swap_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * add_err - a function that prints error message if the stack contains less
 * than two elements
 * @line: line read
 * Return: void
 */
void add_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * sub_err - a function that prints error message if the stack contains
 * less than two elements
 * @line: lineread
 * Return: void
 */
void sub_err(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
