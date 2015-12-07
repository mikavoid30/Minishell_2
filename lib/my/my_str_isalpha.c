/*
** my_str_isalpha.c for my_str_isalpha in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_10
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 22:05:02 2014 Mickael BOULAT
** Last update Tue Oct  7 22:30:38 2014 Mickael BOULAT
*/

int	my_str_isalpha(char *str)
{
  int	res;

  res = 0;
  if (*str != 0)
    {
      while ((*str != '\0') && (res == 0))
	{
	  if ((*str >= 'A') && (*str <= 'z'))
	    {
	      if ((*str > 'Z') && (*str < 'a'))
		res = 1;
	    }
	  else
	    {
	      res = 1;
	    }
	  str++;
	}
    }
  else
    res = 1;
  return (res);
}
