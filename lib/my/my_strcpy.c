/*
** my_strcpy.c for my_strcpy in /home/boulat_m/rendu/Semaine2/Piscine_C_J06
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Oct  6 08:57:33 2014 Mickael BOULAT
** Last update Tue Oct  7 19:18:08 2014 Mickael BOULAT
*/

char	*my_strcpy(char *dest, char *source)
{
  int	index;

  index = 0;
    while (source[index] !=  '\0')
    {
      dest[index] = source[index];
      index = index + 1;
    }
  dest[index] = '\0';
  return (dest);
}
