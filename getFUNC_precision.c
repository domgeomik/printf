#include "main.h"
/**
* get_precision - Calculates Precision for Printing
* @format: Formatted String to Print the Arguments
* @i: List Arguments to be Printed.
* @list: list of Arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision_Arg = -1;
if (format[curr_i] != '.')
return (precision_Arg);
precision_Arg = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision_Arg *= 10;
precision_Arg += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision_Arg = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (precision_Arg);
}
