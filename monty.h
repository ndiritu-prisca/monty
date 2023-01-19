#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO
  */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*error_handling.c*/
void args_err(void);
void open_err(char *file);
void instruction_err(char *token, unsigned int line);
void int_err(unsigned int line);
void malloc_err(void);

/*execution.c*/
void open_read(char **av);
int is_comment(char *token);
int is_num(char *token);

/*ops.c*/
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int);

/*0_stack.c*/
void push_stack(stack_t **stack, int num);
void pall_stack(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *stack);

#endif /*MONTY_H*/
