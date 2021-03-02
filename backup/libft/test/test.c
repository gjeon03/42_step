#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size);
int	ft_atoi(const char *str);
void *ft_memset(void *b, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *restrict s1, const void *restrict s2, size_t n);
void *ft_memccpy(void *restrict s1, const void *restrict s2, int c, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
char *ft_strnstr(const char *s1, const char *s2, size_t n);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int c);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_putnbr_fd(int n, int fd);

int main(void)
{
	char str1[20] = "abcde";
	char str2[20];
	int a[20];
	int b[20];
	char **arr;
	int	i = -1;
	int j = -1;

	ft_putnbr_fd(-2147483648, 1);
	printf("\n%zu\n", j * (size_t)i);
	ft_putnbr_fd(0, 1);	
	return (0);
}
