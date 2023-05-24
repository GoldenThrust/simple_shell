#ifndef MAIN_H
#define MAIN_H

/** Library */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <malloc.h>


/**  enviroment variable  */
extern char **environ;

/**   MACROS  */
#define BUFSIZE 1024

/**
 * struct data_m - store all alocated data
 * @input:command line input
 * @args: tokenized input
 * @arg: command path
 * @err: error number
 * @counter: number of time ./hsh is looped
*/
typedef struct data_m
{
	char *input;
	char **args;
	char *arg;
	int err;
	size_t counter;
} data_manager;

/** main function */
int set_data(data_manager *data);
int free_all(data_manager *data);

/** prompt */
int prompt(void);
int _putchar(char c, int i);
void _puts(char *str, int i);

/** command */
int check_cmd(data_manager *data, size_t ch);
int cmd_loop(data_manager *data);
int parse_line(data_manager *data);
int cmd_access(data_manager *data);
void execute_cmd(data_manager *data);
int status(data_manager *data);
void h_signal(int sig);

/** char function */
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *s);
void reverse(char *str, int len);
char *itoa(int num, char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
int _alp(int c);
char *_strchr(const char *str, int c);

/** interger function */
int intlen(int num);
int _atoi(const char *nptr);

/** memory */
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t old_size, size_t size);

/** built in function */
int f_builtin(data_manager *data);
void _exit_(data_manager *data);

/** Advance project */

/** getline */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _fileno(FILE *stream);

/** strtok */
char *_strtok(char *str, const char *delim);

/**environment*/
char *_which(const char *filename, data_manager *data);
char *_getenv(const char *name);

/** End*/

#endif

