/*
** format-4.c for format-4 in /home/boulat_m/rendu/Projets/CPE_2014_my_printf/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov 15 11:18:35 2014 Mickael BOULAT
** Last update Sun Nov 16 21:31:01 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "mypf.h"
#include "my.h"

char	*check_format(const char *command, t_format *format, t_conf *conf)
{
  if (my_strlen((char *)command) > 1)
    {
      if (*(command + 1) != '%')
	{
	  command = get_format_flags((char *)command, conf, format);
	  command = get_format_width((char *)command, format);
	  command = get_format_precision((char *)command, format);
	  command = get_format_prefix((char *)command, conf, format);
	  command = get_format_type((char *)command, conf, format);
	}
    }
  return ((char *)command);
}
