#include "shell.h"

/**
 * cmd_loop - Loop the command until it is exited by pressing ctrl d.
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0;
 */
int cmd_loop(data_manager *data)
{
	size_t len, ch;
	int c;

	signal(SIGINT, h_signal);
	while (1)
	{
		data->counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		ch = _getline(&data->input, &len, stdin);
		c = check_cmd(data, ch);
		if (c == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n', 1);
			break;
		}
		else if (c == 1)
			continue;
		parse_line(data);
		_exit_(data);
		if (cmd_access(data) == 127)
			continue;

		execute_cmd(data);
	}
	return (0);
}

/**
 * parse_line - break input into token.
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0;
 */
int parse_line(data_manager *data)
{
	int i = 0;
	char *token;

	if (data->input == NULL)
	{
		return (1);
	}

	if (!data->args)
	{
		perror("hsh");
		return (1);
	}

	token = _strtok(data->input, " \n");

	while (token)
	{
		data->args[i] = token;
		token = _strtok(NULL, " \n");
		i++;
	}
	data->args[i] = NULL;

	return (0);
}

/**
 * cmd_access - check if command is executable.
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0;
 */
int cmd_access(data_manager *data)
{
	if (access(*data->args, X_OK) == -1)
	{
	   /** data->arg = _which(data->args[0], data);**/
		_strcpy(data->arg, "/bin/");
		_strcat(data->arg, data->args[0]);
		if (access(data->arg, X_OK) == -1)
		{
			status(data);
			return (127);
		}
		data->args[0] = data->arg;
	}

	return (0);
}

/**
 * execute_cmd - Execute command and fork command
 * @data: Pointer to the data_manager struct containing command data
 * Return: 0;
 */
void execute_cmd(data_manager *data)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		free_all(data);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(data->args[0], data->args, environ) == -1)
		{
			perror("./hsh");
			free_all(data);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

