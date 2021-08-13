#include "shell.h"
#include <string.h>

char *_strtok(char *str, char delim)
{
	static char *input = NULL;
	char *result;
	int i;

	

	result = malloc(sizeof(str));
	if (result == '\0')
	{
		free(result);
		return(0);
	}
	if (str != NULL)
		input = str;
	if (input == NULL)
	{
		free(input);
		return (0);
	}
	for (i = 0; input[i]; i++)
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
	int i = 1;
	char *str = argv[i];
	char *ptr;
	(void)argc;
	
	ptr = _strtok(str, ' ');

/*	printf("%s\n", ptr);*/
	if (ptr == 0)
		return (0);
	if (argv[i])
	while (ptr)
	{
		i++;
		printf("%s\n", ptr);
		ptr = _strtok(NULL, ' ');
	}
	str = NULL;
	
	return (0);
}
