##
## Makefile for Makefile in /home/boulat_m/rendu/Projets/minishell
## 
## Made by Mickael BOULAT
## Login   <boulat_m@epitech.net>
## 
## Started on  Tue Nov  4 17:24:28 2014 Mickael BOULAT
## Last update Wed Dec 17 14:55:11 2014 Mickael BOULAT
##

RM	= rm -f

SRCS	= src/minishell.c \
	  src/parsing.c \
	  src/variables.c \
	  src/check.c \
	  src/buildins.c \
	  src/buildins-2.c \
	  src/utils-1.c \
	  src/utils-2.c \
	  src/my_split.c \
	  src/get_next_line.c

OBJS	= $(SRCS:.c=.o)

NAME	= mysh

HNAME	= -I /usr/include

CFLAGS =  $(HNAME)

LIBNAME	= -L ./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(LIBNAME) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
