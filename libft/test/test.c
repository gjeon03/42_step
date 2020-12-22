#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_atoi(const char *str);

int main(void)
{
	char *str1[30];

	printf("atoi : %d\n", atoi("-2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));

	printf("atoi : %d\n", atoi("0"));
	printf("ft_atoi : %d\n", ft_atoi("0"));

	printf("atoi : %d\n", atoi("1"));
	printf("ft_atoi : %d\n", ft_atoi("1"));

	printf("atoi : %d\n", atoi("\n\t 212a3"));
	printf("ft_atoi : %d\n", ft_atoi("\n\t 212a3"));

	printf("atoi : %d\n", atoi("2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("2147483648"));

	return (0);
}
