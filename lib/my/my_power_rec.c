/*
** my_power_rec.c for my_power_rec in /home/boulat_m/rendu/Piscine_C_J05
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Fri Oct  3 15:36:46 2014 Mickael BOULAT
** Last update Wed Oct  8 10:38:12 2014 Mickael BOULAT
*/

int	my_power_rec(int nb, int power)
{
  long	buffer;

  buffer = 0;
  if (power > -1)
    {
      if (power != 0)
	{
	  buffer = my_power_rec(nb, (power - 1));
	  return (buffer * nb);
	}
      else
	{
	  return (1);
	}
    }
  else
    {
      return (0);
    }
}
