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

###FILES
	- hsh : main shell executable file
	- main.h : main header file (contains all prototypes, built-in functions and headers)
	-
	-
	-
	-
	-
	-
	-
	-
	-

### TESTING

	- In interactive mode, the shell should work like this:

	$ ./hsh
	($) /bin/ls
	hsh main.c shell.c
	($)
	($) exit
	$

	- In non-interactive mode, the shell should work like this:
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
