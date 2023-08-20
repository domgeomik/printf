#include "main.h"
/**
* print_char - Prints a character
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flags
* @width: Width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (handle_write_char
(c, buffer, flags, width, precision, size));
}
/**
* print_string - Print Strings
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flags
* @width: get width.
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str_value = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str_value == NULL)
{
str_value = "(null)";
if (precision >= 6)
str_value = "      ";
}
while (str_value[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str_value[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str_value[0], length);
return (width);
}
}
return (write(1, str_value, length));
}
/**
* print_percent - Print percentage sign
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width.
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
* print_int - Print int
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width.
* @precision: Precision specificier
* @size: Size specifier
* Return: Number of characters printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_NegativeValue = 0;
long int n = va_arg(types, long int);
unsigned long int num;
n = convert_size_number(n, size);
if (n == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
num = (unsigned long int)n;
if (n < 0)
{
num = (unsigned long int)((-1) * n);
is_NegativeValue = 1;
}
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_number
(is_NegativeValue, i, buffer, flags, width, precision, size));
}
/**
* print_binary - Print unsigned number
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: Get width.
* @precision: Precision specifier
* @size: Size specifier
* Return: Numbers of characters printed.
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int dom, emma, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
dom = va_arg(types, unsigned int);
emma = 2147483648; /* (2 ^ 31) */
a[0] = dom / emma;
for (i = 1; i < 32; i++)
{
emma /= 2;
a[i] = (dom / emma) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
