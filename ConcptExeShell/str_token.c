#include "shell.h"
#include <string.h>

char *_strtok(char *str, char delim)
{
	static char *input = NULL;
	char *result;
	int i;

	

	result = malloc(sizeof(*result) - 1);
	if (result == NULL)
	{
		free(result);
		return(NULL);
	}
	if (str != NULL)
		input = str;
	if (input == NULL)
	{
		free(input);
		return (0);
	}
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] != delim)
		{
			result[i] = input[i];
		}
		else
		{
			result[i] = '\0';
			input = input + i + 1;
			return(result);
		}
	}
	result[i] = '\0';
	input = NULL;


	return (result);
}

int main(int argc, char **argv)
{
	int i;
	char *str = argv[1];
	char *token;
	(void)argc;

	token = _strtok(str, ' ');

	if (token == '\0')
		return (0);
	for (i = 0; token != '\0'; i++)
	{
		argv[i] = token;
		printf("%s\n", str);
		token = _strtok(NULL, ' ');
	}
	printf("%s\n", argv[i]);
	str = NULL;
	
	return (0);
}

