#include "shell.h"

/**
 * _strcpy - Copy from src To Dest
 * @dest: Destination
 * @src: Source
 * Return: pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s: string address
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenate Two String
 * @dest: Destination
 * @src: Source
 * Return: return a pointer to the resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i + dest_len] = src[i];
	}
	dest[i + dest_len] = '\0';

	return (dest);
}

/**
 * itoa - Convert Integer To Character/string
 * @num: Integer To Convert
 * @str: Pointer to the location where the converted string will be stored
 * Return: Pointer to the resulting character/string
 */
char *itoa(int num, char *str)
{
	int i = 0, is_neg = 0, rem;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
	}

	if (num < 0)
	{
		is_neg = 1;
		num = -num;
	}

	while (num != 0)
	{
		rem = num % 10;
		str[i++] = rem + '0';
		num /= 10;
	}
	if (is_neg)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	reverse(str, i);

	return (str);
}

/**
 * reverse - reverser string character;
 * @str: string to reverse
 * @len: length of the string
 */
void reverse(char *str, int len)
{
	int i, j;

	char temp;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = str[i];

		str[i] = str[j];

		str[j] = temp;
	}
}

