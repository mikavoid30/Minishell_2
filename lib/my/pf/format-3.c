/*
** format-3.c for format-3 in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov 15 11:14:03 2014 Mickael BOULAT
** Last update Sun Nov 16 22:01:56 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

char	*get_format_flags(char *command, t_conf *conf, t_format *format)
{
  while (is_a_flag(*(command + 1), conf))
    {
      format->flags = add_char(*(command + 1), format->flags);
      command++;
    }
  return (command);
}

char	*get_format_width(char *command, t_format *format)
{
  while (is_numeric(*(command + 1)))
    {
      format->width_str = add_char(*(command + 1), format->width_str);
      command++;
    }
  format->width = my_getnbr(format->width_str);
  return (command);
}

char	*get_format_precision(char *command, t_format *format)
{
  if (*(command + 1) == '.')
    {
      command++;
      while (is_numeric(*(command + 1)))
	{
	  format->precision_str = add_char(*(command + 1), format->precision_str);
	  command++;
	}
      format->precision = my_getnbr(format->precision_str);
    }
  return (command);
}

char	*get_format_prefix(char *c, t_conf *cf, t_format *format)
{
  char	(*f)(char, t_conf *);
  int	(*n)(char);
  char	(*t)(char, t_conf *);

  f = is_a_flag;
  n = is_numeric;
  t = is_a_type;
  while (!(*f)(*(c + 1), cf) && !(*n)(*(c + 1)) && !(*t)(*(c + 1), cf))
    {
      format->prefix = add_char(*(c + 1), format->prefix);
      c++;
    }
  return (c);
}

char	*get_format_type(char *command, t_conf *conf, t_format *format)
{
  if (is_a_type(*(command + 1), conf))
    {
      format->type = *(command + 1);
      command++;
    }
  else
    {
      my_putstr("Illegal instruction");
    }
  return (command);
}
