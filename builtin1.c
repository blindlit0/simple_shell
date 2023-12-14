#include "shell.h"

/**
 * _historylist - shows history list, command by line,
 * line numbers first, starting at 0.
 * @info: struct that contains potential arguments.
 *  Return: 0
 */

int _historylist(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * strin_alias - sets alias to string
 * @info: parameter struct
 * @str: alias string
 * Return: 0 on success, 1 on failure
 */

int strin_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: alias string
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (strin_alias(info, str));

	strin_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * alias - prints out an alias string
 * @node: alias node
 * Return: 0 on success, 1 on failure
 */

int alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _mimalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */

int _mimalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			string_alias(info, info->argv[i]);
		else
			alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
