#include "shell.h"

/**
 * _exit_ - Execute the "exit" built-in command
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0 on successful execution, or 1
 * if an invalid argument is provided.
*/
int _exit_(data_manager *data)
{
	int st;
	int i = 0;

	if (data->args[1])
	{
		while (data->args[1][i])
		{
			if (_alp(data->args[1][i++]) == 1)
				return (1);
		}
		st = _atoi(data->args[1]);
		free_all(data);
		exit(st);
	}
	else
	{
		free_all(data);
		exit(0);
	}

	return (0);
}

