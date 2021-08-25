#ifndef _SHELL_H_
#define _SHELL_H_

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
/* Macros */
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM "\t\r\n\a"
/* Prototypes Functions */
void atty(void);
char *_strtok(char *str, char delim);
int _strlen(char *s);
int _strcmp(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *get_env(char *name, char **environ);
char *get_env_value(char *str, char *delim);
char *get_input(void);
char **split(char *input);
void freeAndFlush(char *command, char *commandcopy, char **array);
char *cmd_cpy(char *dest, char *src, char *usr_cmd);
char *static_path(char *user_command, char *env_string, struct data *d);
char *_strdup(char *str, struct data *d);
void freeAndFlush(char *command, char *commandcopy, char **array)

/**
 * struct stat - struct for bypassing forbidden glbal variables
 * @token2: fisrt member
 * @buffer: second memer
 *
 * Description: Allows freeing of certain variable for fixing memmory leaks
 */
struct data
{
	char *token2;
	char *buffer;
};

#endif
