#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int len = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	len += checker(format, args);
	va_end(args);
	return (len);
}
int checker(const char *format, va_list args)
{
	int len = 0, i = 0;
	char *str, next, ch;

	while (format[i])
	{
		next = format[i + 1];
		if (format[i] == '%' && next == 'c')
		{
			ch = va_arg(args, int);
			len += _putchar(ch), i++;

		}
		else if (format[i] == '%' && next == 's')
		{
			str = va_arg(args, char *);
			len += _puts(str), i++;
		}
		else if (format[i] == '%' && next == '%')
		{
			len += _putchar('%'), i++;
		}
		else if (format[i] == '%' && next == ' ')
		{
			return (-1);
		}
		else
		{
			len += _putchar(format[i]);
		}
		i++;
	}
	return (len);
}
int _putint(int n)
{
	int len = 0;
	unsigned int num = n;

	if (n < 0)
	{
		len += _putchar('-');
		num = -n;
	}
	if (num / 10 > 0)
	{
		_putint(num / 10);
	}
	_putchar('0' + (num % 10));
	while (n != 0)
	{
		n /= 10;
		len++;
	}
		return (len);
}
int _puts(char *s)
{
	char *str = s;
	int i;

	if (!str)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
int _putchar(char c)
{
	return (write(1, &c, 1));
}










