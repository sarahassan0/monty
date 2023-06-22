#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	__attribute__((unused)) stack_t *temp;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack.
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
 * add - adds the top two elements of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

