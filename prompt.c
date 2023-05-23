#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @i: File directory
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int i)
{
	return (write(i, &c, 1));
}

/**
 * prompt - Display Shell Prompt
 *
 * Return: On success 1;
 */
int prompt(void)
{
	_puts("$ ", 1);

	return (1);
}

/**
 * _puts - print a string of charcter
 *
 * @str: pointer to char
 * @i: standard I/O number
 */
void _puts(char *str, int i)
{
	int j;

	for (j = 0; str[j] != '\0'; j++)
	{
		_putchar(str[j], i);
	}
}


