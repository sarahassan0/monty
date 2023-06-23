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
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp1 = (*stack)->next;
	temp2 = *stack;
	for (; temp2->next != NULL; temp2 = temp2->next)
		;
	temp1->prev = NULL;
	temp2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp2;
	*stack = temp1;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	temp = *stack;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}
