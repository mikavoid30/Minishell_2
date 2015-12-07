/*
** my_strlen.c for my_strlen in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 10:14:23 2014 Mickael BOULAT
** Last update Thu Oct  2 11:41:02 2014 Mickael BOULAT
*/

int my_strlen(char *str)
{
  unsigned int	counter;

  counter = 0;
  while (*str != '\0')
    {
      counter = counter + 1;
      str = str + 1;
    }
  return (counter);
}
