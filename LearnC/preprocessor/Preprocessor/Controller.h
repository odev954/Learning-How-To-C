#ifndef CONTROLLER_DATA_H
#define CONTROLLER_DATA_H

#include <stdio.h>
#include "Reader.h"
#include "Action.h"
#include "Utils.h"

typedef struct Controller
{
	PreprocessData data;
	Reader reader;
	Action* actions;
	int actionCount;
} Controller;

char* getNextCommand(Controller* self)
{

}

ActionInfo makeInfo(Controller* self)
{
	char* arguments = readUntil(&self->reader, '\n');
	ActionInfo result = { self, splitString(arguments, ' '), 0 };

	while (result.argv + result.argc != NULL)
	{
		result.argc++;
	}

	return result;
}

ReturnCode runCommand(Controller* self, char* command)
{
	for(int i = 0; i < self->actionCount; i++)
	{
		if (strcmp(command, self->actions[i].command) == 0)
		{
			return self->actions[i].action(makeInfo(self));
		}
	}
}

#endif