#include "main.h"
/**
* print_unsigned - Print Unsigned Number
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of chararacters printed.
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num_Unsigned= va_arg(types, unsigned long int);
num_Unsigned = convert_size_unsgnd(num_Unsigned, size);
if (num_Unsigned == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num_Unsigned > 0)
{
buffer[i--] = (num_Unsigned % 10) + '0';
num_Unsigned /= 10;
}
i++;
return 
(write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
* print_octal - Print Unsigned Octal Number
* @types: List arguments
* @buffer: Buffer array that handle print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of chararacters printed
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num_UnsignOctal = va_arg(types, unsigned long int);
unsigned long int init_num = num_UnsignOctal;
UNUSED(width);
num_UnsignOctal = convert_size_unsgnd(num_UnsignOctal, size);
if (num_UnsignOctal == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num_UnsignOctal > 0)
{
buffer[i--] = (num_UnsignOctal % 8) + '0';
num_UnsignOctal/= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return 
(write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
* print_hexadecimal - Print Unsigned Hexadecimal Number 
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of charaxters printed
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
* print_hexa_upper - Print Unsigned Upper Hexadecimal Number 
* @types: List arguments
* @buffer: Buffer array that handlee print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of chararters printed
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/**
* print_hexa - Print Unsigned Upper and Lower Hexadecimak Number
* @types: List arguments
* @map_to: Array of values that map the number 
* @buffer: Buffer array that handle print
* @flags:  Calculates Active Flag
* @flag_ch: Calculates active flags
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* @size: Size specification
* Return: Number of chararacters printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num_UnsignLower = va_arg(types, unsigned long int);
unsigned long int init_num = num_UnsignLower;
UNUSED(width);
num_UnsignLower = convert_size_unsgnd(num_UnsignLower, size);
if (num_UnsignLower == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num_UnsignLower > 0)
{
buffer[i--] = map_to[num_UnsignLower % 16];
num_UnsignLower /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
