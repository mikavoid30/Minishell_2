/*
** my_putchar.c for my_putchar in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Fri Oct  3 23:18:43 2014 Mickael BOULAT
** Last update Mon Nov 10 10:05:31 2014 Mickael BOULAT
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
