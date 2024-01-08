#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str;

    if (format == NULL)
    {
        write(STDERR_FILENO, "Error: Format string is NULL\n", 29);
        return -1;
    }

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            switch (*(format + 1))
            {
            case 'c':
                count += _putchar(va_arg(args, int));
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                count += _puts(str);
                break;
            case '%':
                count += _putchar('%');
                break;
            case 'd':
            case 'i':
                count += _print_number(va_arg(args, int));
                break;
            default:
                count += _putchar(*format);
                count += _putchar(*(format + 1));
            }
            format += 2;
        }
        else
        {
            count += _putchar(*format);
            format++;
        }
    }

    va_end(args);
    return count;
}

/**
 * _print_number - print an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int _print_number(int n)
{
    int count = 0;
    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }
    if (n / 10)
        count += _print_number(n / 10);
    count += _putchar((n % 10) + '0');
    return count;
}
