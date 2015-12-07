/*
** my.h for my in /home/boulat_m/rendu/semaine2/Piscine_C_J09
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  9 10:53:19 2014 Mickael BOULAT
** Last update Thu Nov 13 10:09:20 2014 Mickael BOULAT
*/

#ifndef MY_H_
# define MY_H_

#   define BUFFER_SIZE 200000
#   define BLACK "\033[30m"
#   define RED "\033[31m"
#   define GREEN "\033[32m"
#   define YELLOW "\033[33m"
#   define BLUE "\033[34m"
#   define MAGENTA "\033[35m"
#   define CYAN "\033[36m"
#   define WHITE "\033[37m"
#   define INIT "\033[0m"
#   define BOLD "\033[1m"
#   define BLINK "\033[5m"
#   define AUTO "\033[7m"

int	my_putstrn(char* str);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
void	my_putstrc(char *str, char *color, char bold);
void	my_putstrcn(char *str, char *color, char bold);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strtolowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isalphanum(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
int	my_power_it(int nb);
int	my_putnbrbase(int nbr, char *str);
int	my_str_isalphanum(char *str);
char	*my_strdup(char *str);

#endif
