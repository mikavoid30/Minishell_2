/*
** functions-2.c for functions-2 in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov 15 16:50:42 2014 Mickael BOULAT
** Last update Sun Nov 16 22:04:36 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

void	putstring(void *arg, t_format *format)
{
  int	size;
  char	*buff;
  int	p;

  size = 0;
  p = format->precision;
  if (format->precision > my_strlen((char *)arg))
    format->precision = my_strlen((char *)arg);
  if (format->precision > format->width)
    size = format->precision;
  else
    size = format->width;
  if ((buff = malloc(size + 1)) != 0)
    {
      fill_str(buff, ' ', size);
      if (is_in_tab('-', format->flags))
	my_strncpy(buff, (char *)arg, format->precision);
      else
	my_strncpy(&buff[size - p], (char *)arg, p);
    }
  my_putstr(buff);
}
