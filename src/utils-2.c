/*
** utils-2.c for utils-2 in /home/boulat_m/rendu/Projets/minishell
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sun Nov  9 14:09:46 2014 Mickael BOULAT
** Last update Sun Nov 30 10:32:05 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include "list.h"
#include "mysh.h"
#include "my.h"

void			my_show_list(t_env_list *start)
{
  t_env_list		*current;
  int			i;

  i = 0;
  current = start;
  while (current != NULL)
    {
      my_putstrc(current->var, BLUE, 1);
      my_putstr(" -> ");
      my_putstrc(current->value, CYAN, 0);
      my_putchar('\n');
      current = current->next;
    }
}

void    fill(t_env_list *current, char *str)
{
  int	i;

  i = 0;
  current->var = my_strdup(str);
  while (current->var[i])
    {
      if (current->var[i] == '=')
	{
	  current->var[i] = '\0';
	  current->value = &current->var[i + 1];
	}
      i++;
    }
  current->next = NULL;
}

int			my_putstr_end_list(t_env_list **start, char *str)
{
  t_env_list		*current;
  t_env_list		*last;

  if ((current = malloc(sizeof(t_env_list))) != 0)
    {
      if ((current->data = malloc(my_strlen(str) + 1)) != 0)
        {
          fill(current, str);
          last = *start;
          if (last != NULL)
            {
              while (last->next != NULL)
                last = last->next;
              last->next = current;
	    }
          else
            *start = current;
        }
    }
  return (0);
}

void	my_putstrc(char *str, char* color, char bold)
{
  my_putstr(color);
  if (bold)
    my_putstr("\033[1m");
  my_putstr(str);
  my_putstr(INIT);
}

void	my_putstrnc(char *str, char* color, char bold)
{
  my_putstr(color);
  if (bold)
    my_putstr("\033[1m");
  my_putstr(str);
  my_putstr(INIT);
  my_putchar('\n');
}

void		my_get_env(char **env, t_env_list **begin, t_paths *p)
{
  int		i;
  t_env_list	*start;
  int		nb;

  i = 0;
  while (env[i])
    {
      my_putstr_end_list(begin, env[i]);
      i++;
    }
  start = *begin;
  while (start != NULL)
    {
      p->buildins = my_strdup("cd:setenv:getenv:env:exit");
      if (my_strcmp(start->var, "PATH") == 0)
	{
	  p->paths = my_split(':', start->value, p->paths, &nb);
	  p->nb_paths = nb;	
	  my_put_nbrn(p->nb_paths);  
	}
      start = start->next;
    }
}

char	*format(char *str, char *ret)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  if((i != 0) && (str[i - 1] != ' ') && (str[i + 1] != '\n'))
	    {
	      ret[j] = str[i];
	      j++;
	    }
	}
      else
	{
	  ret[j] = str[i];
	  j++;
	}
      i++;
    }
  ret[j] = '\n';
  ret[j + 1] = '\0';
  return (ret);
}
