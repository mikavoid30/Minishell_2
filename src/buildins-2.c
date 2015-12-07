/*
** buildins.c for buildins.c in /home/boulat_m/rendu/Projets/minishell
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Sat Nov  8 09:29:32 2014 Mickael BOULAT
** Last update Sun Nov 30 11:59:30 2014 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include "mysh.h"
#include "my.h"

char    *rem_end_n(char *path)
{
  char  *str;
  int   i;

  str = my_strdup(path);
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
        str[i] = '\0';
      i++;
    }
  return (str);
}

char    **exec_cd(char **argv, char **env)
{
  if (opendir(rem_end_n(argv[1])) != NULL)
    {
      env = exec_setenv(env, "PWD", argv[1]);
      chdir(rem_end_n(argv[1]));
    }
  else
    {
      perror(rem_end_n(argv[1]));
    }
  return (env);
}

char    **exec_buildin(char *name, char **argv, char **env, t_env_list *start)
{
  if (my_strcmp("cd", name) == 0)
    env = exec_cd(argv, env);
  else if (my_strcmp("env", name) == 0)
    my_show_list(start);
  else if (my_strcmp("setenv", name) == 0)
    {
      if (argv[1] != NULL)
	{
	  if (argv[2] != NULL)
	    {
	      env = exec_addenv(env, argv[1], argv[2]);
	    }	
	}   
    }
  return (env);
}

void	exec_interrupt(int signal)
{
  my_putstr("\n");
  print_prompt(GREEN);
  exit(0);
}

char	**check_buildins(char *user_command, char **env, t_env_list *start, t_paths *p)
{
  char	*command;
  int	status;
  t_env	*infos;
  pid_t	childpid;

  command = my_strdup(user_command);
  command = format(command, command);
  command = replace_variables(command, command, start);
  p->parsed = cut_d(command, p->parsed, ' ');
  //p->parsed = my_split(' ', command, p->parsed, &status);
  if (my_strstr(p->buildins, get_bin_name(command)) != 0)
    env = exec_buildin(p->parsed[0], p->parsed, env, start);
  else
    {
      childpid = fork();
      if (childpid == 0)
	{
	  signal(SIGINT, exec_interrupt);
	  p->parsed[0] = get_the_path(p->parsed[0], start, p);
	  execve(p->parsed[0], p->parsed, env);
	  free(command);
	  return (0);
	}
      wait();
    }
  return (env);
}
