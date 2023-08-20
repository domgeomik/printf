#include "main.h"
/**
* get_size - Calculates Size to Cast the Argument
* @format: Formatted strings to print the Arguments
* @i: List  Arguments to be Printed.
*
* Return: Precision.
*/
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size_Arg = 0;
if (format[curr_i] == 'l')
size_Arg = S_LONG;
else if (format[curr_i] == 'h')
size_Arg = S_SHORT;
if (size_Arg == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size_Arg);
}
