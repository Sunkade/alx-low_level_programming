#include "main.h"

/**
 * _isalpha - Check if a character is an alphabetic character
 * @c: The character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 */
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * print_sign - Print the sign of a number
 * @n: The int to check
 * Return: 1 and print + if n is greater than zero,
 * 0 and print 0 if n is zero,
 * -1 and print - if n is less than zero
 */
int print_sign(int n)
{
    if (n > 0)
    {
        _putchar('+');
        return (1);
    }
    else if (n == 0)
    {
        _putchar('0');
        return (0);
    }
    else if (n < 0)
    {
        _putchar('-');
    }
    return (-1);
}

