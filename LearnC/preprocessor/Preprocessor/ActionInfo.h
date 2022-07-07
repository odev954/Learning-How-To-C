#ifndef ACTION_INFO_H
#define ACTION_INFO_H

#include "PreprocessData.h"

typedef struct ActionInfo
{
	Controller* controller;
	char** argv;
	int argc;
} ActionInfo;

#endif