#include "shell.h"

int main(int ac, char **av, char **env)
{
	(void)ac;
	int i;
	size_t n;
	char *path;
	char *token, *prompt = "$HELL==>"
	char *inputBuffer;
	size_t inputLen;
	struct stat statBuffer;
	int status;
	int interactive = 1;
	pid_t pid;

	
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, 2);
	signal(SIGNIT, handler);
	
	while ((inputLen = getline(&inputBuffer, &n, stdin))
	{
			interactive = 0;
		return (1);
	if (av[0])
		if (inputLen == -1)
		{
			return (1);
		}
		printf("%s", inputBuffer);
		
		if (av[0] && av[1])
		/* TOKENIZER*/
			interactive = 0;
			for (i = 0; env[i] != NULL; i++)
			{
				if (strncmp(env[i], "PATH", 4))
				{
					printf("%s\n", env[i]);
				}
			}
			path = env[i];
			token = strtok(path, "=");

			for (i = 0; token != NULL; i++)
			{

				token = strtok(NULL, ":");
				printf("Path: %s\n", token);
			}
			i++;
	}
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			/*execve(token[0], token, NULL);*/
			wait(&status);
		}	
	}
/*	printf("PID: %d\n", pid);
	printf("PATH = %s\n", path);
	printf("ENV: %s\n", env[i]);
*/
	return (0);
}
