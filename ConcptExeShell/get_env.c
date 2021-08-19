#include "shell.h"
/**
 * get_env_value - Function that takes an environment variable
 * string and extracts the value in the variable
 * @str: String to be strtok'd
 * @delim: Characters where strtok should split the string at
 * Return: The value of the environmental variable
 */
char *get_env_value(char *str, char *delim)
{
	str = strtok(str, delim);
	str = strtok(NULL, delim);

	return (str);
}

/**
 * _getenv - Custom version of getenv. Searches for
 * environmental variable in the given list
 * @name: Name of variable to search for
 * @environ: Environmental variable list, passed from main
 * Return: The pointer to the variable, if found, or NULL if not found
 */
char *_getenv(char *name, char **environ)
{
	int i, j, length = 0;
	char *environ_string = NULL;

	while (name[length])
		length++;

	environ_string = malloc(sizeof(char) * length + 1);
	if (environ_string == NULL)
	{
		free(environ_string);
		return (NULL);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		j = 0;
		while (j < length)
		{
			environ_string[j] = environ[i][j];
			j++;
		}
		if (strcmp(name, environ_string) == 0)
		{
			free(environ_string);
			return (environ[i]);
		}
	}

	free(environ_string);
	return (NULL);
}

