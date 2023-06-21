#include "monty.h"

global_t *interpreter;

int main(int argc, char **argv)
{
    FILE *monty_file = NULL;
    char line[1000];
    int line_number = 0;
    stack_t *stack = NULL;

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

    while ((fgets(line, sizeof(line), monty_file)) != NULL)
    {

        interpreter->line = strtok(line, "\n");
        interpreter->line_number = line_number++;
        interprete_line(&stack);
    }
    fclose(monty_file);
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

    opcode = strtok(interpreter->line, " ");
    intger = (strtok(NULL, " "));
    (void)intger;
    while (monty_opcode != NULL)
    {
        if (opcode == monty_opcode[i].opcode)
        {
            monty_opcode[i].f(stack, interpreter->line_number);
        };
        i++;
    }

    fprintf(stderr, "L%i: unknown instruction %s\n", interpreter->line_number, opcode);
    exit(EXIT_FAILURE);

    return (0);
}
