#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int printed_chars = 0;

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            int value = va_arg(args, int);
            printed_chars += printf("%d", value);
            format += 2; // Move to the next format specifier
        }
        else
        {
            putchar(*format);
            printed_chars++;
            format++;
        }
    }

    va_end(args);
    return printed_chars;
}

int main(void)
{
    _printf("Value: %d, %i\n", 42, -123);

    return 0;
}
