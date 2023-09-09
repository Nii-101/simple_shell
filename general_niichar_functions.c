#include "my_shell.h"

/**
 * check_if_interactive - checks whether shell  is in interactive mode
 * Returns:
 *   1 if the shell is in interactive mode
 *   0 if the shell is not in interactive mode
 */

int check_if_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * execute_niichar_command - function to execute a niichar command
 * @parsed_command: pointer to parsed niichar commands
 * Returns: void
 */
void execute_niichar_command(char **parsed_command)
{
	BuiltIn niichar_built_in_functions[4] = {
		{"niichar_exit", niichar_exit},
		{"niichar_env", niichar_env},
		{"niichar_cd", niichar_cd},
		{"niichar_echo", niichar_echo,
	};

	int niichar_commands_size = sizeof(niichar_commands);
	int niichar_command_size = sizeof(niichar_commands[0]);
	int num_niichar_commands = niichar_commands_size / niichar_command_size;
	int is_niichar_command = 0;

	for (int i = 0; i < num_niichar_commands; i++)
	{
		if (strcmp(parsed_command[0], niichar_commands[i].name) == 0)
		{
			is_niichar_command = 1;
			niichar_commands[i].command(parsed_command);
			break;
		}
	}

	if (!is_niichar_command)
	{
		perform_niichar_actions(parsed_command);
	}
}

/**
 * is_niichar_whitespace - checks if a string contains only niichar whitespace characters
 * @niichar_input_string: pointer to the string to check
 * Returns:
 *   1 if the string contains only niichar whitespace characters
 *   0 if the string contains non-niichar whitespace characters
 */
int is_niichar_whitespace(char *niichar_input_string)
{
	int is_white = 1, counter = 0;

	while (niichar_input_string[counter])
	{
		if (!isspace(niichar_input_string[counter]))
	{
		is_white = 0;
		break;
	}

		counter++;
	}

	return (is_white);
}
