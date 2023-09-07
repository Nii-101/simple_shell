#ifndef MY_SHELL_H
#define MY_SHELL_H

#define ODAM_TOKEN_BUFFER_SIZE 64
#define ODAM_MAX_BUFFER_SIZE 1024
#define ODAM_TOKEN_SEPARATOR " \n\a\t\r"

/* HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <fcntl.h>

/* PROTOTYPES*/
int check_if_interactive(void);
void initiate_odam_interactive(void);
void initiate_odam_non_interactive(void);
char **parse_command_input(char *command_input, char *odam_separator);
void perform_actions(char **parsed_arguments);
char *get_command_path(char *command);
char *odam_implode(char **splitted_tokens, char *needle);
void execute_niichar_command(char **parsed_command);
char *odam_read_lines(void);
int is_niichar_whitespace(char *niichar_input_string);
char *odam_str_tokenizer(char *input_string, const char *separator);
int odam_echo(char **parsed_commands);
int is_odam_path_available(char *full_command_path);
int odam_write_error(char *imploded_command);
void odam_free_command_memory(char **parsed_command);
void odam_do_system_call(char *command_to_execute, char **parsed_arguments);
void odam_handle_file(char *file_name);
void odam_process_file(char *file_name);

/* NIICHAR_BUILT_IN_FUNCTIONS */
int niichar_exit(char **parsed_command);
int niichar_env(char **parsed_command);
int niichar_cd(char **parsed_command);

extern char **environ;
char *odam_shell_name;

typedef int (*Command)(char **args);

/**
 * struct built_in - a dog's basic info
 * @name: name of command
 * @command: pointer to command
 */
typedef struct built_in
{
	char *name;
	Command command;
} BuiltIn;

#endif /* MY_SHELL_H */
