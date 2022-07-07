#ifndef DEFINE_H
#define DEFINE_H

#include "ActionInfo.h"
#include "ReturnCode.h"
#include "Controller.h"

#define ARG_AMOUNT 2

ReturnCode define(ActionInfo info)
{
	ReturnCode result = SUCCESS;
	Definition* definition = NULL;
	char* command = NULL;

	if (info.argc == ARG_AMOUNT)
	{
		definition = searchDefinitionByName(&info.controller->data, info.argv[0]);

		if (definition == NULL)
		{
			insertNewDefinition(&info.controller->data, { info.argv[0], info.argv[1] });
		}
		else
		{
			result = FAILURE;
		}
	}
	else
	{
		result = FAILURE;
	}

	return result;
}

#endif