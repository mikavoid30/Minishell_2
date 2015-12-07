/*
** my_str_isprintable.c for my_str_isprintable in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_14
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 23:03:10 2014 Mickael BOULAT
** Last update Tue Oct  7 23:04:09 2014 Mickael BOULAT
*/

int	my_str_isprintable(char *str)
{
  int	res;

  res = 0;
  if (*str != 0)
    {
      while ((*str != '\0') && (res == 0))
	{
	  if ((*str < 32) || (*str > 126))
	    res = 1;
	  str++;
	}
    }
  else
    res = 1;
  return (res);
}
