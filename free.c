#include "main.h"
/**
 * free_struct - frees a 1D structay grid
 * @f: poiter to a 1D structay
 * Return: Nothing
 */
void free_struct(input_t *f)
{
	int i;

	for (i = 0; f->argv[i] != NULL; i++)
	{
		free(f->argv[i]);
	}
	free(f->argv[i]);
	free(f->argv);

	for (i = 0; f->envp[i] != NULL; i++)
	{
		free(f->envp[i]);
	}
	free(f->envp[i]);
	free(f->envp);
}
