/*
** my_strstr.c for my_strstr in /home/boulat_m/rendu/Semaine2/Piscine_C_J06/ex_04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Oct  6 14:12:58 2014 Mickael BOULAT
** Last update Tue Oct  7 21:38:11 2014 Mickael BOULAT
*/

typedef struct	s_values
{
  int i;
  int j;
  int buffer;
}		t_index;

int	my_strlen_str(char *str)
{
  int	counter;

  counter = 0;
  while (*str != '\0')
    {
      counter = counter + 1;
      str = str + 1;
    }
  return (counter);
}

char			*my_strstr(char *str, char *to_find)
{
  char			*res;
  struct s_values	val;

  if (my_strlen_str(to_find) == 0)
    return (str);
  val.i = 0;
  res = 0;
  while (str[val.i] != 0)
    {
      val.j = 0;
      if (str[val.i] == to_find[val.j])
	{
	  val.buffer = val.i;
	  while ((str[val.i] == to_find[val.j]) && (val.i < my_strlen_str(str)))
	    {
	      val.i++;
	      val.j++;
	    }
	  if (val.j == my_strlen_str(to_find))
	    res = &str[val.buffer];
	}
      else
	val.i++;
    }
  return (res);
}
