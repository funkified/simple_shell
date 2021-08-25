#include "holberton.h"

/**
 * get_input - read line/input from stdin
 * Return: string input
 */

char *get_input(void)
{
	char *input = NULL;
	size_t len = 0;

	if (getline(&input, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading from input\n");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}

/**
 * split - split string inton tokens
 * @input: line passed to tokeniezd
 * Return: tokeniezd stirng
 */

char **split(char *input)
{
	int len = 0;
	int bufsize = TOKEN_BUFSIZE;
	char **string_tokens = NULL;
	char *token = NULL;

	string_tokens = malloc(sizeof(char *) * bufsize);

	if (string_tokens == NULL)
	{
		fprintf(stderr, "Allocation Failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, TOKEN_DELIM);

	while (token != NULL)
	{
		string_tokens[len] = token;
		len++;

		if (len >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			string_tokens = realloc(string_tokens, bufsize * sizeof(char *));
			if (!string_tokens)
			{
				fprintf(stderr, "Allocation Failed\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIM);
	}
	string_tokens[len] = NULL;
	return (string_tokens);
}
