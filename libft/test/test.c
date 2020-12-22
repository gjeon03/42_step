#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_strncmp(const char *s1, const char *s2, size_t n);

int main(void)
{
	char str1[30] = "abcdefg";
	char str2[30] = "abc0123456";

	printf("strncmp : %d\n", strncmp(str1, str2, -1));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, -1));

	printf("strncmp : %d\n", strncmp(str1, str2, 0));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, 0));
	
	printf("strncmp : %d\n", strncmp(str1, str2, 4));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, 4));

	printf("strncmp : %d\n", strncmp(str1, str2, 6));
	printf("ft_strncmp : %d\n", ft_strncmp(str1, str2, 6));

	return (0);
}
