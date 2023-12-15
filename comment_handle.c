#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

/**
 * process_input - Process user input in the shell, ignoring comments.
 * @input: User input string.
 */

void process_input(char *input)
{
	char *comment_pos = strchr(input, '#');

	if (comment_pos != NULL)
	{
		*comment_pos = '\0';
	}

	printf("Processed input: %s\n", input);
}

/**
 * main - reads input from user using fgets and calls above function
 * Return: 0
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];

	printf("Enter command: ");
	fgets(input, sizeof(input), stdin);

	input[strcspn(input, "\n")] = '\0';

	process_input(input);

	return (0);
}
