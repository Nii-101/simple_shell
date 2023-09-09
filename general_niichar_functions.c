nclude "shell.h"

/**
 * is_niichar_interactive - checks whether shell is in interactive mode
 *
 * Return: 1 or 0 as int
 *
 */

int is_niichar_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * execute_niichar_command - function to execute command
 * @parsed_command: pointer to parsed commands
 * Return: void
 *
 */

void execute_niichar_command(char **parsed_command)
{
	BuiltIn niichar_built_in_functions[4] = {
		{"exit", niichar_exit},
		{"env", niichar_env},
		{"cd", niichar_cd},
		{"echo", niichar_echo}
	};
	int niichar_built_in_num, is_built_in = 0, niichar_counter = 0;

	niichar_built_in_num = sizeof(niichar_built_in_functions) /
		sizeof(niichar_built_in_functions[0]);

	while (niichar_counter < niichar_built_in_num)
	{
		if (strcmp(parsed_command[0],
					niichar_built_in_functions[niichar_counter].name) == 0)
		{
			is_built_in = 1;
			niichar_built_in_functions[niichar_counter].command(parsed_command);
			break;
		}
		niichar_counter++;
	}

	if (is_built_in == 0)
		perform_actions(parsed_command);
}

/**
 * niichar_is_white_space - checks if
 *
 * string contains only whitespace characters
 *
 * @input_string: pointer to string to check
 *
 * Return: 1 if whitespace else 0
 *
 */

int niichar_is_white_space(char *input_string)
{
	int is_white = 1, niichar_counter = 0;

	while (input_string[niichar_counter])
	{
		if (!isspace(input_string[niichar_counter]))
		{
			is_white = 0;
			break;
		}

		niichar_counter++;
	}

	return (is_white);
}
