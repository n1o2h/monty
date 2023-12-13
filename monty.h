#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>


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

extern stack_t *head;

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

void principal(FILE *);
int exec(char **, unsigned int, char *);
int exec_stack(char **, unsigned int);
int exec_queue(char **, unsigned int);
char **split(char *txt, char *sep);
void _push(stack_t **, unsigned int);
void _push_queue(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _Qpall(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
void _pstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);
/*void _pop(stack_t **, unsigned int);*/
/*void _swap(stack_t **, unsigned int);*/
/*void _add(stack_t **, unsigned int);*/
char **_strtok(char *argv, char **table);
char *_strdup(char *);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

#endif
