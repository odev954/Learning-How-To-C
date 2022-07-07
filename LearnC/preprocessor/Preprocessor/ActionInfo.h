#ifndef ACTION_INFO_H
#define ACTION_INFO_H

#include "Command.h"

typedef struct ActionInfo
{
	Command command;
	char** argv;
	int argc;
} ActionInfo;

#endif