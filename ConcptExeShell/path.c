#include "shell.h"

int main(int ac, char **av, char **env)
{
	(void)ac, (void)av;
	char *prompt = "$Hell>";
	char **array;
	int i;
	size_t command_size;
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

		if (interactive == EOF)
		{
			free(command);
			return (EXIT_SUCCESS);
		}

		token = strtok(commandcopy, delim);
		
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			command_size++;
		}
		array = malloc(sizeof(char *) * (command_size + 1));
		token = strtok(command, " ");
		
		i = 0;
		while (token != NULL)
		{
			array[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		array[i] = NULL;
		for (i = 0; env[i] != NULL; i++)
		{
			if (array[i] != NULL && strncmp(env[i], "PATH", 4) == 0);
			{
				printf("%s\n", env[i]);
			//	printf("Array: %s\n", array[i]);
			}
		}
		command = env[i];
		token = strtok(command, ":");

		for (i = 0; token != NULL; i++)
		{

			token = strtok(NULL, ":");
			printf("Path: %s\n", array[i]);
		}

		pid = fork();
		printf("Father PID: %d\n", pid);
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			if ((execve(array[0], array, NULL) == -1))
			{
				printf("After execve %d\n",  i);
				write(STDERR_FILENO, array[0], strlen(array[i]));
				write(STDERR_FILENO, ": command not found\n", 21);
			}
			exit(status);
		}
		else
		{
			printf("PID is : %d\n", pid);
			wait(NULL);
		}
		free(array);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 7);
	}
	free(token);
	printf("PID: %d\n", pid);
	printf("PATH = %s\n", command);
	printf("ENV: %s\n", env[i]);

	return (0);
}
