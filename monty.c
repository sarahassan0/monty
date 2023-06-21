#include "monty.h"

global_t *interpreter;

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
    while ((read = getline(&lineptr, &len, monty_file)) != -1)
    {

        interpreter->line_number = ++line_number;
        if (read > 1)
        {
            interpreter->line = strtok(lineptr, "\n");
            interprete_line(&stack);
        }
    }
    free(lineptr);
    fclose(monty_file);
    free_stack(&stack);
    return (0);
}

int interprete_line(stack_t **stack)
{
    int i = 0;
    instruction_t monty_opcode[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {NULL, NULL}};

    char *opcode;
    char *intger;

    opcode = strtok(interpreter->line, " $");
    intger = (strtok(NULL, " $"));

    if (intger != NULL)
    {
        if (is_digit(intger))
            interpreter->intger = atoi(intger);
        else
        {
            fclose(interpreter->file);
            fprintf(stderr, "L%i: push integer\n", interpreter->line_number);
            exit(EXIT_FAILURE);
        }
    }

    while (opcode != NULL)
    {
        if (strcmp(opcode, monty_opcode[i].opcode) == 0)
        {

            monty_opcode[i].f(stack, interpreter->line_number);
            return -1;
        };
        i++;
    }

    fclose(interpreter->file);
    fprintf(stderr, "L%i: unknown instruction %s\n", interpreter->line_number, opcode);
    exit(EXIT_FAILURE);

    return (0);
}
