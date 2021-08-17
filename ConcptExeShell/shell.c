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

	fullPath = malloc(sizeof(char) * 256);
	tokens = malloc(sizeof(char *) * 10);

	if (isatty(STDIN_FILENO) == 0)
	{
		interactive = 0;
	}
/* interactive mode */
	while (1 == 1)
	{
		if (interactive == 1)
		{
			printf("$hell  ");
		}
		/* get line from standard input */
		inputLenght = getline(&inputBuffer, &n, stdin);
	}

	tokens[0] = strtok(inputBuffer, delimeters);
	/* Create Tokens */
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = strtok(NULL, delimeters);
	}
	/* Tokenized PATH */
	/* Check if the program exist */

	/*	status = stat(tokens[0], &statStruct);*/

	/*else - check for errors */
	/* Execute the chld */
	/*Reset Token*/

	return (0);
}
