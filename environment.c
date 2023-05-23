#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable.
 * Return: On success, returns a pointer to the
 * value of the environment variable.
 * If the environment variable is not found or
 * the name is invalid, returns NULL.
 */
char *_getenv(const char *name)
{
	size_t n_len;
	int i;

	if (name == NULL || strlen(name) == 0)
	{
		return (NULL);
	}

	n_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, n_len) == 0 && environ[i][n_len] == '=')
		{
			return (environ[i] + n_len + 1);
		}
	}

	return (NULL);
}

/**
 * _which - Searches for a file in the directories
 * listed in the environment variable "PATH".
 * @filename: The name of the file to search for.
 * @data: Pointer to the data_manager struct containing command data
 * Return: On success, returns a pointer to the path of the file.
 * If the file is not found or the "OLDPWD"
 * environment variable is invalid, returns NULL.
 */
char *_which(const char *filename, data_manager *data)
{
	char *path = _getenv("PATH");
	char *token;
	struct stat st;

	token = strtok(path, ":");

	while (token)
	{
		strcpy(data->arg, token);
		strcat(data->arg, "/");
		strcat(data->arg, filename);
		strcat(data->arg, "\0");
		if (stat(data->arg, &st) == 0)
			return (data->arg);
		token = strtok(NULL, ":");
	}
	return (NULL);
}


