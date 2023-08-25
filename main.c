#include "main.h"
/**
 * exec_section - implements a simple shell
 * @cmd: pointer to a struct
 * @av: program arguments
 * @num: tracks line number where error occurs
 * Return: Nothing
 */
int  exec_section(input_t *cmd, char **av, int num)
{
	pid_t pid1;
	int i;

	if (cmd->path[0] != '/')
		return (127);
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		return (2);
	}
	if (pid1 > 0)
		wait(NULL);
	if (pid1 == 0)
	{
		if (execve(cmd->path, cmd->argv, cmd->envp) == -1)
		{
			write(2, av[0], _strlen(av[0]));
			write(2, ": ", 2);
			write(2, to_strn(num), (_strlen(to_strn(num))));
			write(2, ": ", 2);
			for (i = 0; cmd->argv[i] != NULL; i++)
			{
				write(2, cmd->argv[i], _strlen(cmd->argv[i]));
				write(2, " ", 1);
			}
			write(2, ": not found\n", _strlen(": not found\n"));
			return (2);
		}
	}
	return (0);
}
/**
 * main - implements a simple shell
 * @ac: argument count
 * @av: arguments array
 * @envp: environment variables
 * Return: EXIT_SUCCESS
 */
int main(int ac, char **av, char **envp)
{
	input_t *cmd;
	int prompt_no = 1;

	(void)ac;
	(void)av;

	while (1)
	{
		cmd = get_input(envp);
		if (cmd == NULL)
			continue;
		_exiting(cmd);
		if (_strncmp(cmd->argv[0], "env", 3) == 0)
			_env(cmd, envp);
		else if (_strncmp(cmd->argv[0], "cd", 2) == 0)
		{
			_chdir(cmd);
		}
		else
			exec_section(cmd, av, prompt_no);

		/*free(args);*/
		free_struct(cmd);
		if (cmd->pathFlag == 0)
			free(cmd->path);
		free(cmd);
		prompt_no++;
	}

	return (EXIT_SUCCESS);
}
