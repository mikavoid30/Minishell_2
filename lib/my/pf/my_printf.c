/*
** main.c for my_printf in /home/boulat_m/rendu/Projets/CPE_2014_my_printf
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Nov 10 09:48:03 2014 Mickael BOULAT
** Last update Sun Nov 16 23:36:05 2014 Mickael BOULAT
*/

#include <stdio.h>
#include <stdarg.h>
#include "mypf.h"
#include "my.h"

static t_fcts  f_fcts[] =
  {
    {'b', putbinary},
    {'x', puthexa},
    {'X', puthexamax},
    {'d', putinteger},
    {'s', putstring},
    {'c', put_char},
    {'o', putoctal},
    {'\0', NULL},
  };

int	get_index(char c)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (f_fcts[i].action != NULL)
    {
      if (c == f_fcts[i].c)
	res = i;
      i++;
    }
  return (res);
}

int	is_in_tab(char c, char *str)
{
  int	res;

  res = 0;
  while (*str)
    {
      if (*str == c)
	res = 1;
      str++;
    }
  return (res);
}

int		my_printf(const char *command, ...)
{
  t_conf	conf;
  t_format	format;
  va_list	ap;

  init_conf(&conf);
  va_start(ap, command);
  while (*command)
    {
      if (*command == '%')
	{
	  init_format(&format);
	  command = check_multiples_modulos(command);
	  if (command[0] == '%')
	    {
	      command = check_format(command, &format, &conf);
	      f_fcts[get_index(*command)].action(va_arg(ap, void *), &format);
	    }
	  my_free_format(&format);
	}
      else
	my_putchar(*command);
      command++;
    }
  va_end(ap);
  my_free_conf(&conf);
  return (0);
}
