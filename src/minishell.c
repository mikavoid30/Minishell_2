/*
** main.c for my_ls in /home/boulat_m/rendu/my_ls
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Tue Oct 28 10:06:14 2014 Mickael BOULAT
** Last update Sun Nov 30 10:25:03 2014 Mickael BOULAT
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
#include <string.h>

void	print_prompt(char *color)
{
  my_putstrc("\rBazinga", color, 1);
  my_putstrc(" $> ", CYAN, 1);
}

void	my_handle(int sig)
{
  my_putstr("\n");
  print_prompt(GREEN);
}

int		main(int argc, char **argv, char **env)
{
  int		child_pid;
  char		user_command[BUFF_SIZE];
  t_paths	p;
  t_env_list	*start;
  char		*command;

  start = NULL;
  my_get_env(env, &start, &p);
  while (42)
    {
      signal(SIGINT, my_handle);
      print_prompt(GREEN);
      if ((command = get_next_line(1)) == NULL)
	{
	  my_putchar('\n');
	  return (0);
	}
      if (my_strlen(command) > 1)
	check_buildins(command, env, start, &p);
    }
  return (0);
}
