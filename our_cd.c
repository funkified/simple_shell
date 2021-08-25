#include "holberton.h"
/**
 * our_cd - Custom version of cd. Allows user to move between
 * directories depending on the argument passed alongside cd
 * @path: The argument after cd that determines where to move
 * @environ: Environmental variable list, passed from main
 * Return: 0 if successfully moved, -1 otherwise
 */
int our_cd(char *path, char **environ)
{
	char *hold;

	if (path == NULL || (_strcmp(path, "~") == 0))
	{
		hold = _getenv("HOME", environ);
		hold = get_env_value(hold, "=");
		return (chdir(hold));
	}
	else if (_strcmp(path, "..") == 0)
		return (chdir(".."));
	else if (_strcmp(path, "-") == 0)
	{
		if (_getenv("OLDPWD", environ) != NULL)
		{
			hold = _getenv("OLDPWD", environ);
			hold = get_env_value(hold, "=");
			return (chdir(hold));
		}
	}
	else if (_strcmp(path, ".") == 0)
	{
		hold = _getenv("PWD", environ);
		hold = get_env_value(hold, "=");
		return (chdir(hold));
	}
	else
	{
		if (access(path, F_OK) == 0)
			return (chdir(path));

		else
			perror("cd failed");
	}
	return (-1);
}
