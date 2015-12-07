/*
** utils-1.c for utils-1 in /home/boulat_m/rendu/Projets/minishell
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sun Nov  9 14:08:53 2014 Mickael BOULAT
** Last update Sun Nov 30 10:30:41 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"
#include "my.h"

int	is_this_var(char *var, char *str)
{
  int	ok;
  int	i;

  ok = 1;
  i = 0;
  while (*var)
    {
      if (*var != str[i])
	{
	  ok = 0;
	}
      var++;
      i++;
    }
  if ((ok == 1) && (str[i] != '='))
    {
      ok = 0;
    }
  return (ok);
}

int	get_nb_paths(char *path_line)
{
  int	nb;

  nb = 1;
  while (*path_line)
    {
      if (*path_line == ':')
	nb++;
      path_line++;
    }
  return (nb);
}

void	my_memset(char *str, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      str[i] = '\0';
      i++;
    }
}
