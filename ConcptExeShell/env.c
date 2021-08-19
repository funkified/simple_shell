#include "shell.h"

/**
 * showenv - Function that prints the entire environmental
 * variable list onto the console
 * This function handles env with arguments
 * @args: The argument that came with env
 * @environ: List of environmental variables, passed from main
 * Return: Nothing.
 */
void showenv(char *args, char **environ)
{
	int count, length;

	if (strcmp("-i", args) == 0)
		return;

	for (count = 0; environ[count] != NULL; count++)
	{
		length = strlen(environ[count]);
		write(STDOUT_FILENO, environ[count], length);
		if (strcmp("-0", args) == 0)
			write(STDOUT_FILENO, "\0", 1);
		else
			write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * show_only_env - Function that prints the entire environmental
 * variable list onto the console
 * This function handles env with no arguments
 * @environ: List of environmental variables, passed from main
 * Return: Nothing
 */
void show_only_env(char **environ)
{
	int count, length;

	for (count = 0; environ[count] != NULL; count++)
	{
		length = strlen(environ[count]);
		write(STDOUT_FILENO, environ[count], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}
