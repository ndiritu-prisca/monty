#include "monty.h"

/**
 * _pstr - a function that prints the string starting at the top of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _pstr(stack_t **top, unsigned int line_number)
{

	(void)line_number;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	while (*top != NULL)
	{
		if ((*top)->n <= 0 || (*top)->n > 127)
			break;
		printf("%c", (*top)->n);
		*top = (*top)->next;
	}
	putchar('\n');
}

/**
 * _stack - a function that  sets the format of the data to a stack (LIFO)
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _stack(stack_t **top, unsigned int line_number)
{
	(void)line_number;

	(*top)->n = -1;
}

/**
 * _queue - a function that sets the format of the data to a queue (FIFO).
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _queue(stack_t **top, unsigned int line_number)
{
	(void)line_number;
}
