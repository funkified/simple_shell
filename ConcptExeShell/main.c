#include "shell.h"
#include <errno.h>
#include <sys/stat.h>
#include <signal.h>
int main(int argc, char **args, char **env)
{
	size_t n = NULL;
	char *inputBuffer;
	size_t inputLenght;
	int status;
	int interactive = 1, i = 0;
	char *delimeters = "\t\r\n";
	char **tokens = NULL;
	pid_t pid;
	struct stat statStruct;
	char *tokenPath[] = {"PATH", "/bin", NULL};
	char *fullPath = NULL;
	int currenTokPath;
	size_t tokenPathsize = 0;
	char cwd[1024];

	fullPath = malloc(sizeof(char) * 256);
	tokens = malloc(sizeof(char *) * 10);

	if (isatty(STDIN_FILENO) == 0)
	{
		interactive = 0;
	}
	while (1)
	{
		printf("$hell ");
		/* get line from standard input */
		inputLenght = getline(&inputBuffer, &n, stdin);
		getcwd(cwd, sizeof(cwd));
		printf("\nDir: %s", cwd);
	tokens[0] = strtok(inputBuffer, delimeters);

	/* Create Tokens */
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = strtok(NULL, delimeters);
	}
	/* Tokenized PATH */
	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
		if (strncmp(env[i], "PATH=", 3))
		{
			tokenPath[currenTokPath] = strtok(env[i], "=");

			while (tokenPath[currenTokPath] != NULL)
			{
				currenTokPath++;
				if (currenTokPath == tokenPathsize)
				{
					tokenPathsize = tokenPathsize * 2;
				/*	tokenPath = realloc(tokenPath, tokenPathsize);*/
				}
				tokenPath[currenTokPath] = strtok(NULL, ":");
			}
			i++;
		}
		printf("%s\n", fullPath);
	}
	/*	Check if the program exist */
		status = stat(tokens[0], &statStruct);

		if (status == -1 && tokens[0][0] != '/')
		{
			i = 1;
			while (tokenPath[i] != NULL)
			{
				strcat(fullPath, tokenPath[1]);
				strcat(fullPath, "/" );
				strcat(fullPath, tokens[0]);

				status = stat(fullPath, &statStruct);
				printf("%s\n", tokenPath[i]);
				if (status == 0)
				{
					break;
				}
				else
				{
					memset(fullPath, '\0', 256);
				}
				i++;
				printf("concat: %s\n", fullPath);
			}
		}
		else
		{
			status = access(tokens[0], X_OK);

			if (status == -1)
			{
				perror("WRONG");
				printf("Errno: %d\n", errno);
			}
			else
			{
				/* Execute the chld */
				pid = fork();
				if (pid == 0)
				{
					execve(fullPath, tokens, env);
					exit(0);
				}
				else
				{
					wait(NULL);
				}
			}
		}
		/*Reset Token*/
		i = 0;
		while (i < 10)
		{
			tokens[i] = NULL;
			i++;
		}
		printf("%s\n", fullPath);
		printf("%s", env[i]);
	}	
	free(tokens);
	return (0);
}
