#include "main.h"

/**
 * _getenv - gets environment variable
 * @name: name of the variable
 * Return: string with value of environment variable
 */

char *_getenv(const char *name)
{
	int i, len = 0;
	char *tmp = NULL;

	len = _strlen((char *)name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp((char *)name, environ[i], len) == 0)
		{
			return (environ[i]);
		}
	}
	return (tmp);
}
