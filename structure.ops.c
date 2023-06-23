#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int tmp;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}

/**
 * rotl - rotates the stack to the top
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * roter - rotates the stack to the bottom
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void roter(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
