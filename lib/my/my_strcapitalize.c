/*
** my_strcapitalize.c for my_strcapitalize in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_09
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 11:39:32 2014 Mickael BOULAT
** Last update Tue Oct  7 21:57:32 2014 Mickael BOULAT
*/

int	check_my_char(char c)
{
  int res;
  if ((c == '+') || (c == '-') || (c == ' '))
    res = 0;
  else if ((c >= 'a') && (c <= 'z'))
    res = 1;
  else if ((c >= 'A') && (c <= 'Z'))
    res = 2;
  else
    res = 3;
  return (res);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((i == 0) && (check_my_char(str[i]) == 1))
	str[i] = str[i] - 32;
      else
	{
	  if (check_my_char(str[i - 1]) != 0)
	    {
	      if (check_my_char(str[i]) == 2)
		str[i] = str[i] + 32;
	    }
	  else
	    {
	      if (check_my_char(str[i]) == 1)
		str[i] = str[i] - 32;
	    }
	}
      i++;
    }
  return (str);
}
