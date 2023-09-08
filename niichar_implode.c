#include "shell.h"

/**
 * niichar_implode - implodes array of string into one string
 * @splitted_tokens: pointer to array of tokens
 * @needle: pointer to needle
 * Return: pointer to imploded string
 */

char *niichar_implode(char **splitted_tokens, char *needle)
{
    char *imploded_string = malloc(0);
    int token_index = 0, byte_size = 0;

    while (splitted_tokens[token_index] != NULL)
    {
        byte_size = strlen(splitted_tokens[token_index]) + 1 + strlen(needle) + 1;
        imploded_string = realloc(imploded_string, byte_size);
        if (token_index > 0)
        {
            strcat(imploded_string, needle);
        }

        strcat(imploded_string, splitted_tokens[token_index]);
        token_index++;
    }

    return (imploded_string);
}

