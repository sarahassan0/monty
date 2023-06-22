#include "monty.h"

/**
 * free_stack - free a dlistint_t list
 * @head: pointer to the head of the linked list
 *
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
