#include "monty.h"

/**
 * is_only_digits - checks if a string contains only digits
 * @str: the string to check
 *
 * Return: 1 if the string contains only digits, otherwise, 0.
 */
int is_only_digits(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
		if (!isdigit(str[i]) && !(str[i] == '-' && i == 0))
			return (0);

	return (1);
}
