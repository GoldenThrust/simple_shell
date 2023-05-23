#include "shell.h"

/**
 * check_cmd - Check the validity of a command
 * @data: Pointer to the data_manager struct containing command data
 * @ch: Size of input
 * Return: -1 for error condition, 0 for invalid command,
 * 1 for valid command.
*/
int check_cmd(data_manager *data, size_t ch)
{
	int i = 0;

	if ((int)ch == -1)
	{
		return (-1);
	}
	else if (*data->input == '\n' || *data->input == '\0')
	{
		return (1);
	}
	else
	{
		while (data->input[i])
		{
			if (data->input[i] != ' ' &&
			data->input[i] != '\0' && data->input[i] != '\n')
				return (0);

			i++;
		}
	}

	return (1);
}

/**
 * status - Show error message if command is not found
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0 if no error is found. 127 on error.
 */
int status(data_manager *data)
{
	char *str = malloc(intlen(data->counter) * sizeof(int));

	str = itoa(data->counter, str);
	_puts("./hsh: ", 2);
	_puts(str, 2);
	_puts(": ", 2);
	if (_strcmp(data->args[0], "exit") == 0)
	{
		_puts("exit: ", 2);
		_puts("illegal number: ", 2);
		_puts(data->args[1], 2);
		_putchar('\n', 2);
		free(str);
		return (127);
	}
	else
	{
		_puts(data->args[0], 2);
		_puts(": not found\n", 2);
		free(str);
		return (127);
	}

	return (0);
}

