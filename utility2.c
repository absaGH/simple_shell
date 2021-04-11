#include "shell.h"

/**
 * env_variable - function that generates string array with PATH directories
 * @dir_tmp: temporary directory
 * @text: string array with user input data
 * Return: string array with PATH directories
 */
char *env_variable(char *dir_tmp, char *text)
{

  char *path = NULL, *token = NULL;
  struct stat stark;

  token = strtok(dir_tmp, ":");
  while (token)
    {
      path = malloc(_strlen(token) + 1 + _strlen(text) + 2);
      _strcpy(path, token);
      _strcat(path, text);
      if (stat(path, &stark) == 0 && stark.st_mode & S_IXUSR)
	return (path);
      token = strtok(NULL, ":");
      free(path);
    }
  return (NULL);
}


/**
 * _path - function  that get PATH
 * @text: string with data entered by the user
 * @env: pointer to environment variable
 * Return: string array
 */

char *_path(char *text, char **env)
{
  char *path = NULL, *dir_tmp = NULL;

  dir_tmp = getenv_("PATH", env);
  path = env_variable(dir_tmp, text);
  free(dir_tmp);
  return (path);
}


/**
 * getenv_ - function  that get the value of the environment variable
 * @name: variable name
 * @env: pointer to environment variable
 * Return: string with the value of the environment variable
 */
char *getenv_(char *name, char **env)
{
  char *token;
  int x = 0;
  char *tmp, *str;

  while (env[x])
    {
      tmp = _strdup(env[x]);
      token = strtok(tmp, "=");
      if (_strcmp(name, token) == 0)
	{
	  token = strtok(NULL, "=");
	  str = _strdup(token);
	  free(tmp);
	  return (str);
	}
      free(tmp);
      x++;
    }
  return (NULL);
}

/**
 * *_strcpy - print character
 * @src: pointr character
 * @dest : poinr character
 * Return: 0
 */
char *_strcpy(char *dest, char *src)
{
  int n;

  for (n = 0; src[n] != 0; n++)
    {
      dest[n] = src[n];
    }
  dest[n] = '\0';
  return (dest);
}

/**
 * *_strcat - print character
 * @src: pointr character
 * @dest : poinr character
 * Return: new concatenated string
 */
char *_strcat(char *dest, char *src)
{
  int i, j;

  i = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  dest[i++] = '/';
  j = 0;
  while ((dest[i++] = src[j++]) != '\0')
    {
    }
  dest[i] = '\0';
  return (dest);
}
