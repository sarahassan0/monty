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
