#include "main.h"


/**
 * execmd - function that runs exec command
 * @argv: argument vector
*/

void execmd(char **argv)
{
char *command = NULL;
char *actual_command = NULL;

if (argv)
{
command = argv[0];

actual_command = get_location(command);

if (execve(actual_command, argv, NULL) == -1)
{
perror("Error: ");
};
}
}