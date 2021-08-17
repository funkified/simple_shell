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
/* Macros */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define PROMPT "Hell_Shell$" 
/* Prototypes Functions */
char *_strtok(char *str, char delim);

/**
 * struct stat - struct for bypassing forbidden glbal variables
 * @token2: fisrt member
 * @buffer: second memer
 *
 * Description: Allows freeing of certain variable for fixing memmory leaks
 */
struct statStruct
{
	char *token2;
	char *buffer;
};

#endif
