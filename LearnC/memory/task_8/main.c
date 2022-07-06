#include <stdio.h>

void copyFile(FILE* src, FILE* dst)
{
	char byte = '\0';
	size_t readAmount = fread(&byte, sizeof(char), 1, src);

	while (readAmount != 0)
	{
		fwrite(&byte, sizeof(char), 1, dst);
		readAmount = fread(&byte, sizeof(char), 1, src);
	}
}

int main()
{
	FILE* srcFile = fopen("./srcExample.txt", "r");
	FILE* dstFile = fopen("./dstExample.txt", "w");

	copyFile(srcFile, dstFile);

	fclose(srcFile);
	fclose(dstFile);

	return 0;
}