#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

size_t ft_strlcat(char *dest, const char *src, size_t size);
int	ft_atoi(const char *str);
void *ft_memset(void *b, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *restrict s1, const void *restrict s2, size_t n);

int main(void)
{
	char str1[15] = "abc";
	char str2[15] = "0123456";
	int a[20];
	int b[20];

	//bzero(a, sizeof(int));
	//ft_bzero(b, sizeof(int));

	printf("memcpy : %s\n", memcpy(str1, str2, 4));
	char str3[15] = "abc";
	char str4[15] = "0123456";
	printf("ft_memcpy : %s\n", ft_memcpy(str3, str4, 4));
	return (0);
}
