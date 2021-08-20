#include "shell.h"

int main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
	char *prompt = "$Hell>";
	char **array;
	int i;
	size_t command_size = 0, command_num = 0;
	char *command = NULL, *commandcopy = NULL;
	char *token;
	char *inputBuffer;
	size_t inputLen;
	struct stat statBuffer;
	int status;
	int interactive = 0;
	char delim[] = " ";
	pid_t pid;

	token = malloc(sizeof(char *) * 256);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, 7);
	}

	while ((inputLen = getline(&inputBuffer, &command_size, stdin)))
	{
		command_size = 0;
		inputLen = 0;

		if (inputLen == EOF)
		{
			free(command);
			return (EXIT_SUCCESS);
		}
		
		for (i = 0; inputBuffer[i]; i++)
		{
			if (inputBuffer[i] == '\n')
				inputBuffer[i] = '\0';
		}
		inputBuffer = strtok(inputBuffer, "#");
		commandcopy = strdup(inputBuffer);

		token = strtok(commandcopy, delim);
		
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			command_num++;
		}
		array = malloc(sizeof(char *) * (command_num + 1));
		token = strtok(command, " ");
		
		i = 0;
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, " ");
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
			free(token);
			free(array);
			free(commandcopy);

			pid = fork();
			while (pid != 1)
			{
				exit(status);
			}
		}
//		for (i = 0; env[i] != NULL; i++)
		if (array[0] != NULL && _strcmp("env", array[0]) == 0);
		{
			if (array[1] != NULL)
					showenv(array[1], env);
				else
					show_only_env(env);
		}
		if (fork() == 0)
		{
			if ((execve(array[0], array, NULL) == -1))
			{
//				printf("After execve %d\n",  i);
				write(STDERR_FILENO, array[0], _strlen(array[0]));
				write(STDERR_FILENO, ": command not found\n", 21);
			}
			exit(status);
		}
		else
		{
		//	printf("PID is : %d\n", pid);
			wait(NULL);
		}
		free(array);
		free(command);
		command = NULL;
		commandcopy = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 7);
	}
	free(token);
/*	printf("PID: %d\n", pid);
	printf("PATH = %s\n", command);
	printf("ENV: %s\n", env[i]);
*/
	return (0);
}
