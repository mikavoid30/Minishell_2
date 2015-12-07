/*
** my_putstrr.c for my_putstrr in /home/boulat_m/rendu/Projets/minishell/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Nov  3 09:13:15 2014 Mickael BOULAT
** Last update Mon Nov 10 10:15:00 2014 Mickael BOULAT
*/

#include "my.h"

int	my_putstrr(char *str, char c)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
  my_putchar(c);
  return (0);
}
