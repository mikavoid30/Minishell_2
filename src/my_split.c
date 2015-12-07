/*
** my_split.c for my_split in /home/boulat_m/rendu/Piscine_C/semaine2/Piscine_C_J08/ex_04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Nov 27 16:55:21 2014 Mickael BOULAT
** Last update Sun Nov 30 11:44:10 2014 Mickael BOULAT
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	count_words(char *str, char separator)
{
  int	counter;

  counter = 0;
  if (my_strlen(str) > 1)
    {
      counter = 1;
      while (*str)
	{
	  if (*str == separator)
	    counter++;
	  str++;
	}
    }
  return (counter);
}

int	set_word(char **tab, int j, char *word, char *c)
{
  int	size;
  int	i;
  int	x;

  x = 0;
  if (*c == '\0')
    x = -1;
  *c = '\0';
  size = my_strlen(word);
  i = 0;
  if ((tab[j] = malloc(100)) != 0)
    while (i < size)
      {
	tab[j][i] = word[i];
	i++;
      }
  tab[j][i] = '\0';
  j++;
  return (x);
}

char	*init_var(char *cpy, char *str, int *i, int *j)
{
  cpy = (char *)my_strdup(str);
  *i = 0;
  *j = 0;
  return (cpy);
}

char	*rem_cr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  str[i] = '\0';
  return (str);
}

char	**my_split(char separator, char *str, char **tab, int *nb_words)
{
  int	i;
  int	j;
  char	*word;
  char	*cpy;
 
  //  str = rem_cr(str);
  i = 0;
  cpy = NULL;
  cpy = init_var(cpy, str, &i, &j); 
  if ((tab = (char **)malloc((sizeof(char *) * (*nb_words = count_words(cpy, separator)))) + 1) != 0)
    {
      while (i != -1)
	{
	  if ((*cpy != separator) && (*cpy != '\0'))
	    {
	      if (0 == i++)
		word = cpy;
	    }	   
	  else
	    i = set_word(tab, j++, word, cpy);
	  cpy++;
	}
    }
  return (tab);
}
