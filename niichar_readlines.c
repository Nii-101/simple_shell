#include "shell.h"

/**
 * niichar_read_lines - function reads lines from a file or stdin
 *
 * Return: pointer to lines read as string
 */

char *niichar_read_lines(void)
{
	char *input_commands = NULL;
	size_t niichar_buffer_size = 0;

	if (getline(&input_commands, &niichar_buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input_commands);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input_commands);
			perror(niichar_shell_name);
			exit(EXIT_FAILURE);
		}
	}
	return (input_commands);
}
