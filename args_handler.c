#include "main.h"

/**
 * space_check - checks for long spaces
 * @str: input from standard input / command line
 * Return: pointer to string arguments else NULL
 */
char *space_check(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			return (str);
	}
	return (NULL);
}
/**
 * cmd_arg - returns commandline string arguments
 * @str: input from standard input / command line
 * Return: pointer to string arguments
 */
char **cmd_arg(char *str)
{
	char *temp, **token, *str3 = NULL, *str2 = NULL, delim[] = " \n";
	int i = 1, k = 0;

	str2 = malloc(sizeof(char) * (_strlen(str) + 1));
	if (str2 == NULL)
		return (NULL);
	_strcpy(str2, str);
	str3 = malloc(sizeof(char) * (_strlen(str) + 1));
	if (str3 == NULL)
		return (NULL);
	_strcpy(str3, str);
	temp = strtok(str3, delim);
	while (temp)
	{
		temp = strtok(NULL, delim);
		i++;
	}
	/* allocate memory and copy tokens to arguments array*/
	token = malloc(sizeof(char *) * i);
	if (token == NULL)
		return (NULL);
	temp = strtok(str2, delim);
	for (k = 0; k < (i - 1); k++)
	{
		token[k] = malloc(sizeof(char) * (_strlen(temp) + 1));
		if (token[k] == NULL)
			return (NULL);
		_strcpy(token[k], temp);
		temp = strtok(NULL, delim);
	}
	token[i - 1] = NULL;
	free(str2);
	free(str3);
	if (token[0] == NULL)
	{
		free(token[0]);
		free(token);
		return (NULL);
	}
	return (token);
}
