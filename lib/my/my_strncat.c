/*
** my_strcat.c for my_strcat in /home/boulat_m/rendu/Semaine2/Piscine_C_J07
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct  7 14:36:58 2014 Mickael BOULAT
** Last update Mon Nov 10 10:00:10 2014 Mickael BOULAT
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while ((src[j] != '\0') && (nb > 0))
    {
      dest[i + j] = src[j];
      j++;
      nb--;
    }
  dest[i + j] = '\0';
  return (dest);
}
