#include "main.h"

/**
 * get_width - field width of output
 * @format: string format
 * @i: integer i
 * @args: all arguments
 *
 * Return: fieldwidth
 */
int get_width(const char *format, int *i, va_list args)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != 0; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - 48;
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
