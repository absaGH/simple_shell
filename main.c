#include "shell.h"

/**
 *sh_launch - Launch a program and wait for it to terminate.
 *@args: Null terminated list of arguments (including program).
 *@av: the name of the shell
 *@env: environment variable
 *@cont: count
 *
 *Return: returns 1 on success
 */
int sh_launch(char **args, char *av, char **env, unsigned int cont)
{

	pid_t pid;
	int status;
	char *program = NULL;
	struct stat st;

	if (stat(args[0], &st) == 0)
		program = _strdup(args[0]);
	else
	{
		program = _path(args[0],env);
		if (program == NULL)
		{
			free(program);
			print_e(av, args[0],cont);
			return (1);
		}
	}
	pid = fork();
	if (pid < 0)
		perror(av);
	if (pid == 0)
	{
		if (execve(program, args, env) == -1)
			perror(av);
	}
	else
		waitpid(pid, &status, 0);
	free(program);
	return (1);

}

/**
 *sh_split_line - Split a line into tokens.
 * @line: The line.
 *
 * Return: Null-terminated array of tokens.
 */
char **sh_split_line(char *line)
{
	size_t bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			tokens = _realloc(tokens, &bufsize);
			if (!tokens)
			{
				perror("ERROR");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 *sig_handler - handles ^C signal interupt
 *@uuv: unused variable
 *
 *Return: void
 */
static void sig_handler(int uuv)
{
	(void) uuv;

}

/**
 *sh_loop - getting input and executing it.
 *@av: the name of the shell
 *@env: environment variable
 *
 *Return: nothing
 */
void sh_loop(char *av, char **env)
{

	char *line;
	char **args;
	unsigned int cont;
	size_t len = 0;
	unsigned int is_stdin;

	cont = 0;
	is_stdin = 0;
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		is_stdin = 1;
	if (is_stdin == 0)
		_puts("$ ");
	while (getline(&line, &len, stdin) != -1)
	{
		cont++;
		if ((_strcmp(line, "\n")) == 0)
		{
			/* free(line); */
			_puts("$ ");
			continue;
		}
		args = sh_split_line(line);
		if (args[0] == NULL)
		{
			/* free(line); */
			dobfreer(args);
			_puts("$ ");
			continue;
		}
		sh_execute(args, av, env, cont);
		free(line);
		line = NULL;
		len = 0;
		if (is_stdin == 0)
			_puts("$ ");
	}

}

/**
 *main - main function for the shell
 *@argc: Argument count.
 *@argv: Argument vector.
 *@environment: array of environment variables.
 *
 *Return: exit status
 */
int main(int argc __attribute__((unused)), char **argv,  char **environment)
{

	char *p;
	p = argv[0];
	sh_loop(p, environment);
  
	return (EXIT_SUCCESS);
}
