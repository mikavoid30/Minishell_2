/*
** my_putstrn.c for my_putstrn in /home/boulat_m/rendu/Projets/minishell/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Nov  3 09:12:03 2014 Mickael BOULAT
** Last update Mon Nov 10 10:14:49 2014 Mickael BOULAT
*/

#include "my.h"

int	my_putstrn(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
  my_putchar('\n');
  return (0);
}
