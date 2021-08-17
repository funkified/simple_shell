#include "shell.h"

int main(void)
{
	size_t size = 0;
	char *line = NULL;

	printf("$ ");
	getline(&line, &size, stdin);

	printf("%s", line);
	return (0);
}
