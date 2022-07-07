#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

/*
Splits a given string to sub-strings, and delimiters the sub-string sequance with a NULL.
*/
char** splitString(char* string, char seperator)
{
	char** list = (char**)malloc(sizeof(char*));
	int size = 1;
	int index = 0;
	int counter = 1;

	list[size - 1] = (char*)malloc(sizeof(char));
	while (string[index] != NULL)
	{
		if (string[index] == seperator)
		{
			list[size - 1][counter - 1] = NULL;
			size++;
			list = (char**)realloc(list, sizeof(char*) * size);
			list[size - 1] = (char*)malloc(sizeof(char));
			counter = 1;
		}
		else
		{
			list[size - 1][counter - 1] = string[index];
			counter++;

			list[size - 1] = (char*)realloc(list[size - 1], sizeof(char) * counter);
		}
		index++;
	}

	list[size - 1][counter - 1] = NULL;
	list = (char**)realloc(list, sizeof(char*) * (size + 1));
	list[size] = NULL;

	return list;
}

#endif