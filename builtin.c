#include "shell.h"

/**
 * builtin_fun - Execute builtin_fun.
 * @args: args Null terminated list of arguments.
   
 * Return nothing
 */

void builtin_fun(char **args)
{
  builtins_t b[] = {
    {NULL, NULL}
  };
  int i;
  for (i = 0; b[i].f != NULL; i++)
    {
      if(_strcmp(args[0], b[i].name) == 0)
	b[i].f(args);
    }
}

/**
 * sh_execute - Execute shell built-in or launch program.
 * @args: args Null terminated list of arguments.
 *
 * Return 1 if the shell should continue running, 0 if it should terminate
 */
int sh_execute(char **args, char *av, char **env, unsigned int cont)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	builtin_fun(args);	

	return (sh_launch(args, av, env, cont));
}
