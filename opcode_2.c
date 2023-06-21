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
