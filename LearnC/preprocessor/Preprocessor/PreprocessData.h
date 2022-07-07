#ifndef PRE_PROCESS_DATA_H
#define PRE_PROCESS_DATA_H

#include "Definition.h"
#include <stdlib.h>
#include <string.h>

typedef struct PreprocessData
{
	Definition* definitions;
	int amount;
} PreprocessData;

void createData(PreprocessData* self)
{
	self->definitions = (Definition*)malloc(sizeof(Definition));
	self->amount = 1;
}

void insertNewDefinition(PreprocessData* self, Definition newDefinition)
{
	if (self->amount > 0)
	{
		Definition* temporary = (Definition*)realloc(self->definitions, sizeof(Definition) * (self->amount + 1));

		if (temporary != NULL)
		{
			self->definitions = temporary;
			self->amount++;
		}
	}
	else
	{
		createData(self);
	}
	self->definitions[self->amount - 1] = newDefinition;
}

Definition* searchDefinitionByName(PreprocessData* self, char* name)
{
	for (int i = 0; i < self->amount; i++)
	{
		if (strcmp(self->definitions[i].name, name) == 0)
		{
			return self->definitions + i;
		}
	}
	return NULL;
}

void freeData(PreprocessData* self)
{
	for (int i = 0; i < self->amount; i++)
	{
		free(self->definitions[i].name);
		free(self->definitions[i].value);
	}
	free(self->definitions);
}

#endif

