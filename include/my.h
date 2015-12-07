/*
** my.h for my in /home/boulat_m/rendu/semaine2/Piscine_C_J09
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  9 10:53:19 2014 Mickael BOULAT
** Last update Sat Nov 29 17:05:26 2014 Mickael BOULAT
*/

#ifndef MY_H_
# define MY_H_
# define BUFF_SIZE 512

int my_putstrn(char* str);
char *my_strdup(char *str);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr(char *str);
void my_sort_int_tab(int *tab, int size);
int my_power_rec(int nb, int power);
int my_square_root(int nb);
int my_is_prime(int nombre);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int nb);
char *my_strupcase(char *str);
char *my_strtolowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char *str);
int my_str_isnum(char *str);
int my_str_islower(char *str);
int my_str_isupper(char *str);
int my_str_isprintable(char *str);
int my_showstr(char *str);
int my_showmem(char *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int my_strlcat(char *dest, char *src, int size);
int my_power_it(int nb);
int my_putnbrbase(int nbr, char *str);
int my_str_isalphanum(char *str);

#endif
