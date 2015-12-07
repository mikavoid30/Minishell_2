/*
** my_putstrc.c for  in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Nov 13 09:37:51 2014 Mickael BOULAT
** Last update Sat Nov 22 11:12:47 2014 Mickael BOULAT
*/

#include "my.h"

int	my_putchar_error(char c)
{
  write(2, &c, 1);
  return (0);
}

int	my_puterror(char *str)
{
  my_putstr(RED);
  my_putstr(BOLD);
  while (*str)
    {
      my_putchar_error(*str);
      str++;
    }
  my_putstr(INIT);
  my_putchar_error('\n');
  return (0);
}
