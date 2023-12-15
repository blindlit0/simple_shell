#include "shell.h"

/**
 * _execute -function to exec commands, handle errors
 * @command: command read from stdin
 * @argv: argument vector
 * Return: status codes
*/

int _execute(char **command, char **argv)
{
pid_t child;
int status;
/*Forking processes and handling child processes*/
child  = fork();

/*If command is unrecognized*/
if (child == 0)
{
if (execve(command[0], command, environ) == -1)
{
perror(argv[0]);
freearray2D(command);
exit(0);
}

}
else
{
waitpid(child, &status, 0);
freearray2D(command);
}
return (WEXITSTATUS(status));
}
