/*
** format-2.c for format-2 in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov 15 11:06:27 2014 Mickael BOULAT
** Last update Sun Nov 16 22:05:34 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

char	*check_multiples_modulos(const char *command)
{
  char	*ret;

  if (my_strlen((char *)command) > 1)
    {
      if (*(command + 1) != '%')
	ret = (char *)command;
      else
	{
	  while ((*(command + 1) == '%') && (*command == '%'))
	    {
	      my_putchar('%');
	      command += 2;
	      ret = (char *)command;
	    }
	}
    }
  return (ret);
}

char	*add_char(char c, char *str)
{
  char	*cpy;
  int	size;

  cpy = NULL;
  size = my_strlen(str) + 1;
  if (size > 1)
    {
      cpy = my_strdup(str);
      if ((str = malloc(size + 1)) != 0)
	{
	  str = my_strcpy(str, cpy);
	  str[size - 1] = c;
	  str[size] = '\0';
	}
    }
  else
    {
      if ((str = malloc(2)) != 0)
	{
	  str[0] = c;
	  str[1] = '\0';
	}
    }
  free(cpy);
  return (str);
}

char	is_a_flag(char c, t_conf *conf)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (conf->flags[i])
    {
      if (conf->flags[i] == c)
	ret = 1;
      i++;
    }
  return (ret);
}

char	is_a_type(char c, t_conf *conf)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (conf->convertions[i])
    {
      if (conf->convertions[i] == c)
	ret = 1;
      i++;
    }
  return (ret);
}

int	is_numeric(char c)
{
  int	ret;

  ret = 0;
  if ((c >= '0') && (c <= '9'))
    ret = 1;
  return (ret);
}
