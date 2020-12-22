#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str1[30];

<<<<<<< HEAD
	printf("strlcpy : %ld\n", strlcpy(str1, "hello", 0));
=======
	printf("strlcpy : %lu\n", atoi());
	printf("strlcpy : %s\n", str1);
>>>>>>> adfc9ac878784a9c610d0a080af8209272a6a3fa
	
	char *str2[30];

	printf("ft_strlcpy : %ld\n", ft_strlcpy(str2, "jeon gyeong yeon", 10));
	printf("ft_strlcpy : %s\n", str2);
	return (0);
}
