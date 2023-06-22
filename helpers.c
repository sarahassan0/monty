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

/**
 * is_digit - Checks if a string represents a valid integer.
 * @string: The string to be checked.
 * Return: 1 if the string represents a valid integer, 0 otherwise.
 */

int is_digit(char *string)
{
	if (!string || *string == '\0')
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (isdigit(*string) == 0)
			return (0);
		string++;
	}
	return (1);
}
