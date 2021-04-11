#include "shell.h"

char *builtin_str[] = {
	"help", "exit"
};

int (*builtin_func[]) (char **) = {
	&sh_help, &sh_exit
};

/**
 * sh_num_builtins - findout the number of builtin commands
 *
 * Return: number of builtins
 */
int sh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *  sh_help - print help.
 *  @args: args List of args.
 *  Return: Always returns 1, to continue executing.
 */
int sh_help(char **args)
{
	_puts("Use the man command for information on other programs.\n");
	return (1);
}

/**
 *sh_exit - exit the line
 *Return: always zero
 */
int sh_exit(char **args)
{
	exit(0);
}

/**
 * sh_execute - Execute shell built-in or launch program.
 * @args: args Null terminated list of arguments.

 * Return 1 if the shell should continue running, 0 if it should terminate
 */
int sh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < sh_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (sh_launch(args));
}