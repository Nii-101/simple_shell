#include "shell.h"

/**
 * initiate_non_interactive - starts Niichar shell in non-interactive mode
 * Return: void
 */

void initiate_non_interactive(void)
{
    char *input;
    char **commands;

    while ((input = niichar_read_lines()) != NULL)
    {
        if (!niichar_is_whitespace(input))
        {
            commands = parse_input(input, NIICHAR_TOKEN_SEPARATOR);
            if (commands[0][0] != '#')
                execute_niichar_command(commands);
            niichar_free_memory(commands);
        }
        free(input);
    }
}

