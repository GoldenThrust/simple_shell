#include "shell.h"

/**
 * _realloc -  Reallocates A Memory Block Using Malloc And Free
 * @ptr: A pointer to the memory block
 * @old_size: The new size, in bytes, of the memory block.
 * @size: The new size, in bytes, of the memory block.
 *Return: pointer to the resized memory block,on error NULL
 */
void *_realloc(void *ptr, size_t old_size, size_t size)
{
	void *n_ptr;
	size_t c_size;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	n_ptr = malloc(size);
	if (n_ptr == NULL)
		return (NULL);

	c_size = old_size < size ? old_size : size;

	_memcpy(n_ptr, ptr, c_size);

	free(ptr);
	return (n_ptr);
}



/**
 * _memcpy - Copy a block of memory  From Source To Destination
 * @dest: Destination
 * @src: Source
 * @n: number of bytes to be copied from src to dest
 * Return: pointer to the dest buffer
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	char *cd = (char *)dest, *cs = (char *)src;
	size_t i;

	for (i = 0; i < n; i++)
		cd[i] = cs[i];

	return (dest);
}

