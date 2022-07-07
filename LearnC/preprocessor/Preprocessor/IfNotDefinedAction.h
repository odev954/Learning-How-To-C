#ifndef IFNDEF_H
#define IFNDEF_H

#include "ActionInfo.h"
#include "ReturnCode.h"
#include "Controller.h"

#define ELSE "else"
#define ENDIF "endif"

ReturnCode IfNotDefined(ActionInfo info)
{
	ReturnCode result = SUCCESS;
	Definition* definition = NULL;
	char* command = NULL;
	
	if (info.argc == 1)
	{
		definition = searchDefinitionByName(&info.controller->data, info.argv[0]);
		
		if (definition == NULL)
		{
			do
			{
				if (command != NULL)
				{
					free(command);
				}
				command = getNextCommand(info.controller);
				result = runCommand(info.controller, command);

			} while (strcmp(command, ELSE) != 0 || strcmp(command, ENDIF) != 0);

			while (strcmp(command, ENDIF) != 0)
			{
				if (command != NULL)
				{
					free(command);
				}
				command = getNextCommand(info.controller);
			}
			free(command);
		}
		else
		{
			do
			{
				if (command != NULL)
				{
					free(command);
				}
				command = getNextCommand(info.controller);
			} while (strcmp(command, ELSE) != 0 || strcmp(command, ENDIF) != 0);
			
			free(command);
		}
	}
	else
	{
		result = FAILURE;
	}

	return result;
}

#endif

