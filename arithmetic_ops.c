#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free_stack(stack);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

/**
 * divtion -  divides the second top element by the top element of the stack
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void divtion(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(interpreter->file);
		free_stack(stack);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n / temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

/**
 * mul -  multiplies the second top element of the stack with the
 *   top element of the stack.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

/**
 * mod - computes the rest of the division of the second top element of
 *  the stack by the top element of the stack.
 * @stack: the head of the linked list in stack
 * @line_number: the line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int result;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(interpreter->file);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(interpreter->file);
		free_stack(stack);
		free(interpreter->line);
		free(interpreter);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n % temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
