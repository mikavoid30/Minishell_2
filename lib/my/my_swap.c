/*
** my_swap.c for my_swap in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 09:15:07 2014 Mickael BOULAT
** Last update Fri Oct  3 18:59:28 2014 Mickael BOULAT
*/

int	my_swap(int *a, int *b)
{
  int	buffer;

  buffer = *a;
  *a = *b;
  *b = buffer;
  return (0);
}
