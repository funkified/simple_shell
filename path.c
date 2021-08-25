#include "holberton.h"

/**
 * cmd_cpy - Function that copies a directory and user command
 * into a single line. This is later used to check if this is
 * a valid command to be executed
 *
 * @dest: String containing directory and user command in one
 * @src: Source: The directory string
 * @usr_cmd: Source: The user's input
 *
 * Return: See @dest
 */
char *cmd_cpy(char *dest, char *src, char *usr_cmd)
{
	int i, j;
	char slash = '/';

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = slash;
	for (i++, j = 0; usr_cmd[j] != '\0'; j++, i++)
		dest[i] = usr_cmd[j];

	dest[i] = '\0';
	return (dest);
}

/**
 * static_path - Function that determines if user input is a valid
 * command by searching all directories in PATH
 *
 * @user_command: The user's input
 * @env_string: The environmental variable PATH. Will be strtok'd here
 * @d: Struct. Holds the address of token2 to be freed later
 *
 * Return: The command to be executed in main
 */
char *static_path(char *user_command, char *env_string, struct data *d)
{
	char *token = NULL;
	char *dupe_str = NULL;
	int i, len = 0;

	dupe_str = _strdup(env_string, d);
	dupe_str = get_env_value(dupe_str, "=");
	token = strtok(dupe_str, ":");
	len = _strlen(user_command);
	while (token != NULL)
	{
		d->token2 = malloc(sizeof(char) * (len + _strlen(token) + 2));
		for (i = 0; i < (_strlen(token) + _strlen(user_command) + 1); i++)
			d->token2[i] = '\0';
		cmd_cpy(d->token2, token, user_command);

		if (access(d->token2, F_OK) == 0)
			return (d->token2);
		/* memory error occurs because of above */

		token = strtok(NULL, ":");
		free(d->token2);
	}
	return (user_command);
}
