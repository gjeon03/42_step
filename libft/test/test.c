#include <stdio.h>
#include <bsd/string.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size);

int main(void)
{
	char str1[30] = "jeon";

	printf("strlcpy : %ld\n", strlcpy(str1, "hello", 0));
	
	char str2[30] = "jeon";

	printf("ft_strlcpy : %ld\n", ft_strlcpy(str2, "hello", 0));
	return (0);
}
