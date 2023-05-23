#include "shell.h"

/**
 * main - shell simulation
 * Return: On success 0;
 */
int main(void)
{
	data_manager data;

	set_data(&data);
	cmd_loop(&data);
	free_all(&data);
	return (0);
}

/**
 * set_data - allocate space for data
 * @data: All alocated variable.
 * Return: 0;
*/
int set_data(data_manager *data)
{
	data->input = NULL;
	data->args = malloc((BUFSIZE / 2) * sizeof(char *));
	data->arg = malloc(sizeof(char *) * 100);
	data->counter = 0;
	data->err = 0;
	return (0);
}

/**
 * free_all - free all alocated data
 * @data: All alocated variable.
 * Return: 0;
*/
int free_all(data_manager *data)
{
	free(data->arg);
	free(data->args);
	return (0);
}

