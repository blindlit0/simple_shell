#include "shell.h"

/**
 * *read_line -func that reads stdin
 * @line : line read from stdin
 * Return: read line from stdin for subsequent tokenization
*/
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
ssize_t n;

if (isatty(STDIN_FILENO) == 1)
/*Display appropriate prompt*/
{
write(STDOUT_FILENO, "$ ", 2);
}

n = getline(&line, &len, stdin);
/*Handling Ctrl + D*/
if (n == -1)
{
free(line);
return (NULL);
}
return (line);
}
