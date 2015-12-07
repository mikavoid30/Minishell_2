/*
** my_strncmp.c for my_strncmp in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_06
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 21:52:23 2014 Mickael BOULAT
** Last update Tue Oct  7 21:52:43 2014 Mickael BOULAT
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  if (n > 0)
    {
      while ((s2[i] == s1[i]) && (s1[i] != '\0') && (s2[i] != '\0') && (n > 0))
	{
	  i++;
	  n--;
	}
      if ((s2[i] != s1[i]) && (n > 0))
	res = res + (s1[i] - s2[i]);
    }
  else
    {
      res = res + (s1[0] - s2[0]);
    }
  return (res);
}
