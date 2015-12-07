/*
** my_strdup.c for my_strdup in /home/boulat_m/rendu/semaine2/Piscine_C_J08/ex_01
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Wed Oct  8 12:51:17 2014 Mickael BOULAT
** Last update Mon Nov 10 10:09:55 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*ret;
  int	size;
  int	i;

  size = my_strlen(src);
  i = 0;
  ret = 0;
  if (size > 0)
    {
      ret = malloc(size + 1);
      if (ret)
	{
	  while (src[i])
	    {
	      ret[i] = src[i];
	      i++;
	    }
	}
    }
  return (ret);
}
