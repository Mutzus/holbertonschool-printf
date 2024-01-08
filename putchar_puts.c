#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1 is returned
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 *
 * Return: On success, the number of characters written. On error, -1 is returned.
 */
int _puts(char *str)
{
    int count = 0;
    while (*str)
    {
        if (_putchar(*str) == -1)
            return -1;
        count++;
        str++;
    }
    return count;
}
