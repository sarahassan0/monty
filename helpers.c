#include "monty.h"
/**
 * _atoi - covert string to number.
 * @s: string to be converted to number.
 *
 * Return: result of converting string to number, -1 on failure.
 */

int _atoi(char *s)
{
    unsigned int result, i;
    char sign;

    i = 0;
    result = 0;

    while (s[i] != '\0')
    {
        if (!((s[i] >= '0') && (s[i] <= '9')))
        {
            return (-1);
        }
        if (((s[i] >= '0') && (s[i] <= '9')))
        {
            result = (result * 10) + (s[i] - '0');
        }
        else if (s[i] == '+')
            sign++;

        i++;
    };

    return (result);
}

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
}

/**
 * remove_comments - Removes comments from a command line input.
 * @lineptr: Pointer to the string containing the command line input.
 *
 * Return: Pointer to a newly allocated string without the comments,
 *         NULL if lineptr is NULL or an empty string.
 */
