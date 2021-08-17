#include "shell.h"
#include <string.h>

char *_strtok(char *str, char delim)
{
	static char *input = NULL;
	char *token_array ;
	int i;

	token_array = malloc(sizeof(*token_array) - 1);
	if (token_array == NULL)
	{
		free(token_array);
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
			token_array[i] = input[i];
		}
		else
		{
			token_array[i] = '\0';
			input = input + i + 1;
			return(token_array);
		}
	}	
	token_array[i] = '\0';
	input = NULL;


	return (token_array);
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
	for (i = 0; token != '\0' ; i++)
	{
		argv[i] = token;
		printf("%s\n", argv[i]);
		token = _strtok(NULL, ' ');
	}
	str = NULL;
	
	return (0);
}
