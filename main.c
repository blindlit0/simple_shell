#include "shell.h"
/**
 * main - main function for simple shell
 * @ac: argument count
 * @argv: array of arguments
 * Return: prompt shell
*/

int main(int ac, char **argv)
{
char *line = NULL;
char **command = NULL;
int status = 0;
/*int i = 0;*/
(void) ac;
(void) argv;


while (1)
{
line = read_line();
/*Handling EOF*/
if (line == NULL)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "\n", 1);
}
return (status);
}

/*free(line);*/
command = tokenizer(line);
if (!command)
{
continue;
}
status = _execute(command, argv);

}
}

