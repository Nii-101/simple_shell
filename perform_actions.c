#include "shell.h"

/**
 * execute_operations - function to execute entered tasks
 * @parsed_args: parsed input arguments
 */
void execute_operations(char **parsed_args)
{
    char *full_cmd_path;

    if (is_custom_path_available(parsed_args[0]) == 1)
    {
        execute_custom_task(parsed_args[0], parsed_args);
    }
    else
    {
        full_cmd_path = retrieve_command_path(parsed_args[0]);
        execute_custom_task(full_cmd_path, parsed_args);
        free(full_cmd_path);
    }
}

/**
 * execute_custom_task - function to execute custom tasks
 * @command: actual command to execute
 * @parsed_args: parsed input arguments
 */
void execute_custom_task(char *command, char **parsed_args)
{
    pid_t process_id;
    char *combined_cmd;

    if (command != NULL)
    {
        process_id = fork();
        if (process_id == 0)
        {
            execve(command, parsed_args, NULL);
            perror(niichar_shell_name);
        }
        else if (process_id < 0)
        {
            perror(strcat(niichar_shell_name, " :1 : "));
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        combined_cmd = niichar_implode(parsed_args, " ");
        niichar_print_error(combined_cmd);
        free(combined_cmd);
    }
}

/**
 * is_custom_path_available - checks if provided command path exists
 * @full_cmd_path: full command path
 * Return: int
 */
int is_custom_path_available(char *full_cmd_path)
{
    int available = 0;

    if (access(full_cmd_path, F_OK) == 0 && access(full_cmd_path, X_OK) == 0)
    {
        available = 1;
    }
    return (available);
}

/**
 * niichar_print_error - prints error message to stderr
 * @combined_cmd: command as a string
 * Return: int
 */
int niichar_print_error(char *combined_cmd)
{
    char *error_msg;

    error_msg = malloc(NIICHAR_MAX_BUFFER_SIZE * sizeof(char));

    if (error_msg == NULL)
    {
        perror(niichar_shell_name);
        return (1);
    }

    snprintf(error_msg, 1024,
             "%s: 1: %s: command not found\n",
             niichar_shell_name, combined_cmd);

    write(STDERR_FILENO, error_msg, strlen(error_msg));
    free(error_msg);

    return (0);
}

