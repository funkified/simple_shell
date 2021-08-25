#include "shell.h"

#define max_args 12
void getArgs(char *cmd, char **args)
{
	int i = 0;

	strtok(cmd, " ");
	args[i] = cmd; /*1st argument is the command*/

	while ((args[++i] = strtok(NULL, " ")) != NULL && i < (max_args - 2))
		;
}
