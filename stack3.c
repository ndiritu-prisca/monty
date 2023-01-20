#include "monty.h"

/**
 *_mod - a function that computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * result is stored in the 2nd top element of the stack, and the top element
 * is removed.
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	if (*top == NULL || (*top)->next ==  NULL)
		mod_err(line_number);

	if ((*top)->n == 0)
		div_err2(line_number);

	temp = (*top)->next;
	temp->n  %= (*top)->n;
	_pop(top, line_number);
}

/**
 * _rotl - a function that rottates the stack to the top
 * top element of the stack becomes the last one, second element becomes top
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _rotl(stack_t **top, unsigned int line_number)
{
	stack_t *new_top, *temp, *new_last;

	(void)line_number;

	if (*top == NULL || (*top)->next == NULL)
		return;

	new_last = *top;
	temp = *top;

	while (temp->next != NULL)
		temp = temp->next;

	new_top = (*top)->next;
	new_last->next = NULL;
	new_last->prev = temp;
	temp->next = new_last;
	new_top->prev = NULL;
	*top = new_top;
}

/**
 * _rotr - a function that rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _rotr(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;
	temp = *top;
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = *top;
	(*top)->prev = temp;
	*top = temp;
}

/**
 * _nop - a function that does nothing.
 * @top: element at the top of the stack (head)
 * @line_number: line read
 * Return: void
 **/
void _nop(stack_t **top, unsigned int line_number)
{
	(void) top;
	(void) line_number;
}

/**
 * _pchar -a function that prints the char at the top of the stack
 * @top: element at the top of the stack (head)
 * @line_number: line reade
 * Return: void
 **/
void _pchar(stack_t **top, unsigned int line_number)
{
	int ascii_num;

	if (*top == NULL)
		pchar_err2(line_number);

	ascii_num = (*top)->n;

	if (ascii_num < 0 || ascii_num > 127)
		pchar_err(line_number);
	printf("%c\n", ascii_num);
}
