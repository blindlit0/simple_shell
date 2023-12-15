#include "shell.h"

/*Handling free when no commands are entered */
/**
 * freearray2D -frees dynamically allocated space for arrays
 * @arr : array
*/
void freearray2D(char **arr)
{
int i;
if (!arr)
{
return;
}


for (i = 0; arr[i]; i++)
{
free(arr[i]);
arr[i] = NULL;
}

free(arr), arr = NULL;
}
/*printf("%s\n", arr[i]);*/
