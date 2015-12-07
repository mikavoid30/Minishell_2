/*
** my_put_nbr.c for my_put_nbr in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 20:25:59 2014 Mickael BOULAT
** Last update Sun Nov 16 21:43:35 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_nblen(int nb)
{
  int   i;

  i = 0;
  if (nb < 0)
    {
      nb = -nb;
      i++;
    }
  while (nb > 0)
    {
      i++;
      nb = nb / 10;
    }
  return (i);
}

char	*my_getstr(int nb, char *str)
{
  int	i;
  int	size;

  i = 0;
  size = my_nblen(nb);
  if ((str = malloc(size + 2)) != 0)
    {
      if (nb < 0)
	{
	  str[size - 1] = '-';
	  nb = -1 * nb;
	}
      while (nb > 0)
	{
	  str[i] = ((nb % 10) + 48);
	  nb = nb / 10;
	  i++;
	}
      str[size] = '\0';
    }
  str = my_revstr(str);
  return (str);
}
