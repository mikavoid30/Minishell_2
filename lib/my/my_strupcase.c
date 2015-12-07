/*
** my_strupcase.c for my_strupcase in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_07
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 10:37:07 2014 Mickael BOULAT
** Last update Tue Oct  7 21:11:18 2014 Mickael BOULAT
*/

char	*my_strupcase(char *str)
{
  while (*str != 0)
    {
      if ((*str >= 'a') && (*str <= 'z'))
	{
	  *str = *str - 32;
	}
      str++;
    }
  return (str);
}
