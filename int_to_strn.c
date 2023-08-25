#include "main.h"
/**
 * to_strn - Converts an int to a string
 * @n: Integer to be converted to string
 * Return: Pointer to a string otherwise NULL
 */

char *to_strn(long int n)
{
	long int i, div = n, is_negative = n;
	char *str;

	if (n < 0)
	{
		div *= -1;
		for (i = 0; div > 0; i++)
		{
			div /= 10;
		}
		i++;
		n *= -1;

	}
	else
	{
		for (i = 0; div > 0; i++)
		{
			div /= 10;
		}
	}
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	*(str + i) = '\0';
	i--;
	for (; i >= 0; i--)
	{
		*(str + i) = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative < 0)
		str[0] = '-';
	return (str);
}
