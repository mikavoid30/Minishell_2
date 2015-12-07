/*
** my_putstrc.c for  in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Nov 13 09:37:51 2014 Mickael BOULAT
** Last update Thu Nov 13 10:33:20 2014 Mickael BOULAT
*/

#include "my.h"

void	my_putcharc(char c, char *color, char bold)
{
  my_putstr(color);
  if (bold == 1)
      my_putstr(BOLD);
  my_putchar(c);
  my_putstr(INIT);
}
