/*
** my_putstrc.c for  in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/lib/my
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Nov 13 09:37:51 2014 Mickael BOULAT
** Last update Sat Nov 22 11:22:55 2014 Mickael BOULAT
*/

#include "my.h"

/* for debug only */

int	color_str(char *str, char *color)
{
  my_putstr(color);
  my_putstr(BOLD);
  my_putstr(str);
  my_putstr(INIT);
  my_putchar('\n');
  return (0);
}

int	green(char *str)
{
  color_str(str, GREEN);
  return (0);
}

int	cyan(char *str)
{
  color_str(str, CYAN);
  return (0);
}

int	yellow(char *str)
{
  color_str(str, YELLOW);
  return (0);
}

int	pink(char *str)
{
  color_str(str, MAGENTA);
  return (0);
}
