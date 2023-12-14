#include "shell.h"

/**
 * _curenv - prototype to print the current environment
 * @info: structure that contains potential arguments.
 * Return: 0
 */

int _curenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _fetchenv - fetches the value of an environ variable
 * @info: struct containing potential arguments.
 * @name: name of environment variable
 * Return: the value
 */

char *_fetchenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _newenv - Initializes a new environment variable,
 * or modifies one that exists already.
 * @info: Structure that contains potential arguments.
 *  Return: 0
 */

int _newenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _rmenv - remove an environ variable
 * @info: struct contains potential arguments.
 *  Return: 0
 */

int _rmenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * pop_env_list - prototype to populate environ linked list
 * @info: struct that contains potential arguments.
 * Return: 0
 */

int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
