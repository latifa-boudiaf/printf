#include "main.h"

int _printf(const char *format, ...)
{
int printed_char;
va_list args;

printed_char = 0;

va_start(args, format);

while (*format)
{
if (*format == '\0')
{
break;
}
else if (*format != '%')
{
write(1, format, 1);
printed_char++;
}
else
{
if (*(format + 1) == '%')
{
write(1, "%", 1);
printed_char++;
format++;
}
else if (*(format + 1) == 'c')
{
int c = va_arg(args, int);
write(1, &c, 1);
printed_char++;
format++;
}
else if (*(format + 1) == 's')
{
char *string = va_arg(args, char*);
write(1, string, strlen(string));
printed_char += strlen(string);
format++;
}
}
format++;
}
va_end(args);
return printed_char;
}
