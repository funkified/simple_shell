#include "shell.h"


int main(void)
{
	FILE *fp;
	char x[10] = "ABCDEFGIJ\n";

	fp=fopen("file.c", "wb");
	fwrite(x, sizeof(x[0]), sizeof(x)/sizeof(x[0]), fp);
	printf("DA FILe is %lu %s", sizeof(fp), x);
	fclose(fp);
	return (0);
}
