#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int ft_isascii(int c);

int main(void)
{
	char str1[30] = "abcdefg";
	char str2[30] = "abc0123456";

	printf("isalnum : %d\n", isascii('A'));
	printf("ft_isalnum : %d\n", ft_isascii('A'));

	printf("isalnum : %d\n", isascii('g'));
	printf("ft_isalnum : %d\n", ft_isascii('g'));

	printf("isalnum : %d\n", isascii('2'));
	printf("ft_isalnum : %d\n", ft_isascii('2'));

	printf("isalnum : %d\n", isascii('\n'));
	printf("ft_isalnum : %d\n", ft_isascii('\n'));

	printf("isalnum : %d\n", isascii(230));
	printf("ft_isalnum : %d\n", ft_isascii(230));

	printf("isalnum : %d\n", isascii(-1));
	printf("ft_isalnum : %d\n", ft_isascii(-1));

	return (0);
}
