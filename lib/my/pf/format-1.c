/*
** format.c for format in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov 15 11:03:28 2014 Mickael BOULAT
** Last update Fri Nov 21 08:51:55 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

void	my_free_conf(t_conf *conf)
{
  free(conf->flags);
  free(conf->convertions);
}

void	my_free_format(t_format *format)
{
  free(format->flags);
  free(format->width_str);
  free(format->precision_str);
  free(format->prefix);
}

void	init_conf(t_conf *conf)
{
  conf->flags = my_strdup("-+ 0#");
  conf->convertions = my_strdup("sdbxXoc");
}

void	init_format(t_format *format)
{
  if ((format->flags = malloc(1)) != 0)
    format->flags[0] = '\0';
  if ((format->width_str = malloc(1)) != 0)
    format->width_str[0] = '\0';
  if ((format->precision_str = malloc(1)) != 0)
    format->precision_str[0] = '\0';
  if ((format->prefix = malloc(1)) != 0)
    format->prefix[0] = '\0';
  format->type = '\0';
  format->precision = 0;
  format->width = 0;
}

void	fill_str(char *str, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      str[i] = c;
      str[i + 1] = '\0';
      i++;
    }
}
