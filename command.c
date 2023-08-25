#include "main.h"
/**
 * com_sort - sorts command names
 * @name: name of command
 * Return: path to the respective command program
 */
char *com_sort(char *name)
{
	char *temp = NULL, cwd[1024], *cmd_name, *cmd = NULL;

	temp = getcwd(cwd, sizeof(cwd));
	temp = malloc(sizeof(char) * (_strlen(cwd) + 1));
	if (temp == NULL)
		return (NULL);
	_strcpy(temp, cwd);
	if (_strncmp(name, "../", 3) == 0)
		return (absolute_path(temp, name));

	/*generate full path to command executable*/
	cmd_name = strtok(name, ".~/");
	cmd = malloc(sizeof(char) * (_strlen(name) + _strlen(temp) + 2));
	if (cmd != NULL)
	{
		_strcpy(cmd, temp);
		_strcat(cmd, "/");
		_strcat(cmd, cmd_name);
		_strcat(cmd, "\0");
	}
	free(temp);
	return (cmd);
}
/**
 * com_path - returns pathname to command
 * @cmd_name: name of command
 * Return: pathname to command
 */
char *com_path(char *cmd_name)
{
	char *cmd, *name, *path /*= "/bin/"*/;

	if (_strncmp(cmd_name, "./", 2) == 0 ||
		_strncmp(cmd_name, "../", 3) == 0)
	{
		return (com_sort(cmd_name));
	}
	else if (cmd_name[0] == '/')
	{
		name = strtok(cmd_name, " ");
		cmd = malloc(sizeof(char) * (_strlen(name) + 1));
		_strcpy(cmd, name);
	}
	else
	{
	path = com_search(cmd_name);
	printf("%s\n", path);
	fflush(stdout);
	cmd = malloc(sizeof(char) * (_strlen(cmd_name) + _strlen(path) + 2));
	if (cmd == NULL)
		perror("malloc in com_path failed\n");
	_strcpy(cmd, path);
	_strcat(cmd, "/");
	_strcat(cmd, cmd_name);
	printf("%s\n", cmd);
	}

	return (cmd);
}
