/*
** my_strcmp.c for strcmp in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_05
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 20:18:39 2014 Mickael BOULAT
** Last update Tue Oct  7 20:19:53 2014 Mickael BOULAT
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while ((s2[i] == s1[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  if (s2[i] != s1[i])
    res = res + (s1[i] - s2[i]);
  return (res);
}
