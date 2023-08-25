#include "main.h"

/**
 * _strstr - Locate a substring in a string
 * @haystack: Input string to search in
 * @needle: Substring to search for
 * Return: Pointer to the beginning of the located substring, or NULL
 */
char *_strstr(char *haystack, char *needle)
{
    for (; *haystack != '\0'; haystack++)
    {
        char *l = haystack;
        char *p = needle;

        while (*l == *p && *p != '\0')
        {
            l++;
            p++;
        }

        if (*p == '\0')
            return (haystack);
    }

    return (0);
}

