#include "shell.h"

/**
 * _exit_ - Execute the "exit" built-in command
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0 on successful execution, or 1
 * if an invalid argument is provided.
*/
void _exit_(data_manager *data)
{
	int st;
	int i = 0;

	if (_strcmp(data->args[0], "exit") == 0)
	{
		if (data->args[1])
		{
			while (data->args[1][i])
			{
				if (_alp(data->args[1][i++]) == 1)
					return;
			}
			st = _atoi(data->args[1]);
			free(data->input);
			free_all(data);
			exit(st);
		}
		else
		{
			free(data->input);
			free_all(data);
			exit(0);
		}
	}

}

/**
 * h_signal - handle ^C signal
 * @sig: signal
 */
void h_signal(int sig)
{
	if (sig == SIGINT)
		_puts("\n$ ", 1);
}
