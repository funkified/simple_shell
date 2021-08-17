#include "shell.h"
#include <string.h>
int main(void)
{
	char string[] = "I hate shell";
	char *token = NULL;
	char **token_array = NULL;
	int i, count = 0;
	int lenght;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == ' ')
		{
			count++;
		}
	}

	count += 2;
	token_array = malloc(sizeof(char *) * (count));

	token = strtok(string, " ");

	for (i = 0; token != NULL; i++)
	{
		lenght = strlen(token);
		token_array[i] = malloc(sizeof(char) * (lenght + 1));
		token_array[i] = token;
		token = strtok(NULL, " ");
	}
	token_array[i] = NULL;

	for (i = 0; token_array[i] != NULL; i++)
	{
		printf("%s\n", token_array[i]);
	}
	return (0);
}
