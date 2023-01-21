#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
  * struct queue_s - Return value of opcodes and if list is stack/queue
  * @opcode_ret: Return value of the void opcode functions
  * @val: 1 if list is a queue, 0 if it's a stack
  *
  */
typedef struct queue_s
{
	int opcode_ret;
	int val;
	int number;
} opret_q;
extern opret_q queue_t;

/* error_handler functions */
void args_err(void);
void open_err(char **av);
void instruction_err(char *instruction, unsigned int line);
void num_err(unsigned int line);
void malloc_err(void);

/* error handler 2 */
void pint_err(unsigned int line);
void pop_err(unsigned int line);
void swap_err(unsigned int line);
void add_err(unsigned int line);
void sub_err(unsigned int line);

/* error_handler3 */
void div_err(unsigned int line);
void div_err2(unsigned int line);
void mul_err(unsigned int line);
void mod_err(unsigned int line);
/*error handler4*/
void pchar_err(unsigned int line);
void pchar_err2(unsigned int line);

/* executer functions*/
void open_read(char **av);
int is_num(char *token);
int is_comment(char *token, int line_counter);

/*opcodes */
void (*get_op_code(char *token, unsigned int line)) (stack_t **, unsigned int);


/* Stack */
void _push(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int line_number);
void free_stack(stack_t *top);
void _pint(stack_t **top, unsigned int line_number);
void _pop(stack_t **top, unsigned int line_number);

/* stack operations */
void _swap(stack_t **top, unsigned int line);
void _add(stack_t **top, unsigned int line);
void _sub(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line);

/* stack 3 */
void _mod(stack_t **top, unsigned int line_number);
void _rotl(stack_t **top, unsigned int line_number);
void _rotr(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line);
void _pchar(stack_t **top, unsigned int line_number);

/*stack4 */
void _pstr(stack_t **top, unsigned int line_number);
void _stack(stack_t **top, unsigned int line_number);
void _queue(stack_t **top, unsigned int line_number);
void add_node(stack_t **top);
void add_node_end(stack_t **top);

#endif /* _MONTY_H_ */
