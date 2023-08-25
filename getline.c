#include "main.h"
#define INIT_BUFFER_SIZE 8000
/**
 * _getline - get line from stdin
 * @size: size of initial buffer
 * @str: pointer to *string output
 * @stream: input *stream
 * Return: *string pointer
 */
int _getline(char **str, int *size, FILE *stream)
{

	int fdr, pos = 0;
	char st;

	*size = INIT_BUFFER_SIZE;
	(void)*stream;
	*str = malloc(sizeof(char) * (*size));
	if (!*str)
	{
		return (0);
	}

	while (1)
	{
		fdr = read(STDIN_FILENO, &st, 1);
		if (fdr <= 0 || st == '\n')
		{
			(*str)[pos] = '\0';
			return (pos);
		}
		else
			(*str)[pos] = st;
		/*reallocate memory*/
		if (pos >= (*size - 2))
		{
			*size += INIT_BUFFER_SIZE;
			*str = _realloc(*str, (sizeof(char) * (*size)), (*size));
			if (*str == NULL)
				return (0);
		}
		pos++;
	}
	return (pos);

}
