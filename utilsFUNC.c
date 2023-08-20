#include "main.h"
/**
* is_printable - Evaluates  character if printable
* @c: Character to be evaluated.
* Return: 1 if c is printable, 0 NonPrintable
*/
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
* append_hexa_code - Append ascci Hexadecimal code to the buffer
* @buffer: Array of characters.
* @i: Index at which to start appending characters.
* @ascii_code: ASSCI CODE.
* Return: Always 3
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}
/**
* is_digit - Verify if a character is a Digit
* @c: Character to be evaluated
* Return: 1 if c is a digit, 0 Nondigit
*/
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}
/**
* convert_size_number - Casts a Number to Specified Size
* @num: Numbers to be casted.
* @size: Numbers indicating type to be casted.
* Return: Casted value of Numbers
*/
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
/**
* convert_size_unsgnd - Casts a Number to the Specified Size
* @num: Numbers to be casted
* @size: Number indicating  type to be casted
* Return: Casted value of Numbers
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
