#include "monty.h"

/**
 * pint -  pushes an element to the stack.
 * @stack: the head of the linked list in stack.
 * @line_number: the line number.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t **head;
	stack_t *new;

	head = stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fclose(interpreter->file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (interpreter->intger != NULL)
	{
		if (is_digit(interpreter->intger))
			new->n = atoi(interpreter->intger);
		else
		{
			free(new);
			fclose(interpreter->file);
			free_stack(head);
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free(new);
		fclose(interpreter->file);
		free_stack(head);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	new->next = (*head);
	new->next->prev = new;
	*head = new;
}

/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *head = *stack;

	if (*stack == NULL)
		return;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(interpreter->file);
		free(interpreter->op);
		free(interpreter);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * add - adds the top two elements of the stack.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * nop - doesn’t do anything.
 * @stack: the head of the linked list in stack.
 * @line_number: the line number.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
