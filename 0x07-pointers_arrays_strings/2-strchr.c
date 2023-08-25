#include "main.h"

/**
 * _strchr - Locate a character in a string
 * @s: Input string
 * @c: Character to locate
 * Return: Pointer to the first occurrence of character in the string, or NULL
 */
char *_strchr(char *s, char c)
{
    int i = 0;

    for (; s[i] >= '\0'; i++)
    {
        if (s[i] == c)
            return (&s[i]);
    }
    return (0);
}

