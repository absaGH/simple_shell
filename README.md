ALX - Simple Unix Like Shell
===========================
     C programming with ALX School!
================================================================================

## Description
    The implementation of a simple shell. A shell is a user intferace for access to an operating system's services. Shells use either a command-line interface or graphical user interface, depending on a computer's role and particular operation.
    You compile it with this command:
    (./hsh [arg...])

## Example
./hsh $ ls README.md main.c $

    or $ echo "/bin/ls" | ./hsh hsh main.c shell.c 'test_ls_2' $

This Shell is abled to use the built-ins:

    env: Use this command to print environment variables.

    exit: Use this command to exit our shell.

## Installation
- Clone the repo below
```
https://github.com/maleksal/simple_shell.git
```
- Compile with
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Files:
    shell.h: This file contains all the prototypes used for our shell project.

    AUTHORS: This file contains all the contributors to this repository.

    man_1_simple_shell: The man page for our shell.

    builtins.c: This file contains the code for the builtin functions of code.

    execute.c: Fork and execute a file.

## Authors
* [**Sertsedengle Shewandagn**](https://github.com/sertsev)
* [**Abebayehu Samuel**](https://github.com/absagh)