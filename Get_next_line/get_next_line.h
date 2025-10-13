#ifndef GET_NEXT_LINE
#define  GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#include<stdio.h> 
#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h> 

size_t  ft_strlen(const char *s);
void    *ft_calloc(size_t count, size_t size);
void *ft_memcpy(void *dst, const void *src, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
char *get_next_line(int fd);

#endif