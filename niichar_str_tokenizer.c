#include "niichar_shell.h"

/**
 * niichar_str_tokenizer - splits string into tokens
 * @input_string: pointer to string to tokenize
 * @separator: pointer to delimiters
 * Return: pointer to string of token
 */

char *niichar_str_tokenizer(char *input_string, const char *separator)
{
	char *initial, *terminal;
	static char *final_word;

	initial = (input_string == NULL) ? final_word : input_string;
	initial += strspn(initial, separator);

	if (*initial == '\0')
	{
		final_word = NULL;
		return (NULL);
	}

	terminal = initial + strcspn(initial, separator);

	if (*terminal != '\0')
		*terminal++ = '\0';

	final_word = terminal;
	return (initial);
}

