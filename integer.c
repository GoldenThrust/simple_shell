#include "shell.h"

/**
 * intlen - Determine Length Of Int
 * @num: Integer
 * Return: Length Of Integer
 */
int intlen(int num)
{
	int i = 0;

	while (num != 0)
	{
		i++;

		num /= 10;
	}
	return (i);
}


/**
 * _atoi - convert string to integer
 * @nptr: string to convert
 * Return: integer
 */
int _atoi(const char *nptr)
{
	int num = 0, sign = 1;

	while (*nptr)
	{
		if (*nptr == '-')
			sign = -sign;
		else if (*nptr >= '0' && *nptr <= '9')
			num = num * 10 + (*nptr - '0');
		else if (num > 0)
			break;
		nptr++;
	}

	return (num * sign);
}



