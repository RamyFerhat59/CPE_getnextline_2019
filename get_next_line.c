/*
** EPITECH PROJECT, 2020
** get_next_line.c
** File description:
** get_next_line.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE];
    int ch = 0;
    char *line = "\0";
    static char *rest_of_line = "\0";

    if (fd == -1 || buffer == NULL || READ_SIZE <= 0)
        return (NULL);
    line = rest_of_line;
    if (line == NULL) {
        return NULL;
    }
    while ((ch = read(fd, buffer, READ_SIZE)) > 0 && buffer[ch] != '\n') {
        line = my_strcat(line, buffer, ch);
        if (line == NULL) {
            return NULL;
        }
    }
    if (line == NULL) {
        return (NULL);
    }
    rest_of_line = rest_of_file(line);
    if (rest_of_line == NULL)
        return (NULL);
    if (my_strlen(line) == 0)
          return (NULL);
    for (int j = 0; line[j] != '\0'; j++) {
        if (line[j] == '\n')
            line[j] = '\0';
    }
    return (line);
}

int my_strlen(char const *str)
{
    int i = 0;
    
    while (str[i])
        i++;
    return (i);
}

char *my_strcat(char *line, char *buffer, int size)
{
    char *line_copy;
    int nbread = 0;
    int j = 0;

    nbread = nb_char_read(line);
    line_copy = malloc(sizeof(char) * ((nbread + size) + 1));
    if (line_copy == NULL)
        return (NULL);
    line_copy = my_strcpy(line_copy, line);
    if (line_copy == NULL)
        return (NULL);
    for (; j < size; j++) {
        line_copy[nbread + j] = buffer[j];
    }
    line_copy[nbread + j + 1] = '\0';
    return (line_copy);
}

int nb_char_read(char *str)
{
    int i = 0;
    
    while(str[i] != '\0') {
        i++;
    }
    return (i);  
}

int nb_char_line(char *str)
{
    int i = 0;
    
    while(str[i] != '\n' && str[i] != '\0') {
        i++;
    }
    return (i);  
}

char *rest_of_file(char *str)
{
    char *res = NULL;
    int nb_read = 0;
    int charline = 0;
    int j = 0;

    charline = nb_char_line(str);
    if(str[charline] == '\n')
        charline++;
    nb_read = nb_char_read(str);
    res = malloc(sizeof(char) * ((nb_read - charline) + 1));
    if (res == NULL)
        return (NULL);
    for (; str[charline]; j++) {
        res[j] = str[charline];
        charline++;
    }
    res[j] = '\0';
    return (res);
}

char *my_strcpy(char *dest, char *src)
{
    int i;
    i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (dest);
}
