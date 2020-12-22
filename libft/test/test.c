#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(const char *str);

int main(void)
{
	char *str1[30];

	printf("strlen : %lu\n", strlen("-2147483648"));
	printf("ft_strlen : %lu\n", ft_strlen("-2147483648"));

	printf("strlen : %lu\n", strlen(""));
	printf("ft_strlen : %lu\n", ft_strlen(""));

	printf("strlen : %lu\n", strlen("jeon\n\t"));
	printf("ft_strlen : %lu\n", ft_strlen("jeon\n\t"));

	return (0);
}
