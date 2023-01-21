#include "monty.h"

opret_q queue_t;

/**
 * _pstr - a function that prints the string starting at the top of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int num;

	(void)line_number;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	temp = *top;
	while (temp != NULL)
	{
		num = temp->n;
		if (num <= 0 || num > 127)
			break;
		putchar(num);
		temp = temp->next;
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
	(void)top;
	(void)line_number;

	queue_t.val = 0;
}

/**
 * _queue - a function that sets the format of the data to a queue (FIFO).
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _queue(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	queue_t.val = 1;
}

/**
 * add_node - a function that adds a node at the beginning.
 * @top: element at the top of the stack (head)
 * Return: void
 */
void add_node(stack_t **top)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		malloc_err();
		queue_t.opcode_ret = 1;
	}
	if (queue_t.opcode_ret != 1)
	{
		if (*top != NULL)
			(*top)->prev = newNode;
		newNode->next = *top;
		newNode->n = queue_t.number;
		newNode->prev = NULL;
		*top = newNode;
	}

}

/**
 * add_node_end - a function that adds a node at the end.
 * @top: element at the top of the stack (head)
 * Return: void
 */
void add_node_end(stack_t **top)
{
	stack_t *newNode;
	stack_t *temp = *top;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		malloc_err();
		queue_t.opcode_ret = 1;
	}
	if (queue_t.opcode_ret != 1)
	{
		while (temp != NULL && temp->next != NULL)
			temp = temp->next;
		newNode->n = queue_t.number;
		newNode->next = NULL;
		newNode->prev = temp;
		if (temp != NULL)
			temp->next = newNode;
		else
			*top = newNode;
	}
}
