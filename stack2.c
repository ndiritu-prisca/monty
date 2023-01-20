#include "monty.h"

/**
 *_swap - a function that swaps the top 2 elements of a stack
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _swap(stack_t **top, unsigned int line_number)
{
	int num;

	if (*top == NULL || (*top)->next == NULL)
		swap_err(line_number);

	num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = num;
}

/**
 *_add - a function that adds the top two elements of the stack
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
		add_err(line_number);

	temp = (*top)->next;
	temp->n += (*top)->n;
	_pop(top, line_number);
}

/**
 *_sub - a function that subtracts the top element of the stack from the second
 * top element of the stack..
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
		sub_err(line_number);

	temp = (*top)->next;
	temp->n -= (*top)->n;
	_pop(top, line_number);
}

/**
 * _div - a function that divides the second top element of the stack by the
 * top element of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 */

void _div(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
		div_err(line_number);

	if ((*top)->n == 0)
		div_err2(line_number);

	temp = (*top)->next;
	temp->n = (temp->n) / (*top)->n;
	_pop(top, line_number);
}

/**
 * _mul - a function that multiplies the second top element of the stack with
 * the top element of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 */
void _mul(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
		mul_err(line_number);

	temp = (*top)->next;
	temp->n *= (*top)->n;
	_pop(top, line_number);
}
