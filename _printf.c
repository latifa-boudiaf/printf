#include "main.h"

/**
 * _printf - Custom implementation of the printf function
 * supporting %c, %s, %d, %i, and %%
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
	va_start(lst_args, format);

	printed_char = 0;

	if (format==NULL || *format == '\0')
	{
		return (-1);
	}
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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(lst_args, int);
				char buffer[12];
				int num_length = snprintf(buffer, sizeof(buffer), "%d", num);
				write(1, buffer, num_length);
				printed_char += num_length;
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(lst_args, unsigned int);
				unsigned int mask = 1U << ((sizeof(unsigned int) * 8) - 1);
				int flag = 0;
				while (mask)
				{
					if (num & mask)
					{
						write(1, "1", 1);
						printed_char++;
						flag = 1;
					}
					else if (flag)
					{
						write(1, "0", 1);
						printed_char++;
					}
					mask >>= 1;
				}
				if (!flag)
				{
					write(1, "0", 1);
					printed_char++;}
			}
		}
		format++;
	}

	va_end(lst_args);
	return (printed_char);
}
