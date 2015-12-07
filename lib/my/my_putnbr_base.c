/*
** my_putnbr_base.c for my_putnbr_base in /home/boulat_m/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Wed Oct  8 16:21:34 2014 Mickael BOULAT
** Last update Sun Nov 16 22:07:18 2014 Mickael BOULAT
*/

#include "my.h"

int	my_putnbr_base(int nbr, char *str)
{
  int	i;
  char	n;

  n = nbr;
  i = 0;
  if (my_str_isalphanum(str) == 0)
  {
      if (nbr < 0)
	{
	  nbr = -nbr;
	  my_putchar('-');
	}
      while (nbr >= my_power_rec(my_strlen(str), i))
	  i++;
      i--;
      while (i >= 0)
	{
	  my_putchar(str[nbr/my_power_rec(my_strlen(str), i)]);
	  nbr = nbr % my_power_rec(my_strlen(str), i);
	  i--;
	}
      }
  return (n);
}
