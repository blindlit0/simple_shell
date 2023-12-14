#include "main.h"

int command_length;

int stat(const char *pathname, struct stat *statbuff);
int directory_length;


/**
 * get_location - find location of command/path variable passed
*/
char *get_location(char *command)
{

char *path, *path_copy;
char *file_path;
char *path_token;
struct stat buffer;
path = getenv("PATH");

/* getenv gets env variable we need*/
/*Now to tokenization*/
if (path){
path_copy = strdup(path);

/*find length of command given*/
command_length = strlen(command);

/*delim in this case is ":"*/
path_token = strtok(path_copy, ":");

/**
 * Run loop using tokens
 * Append / to command and \0 at the end
 * Check for validity of path
*/

while (path_token != NULL)
{
directory_length = strlen(path_token);
file_path = malloc(command_length + directory_length + 2);
/*+ 2 since we'll append both "/" and "\0" -> 2 more chars*/

/*Copying token obained*/
strcpy(file_path, path_token);
strcat(file_path, "/");
strcat(file_path, command);
strcat(file_path, "\0");


if (stat(file_path, &buffer) == 0)
{
/**0 - success, file_path is valid
*/
free(path_copy);

return (file_path);
}
else 
{
free(file_path);
path_token = strtok(NULL, ":");
}

}


free(path_copy);

/* check if command itself is a file_path that exists*/

if (stat(command, &buffer) == 0)
{
return (command);
}

return (NULL);
}
return (NULL);
}
