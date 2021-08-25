#include "holberton.h"
/**
 * main - Initialize, Read, and Execute a line command interpreter
 * @argc: number of argumetns passed
 * @argv: argument passed
 * @env: enviroment command
 */

int main(int argc, char **argv, char **env)
{
	char *command = NULL, *env_string = NULL, *commandcopy = NULL, *token;
	size_t command_size = 0, commandnum = 0, i = 0;
	char **array;
	char delim[] = " ";
	int status = 0, read_line = 0;
	pid_t pid;
	struct data mine;
	(void)argc, (void)argv;

	signal(SIGINT, SIG_IGN);
	env_string = _getenv("PATH", env);
	atty();

	/*Initialize: In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior*/
	while ((read_line = getline(&command, &command_size, stdin)))
	{
		commandnum = 0;
		command_size = 0;

		if (read_line == EOF)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		for (i = 0; command[i]; i++)
		{
			if (command[i] == '\n')
				command[i] = '\0';
		}
		command = strtok(command, "#");
		commandcopy = strdup(command);

		token = strtok(commandcopy, " ");

		while (token != NULL)
		{
			token = strtok(NULL, " ");
			commandnum++;
		}

		array = malloc(sizeof(char *) * (commandnum + 1));

		token = strtok(command, " ");
		i = 0;
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		array[i] = NULL;

		if (array[0] != NULL && _strcmp("exit", array[0]) == 0)
		{

			if (array[1] != NULL)
			{
				if (*(array[1]) <= '9' && *(array[1]) >= '0')
					status = atoi(array[1]);
			}
			freeAndFlush(command, commandcopy, array);
			pid = fork();
			while(pid != 1)
			{
				exit(status);
			}
		}

		if (array[0] != NULL && _strcmp("cd", array[0]) == 0)
		{
			our_cd(array[1], env);
		}
		if (array[0] != NULL && _strcmp("env", array[0]) == 0)
		{
			if (array[1] != NULL)
				showenv(array[1], env);
			else
				show_only_env(env);
		}
		if (array[0] != NULL)
		{
			mine.buffer = NULL;
			array[0] = static_path(array[0], env_string, &mine);
			free(mine.buffer);
			/* needed to free exact amount but stops program from working free(mine.token2); */
			if (fork() == 0)
			{
				if ((execve(array[0], array, NULL) == -1))
				{
					write(STDERR_FILENO, array[0], _strlen(array[0]));
					write(STDERR_FILENO, ": command not found\n", 21);
				}
				exit(status);
			}
			else
				wait(NULL);

			freeAndFlush(command, commandcopy, array);

			command = NULL;
			commandcopy = NULL;
			atty();
		}
	}
	freeAll(&mine);
	return (0);
}

/**
 * atty - check of interective
 */
void atty(void)
{
	if(isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$Hell>", 7);
}

void freeAndFlush(char *command, char *commandcopy, char **array)
{
	free(command);
	free(commandcopy);
	free(array);
	fflush(stdin);
}
