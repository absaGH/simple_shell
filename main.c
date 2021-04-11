#include "shell.h"

/**
 *sh_launch - Launch a program and wait for it to terminate.
 *@args: Null terminated list of arguments (including program).
 *
 *Return: returns 1 on success
 */

int sh_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("ERORR");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("ERROR");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

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
 *
 *Return: nothing
 */
void sh_loop(void)
{
	char *line;
	char **args;
	int status;
	size_t len = 0;

	signal(SIGINT, sig_handler);
	_puts("$ ");
	while (getline(&line, &len, stdin) != -1)
	{
		args = sh_split_line(line);
		status = sh_execute(args);
		free(args);
		_puts("$ ");
	}
	free(line);
}

/**
 *main - main function for the shell
 *@argc: Argument count.
 *@argv: Argument vector.
 *@environment: array of environment variables.
 *
 *Return: exit status
 */
int main(int argc, char **argv,  char **environment)
{

	sh_loop();

	return (EXIT_SUCCESS);
}
