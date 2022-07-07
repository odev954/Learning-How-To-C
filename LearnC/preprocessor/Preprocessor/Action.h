#ifndef ACTION_H
#define ACTION_H

#include "ReturnCode.h"
#include "ActionInfo.h"

typedef struct Action
{
	char* command;
	ReturnCode(*action)(ActionInfo);
} Action;

#endif 

