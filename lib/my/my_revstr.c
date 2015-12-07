/*
** my_strncpy.c for my_strncpy in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_02
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Oct  6 10:54:54 2014 Mickael BOULAT
** Last update Sun Nov 16 10:14:57 2014 Mickael BOULAT
*/

int	my_strlen_rev(char *str)
{
  int	counter;

  counter = 0;
  while (*str != '\0')
    {
      counter = counter + 1;
      str = str + 1;
    }
  return (counter);
}

char	*my_revstr(char *str)
{
  int	begin;
  int	end;
  char	buffer;
  int	src_length;

  buffer = ' ';
  src_length = my_strlen_rev(str);
  begin = 0;
  end = src_length - 1;
  while (begin <= end)
    {
      buffer = str[begin];
      str[begin] = str[end];
      str[end] = buffer;
      begin = begin + 1;
      end = end - 1;
    }
  str[src_length] = '\0';
  return (str);
}
