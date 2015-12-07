/*
** main.c for my_ls in /home/boulat_m/rendu/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:06:14 2014 Mickael BOULAT
** Last update Sun Nov 30 11:52:26 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"

int	get_nb_words(char *line, char separator)
{
  int	nb;

  nb = 1;
  while (*line)
    {
      if (*line == separator)
	nb++;
      line++;
    }
  return (nb);
}

char	**initt(char **tab, char *line, char separator)
{
  int	k;
  int	nb_words;

  k = 0;
  tab = NULL;
  nb_words = get_nb_words(line, separator);
  
  if ((tab = malloc((nb_words * sizeof(char*)) + sizeof(char*))) != 0)
    {
      while (k < nb_words)
	{
	  if ((tab[k] = malloc(1000)) != 0)
	    my_memset(tab[k], 1000);
	  k++;
	}
      tab[k] = NULL;
    }
  return (tab);
}

char	**cut_d(char *line, char **tab, char separator)
{
  int	i;
  int	k;
  int	j;

  i = 0;
  j = 0;
  k = i;
  tab = initt(tab, line, separator);
  while (line[i] != '\n')
    {
      if (line[i] != ' ')
	{
	  tab[j][k] = line[i];
	  tab[j][k + 1] = '\0';
	}
      else
	{
	  j++;
	  k = -1;
	}
      i++;
      k++;
    }
  return (tab);
}
