#include "shell.h"

/**
 * _strncmp - Compares two strings, s1 and s2
 * , up to a specified number of characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * @n: The number of characters to compare.
 * Return: Returns 1 if the strings don't match,
 * 0 if they match, or -1 on null pointer.
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}


/**
 * _strcmp - Compares two strings, s1 and s2, lexicographically.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: 0 if the strings are equal, or 1 if they are not equal csharp
 * Returns 1 on null pointer inputs.
*/
int _strcmp(const char *s1, const char *s2)
{
	int l1 = strlen(s1), l2 = strlen(s2), i = 0;

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (l1 != l2)
		return (1);

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);

		i++;
	}

	return (0);
}

/**
 * _alp - Check if Alphabtic
 *@c: The character to check
 * Return: 1(True) 0(false)
 */
int _alp(int c)
{
	if (((c >= '0') && (c <= '9')))
		return (0);

	else
		return (1);
}

/**
 * _strchr - Find the first occurrence of a character in a string.
 *
 * @str: The string to search.
 * @c: The character to find.
 *
 * Return: pointer to the first occurrence of the character @c in @str
 *  , or NULL if the character is not found.
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);

		str++;
	}
	if (*str == c)
		return ((char *)str);

	return (NULL);
}

