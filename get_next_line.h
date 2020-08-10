/*
** EPITECH PROJECT, 2020
** get_next_line.h
** File description:
** 
*/

#ifndef READ_SIZE
#define READ_SIZE (16)
#endif /* !READ_SIZE */

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <stdlib.h>
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
char *get_next_line(int fd);
char *my_realloc(char * ptr, int size);
void mymmcpy(char *dest, char *src, int size);    
char *my_strcat(char *res, char *buffer, int size);
char *rest_of_file(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
int count_char(char *str);
int countlinechar(char *str);
int line_length(char *str);
int nb_char_read(char *str);
int nb_char_line(char *str);

#endif /* !MY_H_ */
