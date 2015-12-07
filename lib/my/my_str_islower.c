/*
** my_str_islower.c for my_str_islower in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_12
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 22:44:52 2014 Mickael BOULAT
** Last update Tue Oct  7 22:51:44 2014 Mickael BOULAT
*/

int	my_str_islower(char *str)
{
  int	res;

  res = 0;
  if (*str != 0)
    {
      while ((*str != '\0') && (res == 0))
	{
	  if ((*str < 'a') || (*str > 'z'))
	    res = 1;
	  str++;
	}
    }
  else
    res = 1;
  return (res);
}
