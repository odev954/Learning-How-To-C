#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Reader
{
	FILE* file;

} Reader;

Reader createReader(char* path)
{
	return { fopen(path, "r") };
}

char* readUntil(Reader* self, char delimiter)
{
	char current = NULL;
	char* text = (char*)malloc(sizeof(char));
	int length = 1;
	int left = 0;
	
	fseek(self->file, 0, SEEK_END);
	left = ftell(self->file);
	fseek(self->file, 0L, SEEK_SET);

	while (current != delimiter && left > 0)
	{
		fread(&current, sizeof(char), 1, self->file);

		text[length - 1] = current;
		length++;

		//exapnd the text string
		char* temporary = (char*)realloc(text, sizeof(char) * length);

		if (temporary != NULL)
		{
			text = temporary;
		}

		left--;
	}
	text[length - 1] = NULL;

	fseek(self->file, 1, SEEK_CUR);

	return text;
}

#endif 

