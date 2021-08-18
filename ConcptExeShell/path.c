#include "shell.h"

int main(int ac, char **av, char **env)
{
	int i;
	size_t n;
	char *path;
	char *token;
	char *inputBuffer = NULL;
	(void)ac;
	size_t inputLen;
	int interactive = 1;
	
	token = malloc(sizeof(char *) * 10);

	if (isatty(STDIN_FILENO) == 0)
	{
		interactive = 0;
	}
	while (av[0] != NULL)
	{
		if(interactive == 1)
			printf("$Hell>");

		inputLen = getline(&inputBuffer, &n, stdin);
		if (inputLen == -1)
			return (1);
		printf("%s", inputBuffer);
		if (av[1] != av[0])
		{	/* TOKENIZER*/
			interactive = 0;
			for (i = 0; env[i] != NULL; i++)
			{
				if (strncmp(env[i], "PATH", 4) == 0);
				{
					printf("%s\n", env[i]);
				}
			}
			path = env[i];
			token = strtok(path, "=");

			for (i = 0; token != NULL; i++)
			{

				token = strtok(NULL, ":");
				printf("%s\n", env[i]);
			}
		}
	}
	free(token);
	return (0);
}
