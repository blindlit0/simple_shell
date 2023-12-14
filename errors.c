#include "shell.h"

/**
 * _print_str - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _print_str(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _write_stderr - writes the character c to stderr
 * @c: The char
 * Return: 1 on success.
 * On error, -1, and errno is set appropriately.
 */

int _write_stderr(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _write_fd - prototype that writes the char c to given fd
 * @c: char to print
 * @fd: filedescriptor to write to
 * Return: 1 on success.
 * On error, -1, and errno is set appropriately.
 */

int _write_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _print_input - funtion that prints an input string
 * @str: string to be printed
 * @fd: filedescriptor to write to
 * Return: num of chars put
 */

int _print_input(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
