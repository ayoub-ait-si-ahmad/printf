#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * _printf - prints formatted text to stdout
 * @format: format string containing format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, num_chars = 0, buffer_size = 1024, count;
	char *buffer, *str_arg, int_str[20]; /* max length of a 64-bit signed int is 19 characters + sign */

	va_start(args, format);

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			if (num_chars == buffer_size)
			{
				buffer_size += 1024;
				buffer = realloc(buffer, sizeof(char) * buffer_size);
				if (buffer == NULL)
					return (-1);
			}
			buffer[num_chars] = format[i];
			num_chars++;
			i++;
			continue;
		}
		i++;
		switch (format[i])
		{
			case 'c':
				if (num_chars == buffer_size)
				{
					buffer_size += 1024;
					buffer = realloc(buffer, sizeof(char) * buffer_size);
					if (buffer == NULL)
						return (-1);
				}
				buffer[num_chars] = va_arg(args, int);
				num_chars++;
				i++;
				break;
			case 's':
				str_arg = va_arg(args, char *);
				j = 0;
				while (str_arg[j] != '\0')
				{
					if (num_chars == buffer_size)
					{
						buffer_size += 1024;
						buffer = realloc(buffer, sizeof(char) * buffer_size);
						if (buffer == NULL)
							return (-1);
					}
					buffer[num_chars] = str_arg[j];
					num_chars++;
					j++;
				}
				i++;
				break;
			case 'i':
			case 'd':
				count = snprintf(int_str, 20, "%d", va_arg(args, int));
				if (count < 0)
					return (-1);
				j = 0;
				while (int_str[j] != '\0')
				{
					if (num_chars == buffer_size)
					{
						buffer_size += 1024;
						buffer = realloc(buffer, sizeof(char) * buffer_size);
						if (buffer == NULL)
							return (-1);
					}
					buffer[num_chars] = int_str[j];
					num_chars++;
					j++;
				}
				i++;
				break;
			case '%':
				if (num_chars == buffer_size)
				{
					buffer_size += 1024;
					buffer = realloc(buffer, sizeof(char) * buffer_size);
					if (buffer == NULL)
						return (-1);
				}
				buffer[num_chars] = '%';
				num_chars++;
				i++;
				break;
			default:
				return (-1);
		}
	}

	if (num_chars == buffer_size)
	{
		buffer_size += 1;
		buffer = realloc(buffer, sizeof(char) * buffer_size);
		if (buffer == NULL)
			return (-1);
	}
	buffer[num_chars] = '\0';

	va_end(args);

	count = write(1, buffer, num_chars);
	free(buffer);

	if (count < 0)
		return (-1);

	return (count);
}
