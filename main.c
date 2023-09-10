#include "niichar_shell.h"

/**
 *main - main entry to shell
 *
 *@argc: argument count
 *
 *@argv: string arguments
 *
 * Return: Returns 0 for success
 */

int main(int argc, char *argv[])
{
	niichar_shell_name = argv[0] == NULL ? "tsh" : argv[0];

	if (argc == 2)
	{
		niichar_process_file(argv[1]);
	}
	else
	{
		if (is_niichar_interactive() == 1)
		{
			initiate_niichar_interactive();
		}
		else
		{
			initiate_niichar_non_interactive();
		}
	}
	return (0);
}

