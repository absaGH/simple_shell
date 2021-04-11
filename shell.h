#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

int sh_help(char **args);
int sh_exit(char **args);
int _strcmp(char *strcmp1, char *strcmp2);
char **_realloc(char **ptr, size_t *size);
int sh_launch(char **args);
int sh_execute(char **args);
char **sh_split_line(char *line);
void sh_loop(void);
ssize_t _puts(char *str);

#endif
