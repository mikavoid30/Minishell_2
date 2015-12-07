/*
** integer.c for integer in /home/boulat_m/rendu/Projets/CPE_2014_my_printf
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sun Nov 16 21:16:58 2014 Mickael BOULAT
** Last update Sun Nov 16 21:41:21 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

char	*format_precision(char *str, char *buff, t_format *format)
{
  int	size;
  int	plus;
  int	s;

  plus = is_in_tab('+', format->flags);
  size = my_strlen(str);
  s = size;
  if (format->precision > my_strlen(str))
    s = format->precision;
  if ((buff = malloc(s + 2)) != 0)
    {
      fill_str(buff, '0', (s + plus));
      if (plus && (my_getnbr(str) > 0))
	buff[0] = '+';
      my_strcpy(&buff[(s - size) + plus], str);
    }
  return (buff);
}

char	*format_width(char *str, char *buff, t_format *format)
{
  int	size;
  int	minus;
  int	s;

  minus = is_in_tab('-', format->flags);
  size = my_strlen(str);
  s = size;
  if (format->width > my_strlen(str))
    s = format->width;
  if ((buff = malloc(s + 2)) != 0)
    {
      fill_str(buff, ' ', s);
      if (minus)
	my_strncpy(&buff[0], str, my_strlen(str));
      else
	my_strncpy(&buff[s - size], str, my_strlen(str));
    }
  buff[s] = '\0';
  return (buff);
}

void	putinteger(void *arg, t_format *format)
{
  char  *buff2;
  char	*str;
  char	*res;

  str = NULL;
  str = my_getstr((int)arg, str);
  buff2 = my_strdup(str);
  res = buff2;
  buff2 = format_precision(str, buff2, format);
  res = format_width(buff2, res, format);
  my_putstr(res);
  free(str);
  free(res);
  free(buff2);
}
