# A README file for the ALX C SIMPLE SHELL PROJECT (COHORT 17)

## **AUTHORS**
	- Charles Nortey

	- Nii Odartey E. Lamptey

### _ Permitted Functions and System Calls For Project: 
	- access
	- chdir
	- close
	- closedir
	- execve
	- exit
	- __exit
	- fflush
	- fork
	- free
	- getcwd
	- getline
	- getpid
	- isatty
	- kill
	- malloc
	- open
	- opendir
	- perror
	- read
	- readdir
	- signal
	- stat (__xstat)
	- lstat (__lxstat)
	- fstat (__fxstat)
	- strtok
	- wait
	- waitpid
	- wait3
	- wait4
	- write_

### FILES
	- hsh : main shell executable file

	- niichar_shell.h : main header file (contains all prototypes, built-in functions and headers)

	- main.c : Main entry into the shell

	- general_niichar_functions.c : Contains the general functions for niichar shell

	- interactive_niichar_functions.c : Makes sure the shell is able to run in interactive mode

	- niichar_free_memory.c : Prevents memory leaks by freeing up memory

	- niichar_get_path.c : Gets the path for commands

	- niichar_handle_file.c : Handles a passed file

	- niichar_implode.c : Implodes an array of strings into one string

	- niichar_readlines.c : Reads lines from a file or stdin

	- niichar_str_tokenizer.c : Tokenizes strings of commands

	- non_interactive_niichar_functions.c : Makes sure shell is able to run in non-interactive mode

	- parse_command_input.c : Parses the command input

	- perform_actions.c : Contains a function to execute entered commands

### TESTING

	1. In interactive mode, the shell should work like this:

	$ ./hsh
	($) /bin/ls
	hsh main.c shell.c
	($)
	($) exit
	$

	2. In non-interactive mode, the shell should work like this:
	echo "/bin/ls" | ./hsh
    	hsh main.c shell.c test_ls_2
    	$
    	$ cat test_ls_2
    	/bin/ls
    	/bin/ls
    	$
    	$ cat test_ls_2 | ./hsh
    	hsh main.c shell.c test_ls_2
    	hsh main.c shell.c test_ls_2
    	$

#### _end of README file_
