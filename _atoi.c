#include "shell.h"

/**
 * interact - should work true if the shell is interactive
 * @info: address of struct
 * Return: 1 when interactive mode is a success,
 * and 0 if not
 */

int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * check_char_delim - prototype to check if a char is a delimeter
 * @c: this is the char to be checked
 * @delim: delimeter string
 * Return: 1 if char is a delimeter, and
 * 0 if the char is not
 */

int check_char_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalphabet - prototype to check if there is a character of the alphabet
 *@c: input char
 *Return: 1 if the input char is alphabetic and
 *0 if not
 */

int _isalphabet(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - prototype to convert a string to an integer
 *@s: string to be converted to integer
 *Return: 0 of conversion failed
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
