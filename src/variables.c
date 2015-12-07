/*
** variables.c for variables in /home/boulat_m/rendu/Projets/minishell
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Nov  6 14:51:21 2014 Mickael BOULAT
** Last update Sun Nov 30 11:15:56 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include "mysh.h"
#include "my.h"

char		*get_varcontent(t_env_list *start, char *name, char *s2)
{
  t_env_list	*current;

  current = start;
  while (current != NULL)
    {
      if (my_strcmp(current->var, name) == 0) 
	s2 = my_strdup(current->value);
      current = current->next;
    }
  return (s2);
}

char	*build_command(char *c, t_env_list *start, int i, t_str *s)
{
  if (i == 0)
    {
      s->s2 = get_varcontent(start, "HOME", s->s2);
      s->s3 = my_strdup(&c[i+1]);
      s->s2 = my_strcat(s->s2, s->s3);
      c = s->s2;
    }
  else if ((c[i - 1] == ' ') && ((c[i + 1] == '\n') || (c[i + 1] == '/')))
    {
      c[i] = '\0';
      s->s1 = my_strdup(c);
      s->s2 = get_varcontent(start, "HOME", s->s2);
      s->s3 = my_strdup(&c[i+1]);
      s->s1 = my_strcat(s->s1, rem_end_n(s->s2));
      s->s1 = my_strcat(s->s1, s->s3);
      c = s->s1;
    }
  return (c);
}

char	*check_home(char *c, t_env_list **start)
{
  t_str	*s;
  int	i;

  i = 0;
  if ((s = malloc(sizeof(t_str))) != 0)
    {
      while (c[i] != 0)
	{
	  if (c[i] == '~')
	    c = build_command(c, start, i, s);
	  i++;
	}
      return (c);
    }
  return (NULL);
}

char	*build_variables_command(char *c, t_str *s, t_env_list *start)
{
  if ((c[s->i] == '$') && (c[s->i + 1] != '\n'))
    {
      s->var = 1;
      c[s->i] = '\0';
      s->j = s->i + 1;
      s->s1 = my_strdup(c);
    }
  else if (((c[s->i] == '\0') || (c[s->i] == '\n') || (c[s->i] == ' ')) && s->var) 
    {
      s->var = 2;
      s->s3 = my_strdup(&c[s->i]);
      c[s->i] = '\0';
      s->s2 = &c[s->j];
    }
  if (s->var == 2)
    {
      s->var = 0;
      if ((c = malloc(my_strlen(s->s1) + my_strlen(s->s2) + my_strlen(s->s3) + 1)) != 0)
	{
	  c = my_strcat(c, s->s1);
	  c = my_strcat(c, get_varcontent(start, s->s2, s->s2));
	  c = my_strcat(c, s->s3);
	}
    }
  return (c);
}

char	*replace_variables(char *c, char *replaced, t_env_list *start)
{
  t_str	*s;
  char	*command;

  command = check_home(c, start);
  s = malloc(sizeof(t_str));
  s->i = 0;
  s->var = 0;
  while (command[s->i] != 0)
    {
      command = build_variables_command(command, s, start);
      s->i++;
    }  
  return (command);
}
