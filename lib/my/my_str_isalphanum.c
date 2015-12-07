/*
** my_str_isalpha.c for my_str_isalpha in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_10
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 22:05:02 2014 Mickael BOULAT
** Last update Sun Nov 16 22:08:08 2014 Mickael BOULAT
*/

int	my_str_isalphanum(char *str)
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
	  else if ((*str >= '0') && (*str <= '9'))
	    {
	      res = 0;
	    }
	  else
	      res = 1;
	  str++;
	}
    }
  else
    res = 1;
  return (res);
}
