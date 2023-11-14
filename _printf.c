#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * supporting %c, %s, and %%
 * @format: A format string containing conversion specifiers
 * @...: Additional arguments corresponding to the conversion
 * specifiers in the format string
 *
 * Return: The number of characters printed (excluding the
 * null byte at the end)
 */
int _printf(const char *format, ...)
{
int printed_char;
va_list lst_args;

if (format==NULL || *format == '\0')
return -1;

va_start(lst_args, format);
printed_char = 0;

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
printed_char++;
}
else
{
format++;
if (*format == '%')
{
write(1, "%", 1);
printed_char++;
}
else if (*format == 'c')
{
char c = va_arg(lst_args, int);
write(1, &c, 1);
printed_char++;
}
else if (*format == 's')
{
char *string = va_arg(lst_args, char *);

write(1, string, strlen(string));
printed_char += strlen(string);
}
}
format++;
}

va_end(lst_args);
return (printed_char);
}
