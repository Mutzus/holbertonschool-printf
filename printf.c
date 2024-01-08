#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char *str;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            switch (*(ptr + 1))
            {
            case 'c':
                count += _putchar(va_arg(args, int));
                ptr++; /* Skip 'c' */
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(nil)";
                count += _puts(str);
                ptr++; /* Skip 's' */
                break;
            case '%':
                count += _putchar('%');
                ptr++; /* Skip '%' */
                break;
            default:
                count += _putchar(*ptr);
                break;
            }
        }
        else
        {
            count += _putchar(*ptr);
        }
    }

    va_end(args);

    return count;
}
