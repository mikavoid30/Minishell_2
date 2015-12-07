/*
** my_strncpy.c for my_strncpy in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_02
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Oct  6 10:54:54 2014 Mickael BOULAT
** Last update Tue Oct  7 19:29:44 2014 Mickael BOULAT
*/

int	my_strlen_ncpy(char *str)
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

char	*my_strncpy(char *dest, char *src, int n)
{
  int	index;
  int	src_length;

  src_length = my_strlen_ncpy(src);
  index = 0;
  while (index < n)
    {
      if (index < src_length)
	{
	  dest[index] = src[index];
	}
      else
	{
	  dest[index] = '\0';
	}
      index = index + 1;
    }
  return (dest);
}
