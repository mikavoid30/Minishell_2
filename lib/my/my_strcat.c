/*
** my_strcat.c for my_strcat in /home/boulat_m/rendu/Semaine2/Piscine_C_J07
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 14:36:58 2014 Mickael BOULAT
** Last update Tue Oct  7 15:06:36 2014 Mickael BOULAT
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i + j] = src[j];
      j++;
    }
  dest[i + j] = '\0';
  return (dest);
}
