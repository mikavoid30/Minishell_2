/*
** my_strlowcase.c for my_lowcase in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_08
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 11:23:08 2014 Mickael BOULAT
** Last update Tue Oct  7 20:46:56 2014 Mickael BOULAT
*/

char	*my_strlowcase(char *str)
{
  while (*str != 0)
    {
      if ((*str >= 'A') && (*str <= 'Z'))
	{
	  *str = *str + 32;
	}
      str++;
    }
  return (str);
}
