#include "shell.h"

/**
 * builtin_fun - Execute builtin_fun.
 * @args: args Null terminated list of arguments.
 * @env: variable that contain the current environment
 * Return nothing
 */

void (*builtin_fun(char **args, char **env))(char **args, char **env)
{
builtins_t b[] = {
	{"exit", sh_exit},
	{"env", sh_env},
	{NULL, NULL}
};

int i;

for (i = 0; b[i].f != NULL; i++)
{
	if (_strcmp(args[0], b[i].name) == 0)
	  break;
}
 if (b[i].f != NULL)
   b[i].f(args, env);
 return (b[i].f);
}

/**
 * sh_exit - Builtin command: exit.
 * @args: List of args.
 * @env: variable that contain the current environment
 * Return: Always returns 0, to terminate execution.
 */

void sh_exit(char **args, char **env __attribute__((unused)))
{
	dobfreer(args);
	exit(0);
}

/**
 * sh_env - prints the current environment
 * @args: list of arguments
 * @env: variable that contain the current environment
 * Return: void.
 */

void sh_env(char **args __attribute__((unused)), char **env)
{
	unsigned int i;

	for (i = 0; env[i]; i++)
	{
		_puts(env[i]);
		_puts("\n");
	}
}

/**
 * sh_execute - Execute shell built-in or launch program.
 * @args: args Null terminated list of arguments.
 * @av: the program name
 * @env: variable that contain the current environment
 * @cont: excution/command counter
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */

int sh_execute(char **args, char *av, char **env, unsigned int cont)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (builtin_fun(args, env) != NULL)
	  return 1;

	return (sh_launch(args, av, env, cont));
}
