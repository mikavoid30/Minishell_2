/*
** my_str_isnum.c for my_str_isnum in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_11
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 22:33:06 2014 Mickael BOULAT
** Last update Tue Oct  7 22:40:17 2014 Mickael BOULAT
*/

int	my_str_isnum(char *str)
{
  int	res;

  res = 0;
  if (*str != 0)
    {
      while ((*str != '\0') && (res == 0))
	{
	  if ((*str < '0') || (*str > '9'))
	    res = 1;
	  str++;
	}
    }
  else
    res = 1;
  return (res);
}
