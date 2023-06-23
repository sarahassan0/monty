#include "monty.h"

/**
 * _stack - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
	interpreter->mode = 1;
}

/**
 * _queue - .
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)(line_number);
	interpreter->mode = 0;
}
