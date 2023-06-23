#include "monty.h"

global_t *interpreter;

/**
 * main - Monty Interpreter
 * @argc: number of arguments
 * @argv: pointers to arguments array
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */

int main(int argc, char **argv)
{
	FILE *monty_file;
	int line_number = 0;
	stack_t *stack = NULL;
	char *lineptr = NULL;
	size_t len = 0;
	ssize_t read;

	interpreter = malloc(sizeof(global_t));
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	interpreter->file = monty_file;
	interpreter->mode = 1;
	while ((read = getline(&lineptr, &len, monty_file)) != -1)
	{

		interpreter->line_number = ++line_number;
		if (read > 1)
		{
			interpreter->line = strtok(lineptr, "\t\n");

			interprete_line(&stack);
		}
	}
	fclose(monty_file);
	free(lineptr);
	if (stack != NULL)
		free_stack(&stack);
	free(interpreter);
	return (0);
}

/**
 * interprete_line - Monty Interpreter.
 * @stack: pointers to the stack.
 * Return: 0 on success, -1 on error.
 */

int interprete_line(stack_t **stack)
{
	int i = 0;
	instruction_t monty_opcode[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"div", divtion},
		{"mul", mul}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"stack", _stack}, {"queue", _queue},
		{"rotl", rotl}, {"rotr", rotr}, {NULL, NULL}};

	char *opcode;
	char *intger;

	opcode = strtok(interpreter->line, " ");
	if (!opcode || opcode[0] == '#')
		return (0);
	intger = strtok(NULL, " ");
	interpreter->intger = intger;

	while (monty_opcode[i].opcode && opcode != NULL)
	{
		if (strcmp(opcode, monty_opcode[i].opcode) == 0)
		{
			monty_opcode[i].f(stack, interpreter->line_number);
			return (-1);
		};
		i++;
	}
	free_stack(stack);
	fclose(interpreter->file);
	fprintf(stderr, "L%u: unknown instruction %s\n",
			interpreter->line_number, opcode);
	exit(EXIT_FAILURE);
	return (0);
}
