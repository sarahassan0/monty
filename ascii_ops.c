#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	if (temp->n >= 0 && temp->n <= 127)
		printf("%c\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(interpreter->file);
		free_stack(stack);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top, followed by a new line
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
