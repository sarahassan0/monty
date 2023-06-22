#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
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
	stack_t temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
	{
		temp->next->prev = *stack;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
