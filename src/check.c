/*
** check.c for check in /home/boulat_m/rendu/Projets/minishell
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Nov  4 17:08:03 2014 Mickael BOULAT
** Last update Sun Nov 30 11:24:27 2014 Mickael BOULAT
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "list.h"
#include "mysh.h"
#include "my.h"

DIR     *get_directory(char *directory_name)
{
  DIR           *dir;
  struct stat   st;

  dir = NULL;
  stat(directory_name, &st);
  if ((dir = opendir(directory_name)) == NULL)
    dir = NULL;
  return (dir);
}

char    *check_slash(char *str, char *bin)
{
  int   size;
  char  *slash;

  size = my_strlen(str);
  if (str[size - 1] != '/')
    {
      if ((slash = malloc(size + 2)) != 0)
	{
	  slash = my_strcpy(slash, str);
	  slash[size + 0] = '/';
	  slash[size + 1] = '\0';
	}
    }
  return (my_strcat(slash, bin));
}

char		*check_dir(t_paths *p, t_env_list *start, struct dirent *dt, char *str)
{
  int		i;
  DIR		*dir;

  i = 0;
  while (i < p->nb_paths)
    {
      dir = get_directory(p->paths[i]);
      if (dir != NULL)
	{
	  while ((dt = readdir(dir)) != 0)
	    {
	      if (my_strcmp(dt->d_name, str) == 0)
		if (access(check_slash(p->paths[i], str), X_OK) >= 0)
		  return(check_slash(p->paths[i], str));
	    }
	}	  
      i++;
      if (i == p->nb_paths)
	if ((open(str, O_RDONLY) == -1) || (access(str, X_OK) < 0))
	  perror(str);
    }
  return (NULL);
}

char		*get_the_path(char *str, t_env_list *start, t_paths *p)
{
  int		i;
  char		*dir_name;
  struct dirent	*dt;
  char		**tab;

  i = 0;  
  if (access(str, X_OK) < 0)
    {
      str = check_dir(p, start, dt, str);
      return (str);
    }
  else
    return (str);
}
