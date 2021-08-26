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

/**
 * struct data - Struct for bypassing the restriction
 * forbidding global variables
 * @token2: First member
 * @buffer: Second member
 *
 * Description: Allows freeing of certain variables in memory
 * where freeing otherwise would cause errors. This allows for
 * fixing any possible memory leaks
 */

struct data
{
	char *token2;
	char *buffer;
};

/* Prototypes Functions */
void atty(void);
int _strlen(char *s);
int _strcmp(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_getenv(char *name, char **environ);
char *get_env_value(char *str, char *delim);
void freeAndFlush(char *command, char *commandcopy, char **array);
char *cmd_cpy(char *dest, char *src, char *usr_cmd);
char *static_path(char *user_command, char *env_string, struct data *d);
char *_strdup(char *str, struct data *d);
void freeAll(struct data *d);
void showenv(char *args, char **environ);
void show_only_env(char **environ);
int our_cd(char *path, char **environ);
int _atoi(char *s);
#endif
