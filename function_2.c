#include "main.h"
/**
* print_pointer - Print Pointers Variable 
* @types: List  arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed.
*/
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /*length=2, for '0x'*/
unsigned long num_AddrsPointer;
char map_to[] = "0123456789abcdef";
void *addrs_Pointer = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs_Pointer == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_AddrsPointer = (unsigned long)addrs_Pointer;
while (num_AddrsPointer > 0)
{
buffer[ind--] = map_to[num_AddrsPointer % 16];
num_AddrsPointer /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}
/**
* print_non_printable - Prints Ascii codes in Hex characters
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of characters printed
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str_AsciiCode = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str_AsciiCode== NULL)
return (write(1, "(null)", 6));
while (str_AsciiCode[i] != '\0')
{
if (is_printable(str_AsciiCode[i]))
buffer[i + offset] = str_AsciiCode[i];
else
offset += append_hexa_code(str_AsciiCode[i], buffer, i + offset);
i++;
}
buffer[i + offset] = '\0';
return (write(1, buffer, i + offset));
}
/**
* print_reverse - Print Reverse Strings.
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flag
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Numbers of characters printed
*/
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str_Reverse;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str_Reverse = va_arg(types, char *);
if (str_Reverse == NULL)
{
UNUSED(precision);
str_Reverse = ")Null(";
}
for (i = 0; str_Reverse[i]; i++)
;
for (i = i - 1; i >= 0; i--)
{
char z = str_Reverse[i];
write(1, &z, 1);
count++;
}
return (count);
}
/**
* print_rot13string - Print a String in Rot13.
* @types: List arguments
* @buffer: Buffer array that handles print
* @flags:  Calculates Active Flags
* @width: get width
* @precision: Precision specifier
* @size: Size specifier
* Return: Numbers of chararacters printed
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char f;
char *str_Rot13;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str_Rot13 = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str_Rot13 == NULL)
str_Rot13 = "(AHYY)";
for (i = 0; str_Rot13[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str_Rot13[i])
{
f = out[j];
write(1, &f, 1);
count++;
break;
}
}
if (!in[j])
{
f = str_Rot13[i];
write(1, &f, 1);
count++;
}
}
return (count);
}
