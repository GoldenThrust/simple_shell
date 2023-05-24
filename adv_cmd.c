#include "shell.h"

/**
 * _getline - Read line of input from a file stream.
 *
 * @lineptr: Pointer to the buffer where the input will be store.
 * @n: Pointer to the buffer size.
 * @stream: Pointer to the file stream.
 *
 * Return: The number of characters read replacing null terminator with newline
 * Returns -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t i = 0;
	size_t bufsize = 0;
	static char *buf = NULL, c;
	int rd = 0;

	if (lineptr == NULL || n == NULL)
		return (-1);
	while (1)
	{
		if (bufsize - i < BUFSIZE)
		{
			bufsize += BUFSIZE;
			buf = _realloc(buf, bufsize - BUFSIZE, bufsize);
			if (buf == NULL)
				return (-1);
		}

		rd = read(_fileno(stream), &c, 1);
		if (rd == -1)
			return (-1);
		else if (rd == 0)
			break;

		buf[i++] = c;

		if (c == '\n')
			break;
	}
	if (i == 0)
	{
		if (buf)
			free(buf);
		return (-1);
	}
	buf[i] = '\0';
	*lineptr = buf;
	*n = bufsize;

	return (i);
}

/**
 * _fileno - get the file descriptor associated with a stream
 *
 * @stream: pointer to a FILE structure
 * Return: the file descriptor associated with the stream, or -1 on error
 */
int _fileno(FILE *stream)
{
	if (stream == NULL)
		return (-1);

	return (stream->_fileno);
}


/**
 * _strtok - Breaks a string into a sequence of tokens using a delimiter
 * @str: The string to parse
 * @delim: The string to parse
 * Return: A pointer to the next token in the string, or
 * NULL if there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *last_token;
	char *cur_token;

	if (str != NULL)
		last_token = str;

	if (last_token == NULL || *last_token == '\0')
		return (NULL);

	cur_token = last_token;
	while (*cur_token && _strchr(delim, *cur_token) != NULL)
		cur_token++;

	if (*cur_token == '\0')
	{
		last_token = NULL;
		return (NULL);
	}

	last_token = cur_token;
	while (*last_token && _strchr(delim, *last_token) == NULL)
		last_token++;

	if (*last_token != '\0')
		*last_token++ = '\0';

	return (cur_token);
}

