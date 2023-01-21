#include "monty.h"

opret_q queue_t;

/**
 * _push - a function taht adds a new node at the beginning of a stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _push(stack_t **top, unsigned int line_number)
{

	(void) line_number;

	if (queue_t.val == 0)
		add_node(top);
	else
		add_node_end(top);
}

/**
 * _pall - a function that prints the elements of a stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - a function that frees a dlist_t list
 * @top: top of the stack. (head)
 * Return: void
 **/
void free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}

/**
 * _pint - a function that prints the value at top of a stack
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _pint(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
		pint_err(line_number);
}

/**
 * _pop - a function that pops (deletes) the value at top of a stack
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _pop(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *top;
	if (*top == NULL)
		pop_err(line_number);

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
