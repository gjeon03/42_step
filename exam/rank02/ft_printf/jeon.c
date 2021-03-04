#include <stdio.h>

int	ft_printf(char *str, ...);

int	main(void)
{
	int	len;
	char	str[20] = "jeon";
	int	i = -2147483648;

	len = ft_printf("test:-%d:\n", i);
	//len = ft_printf("test:-%s:\n", "toto");
	//len = ft_printf("test:-%s:\n", "wiurwuyrhwrywuier");
	//len = ft_printf("test:-%s:\n", NULL);
	len = ft_printf("test:%x:\n", 77);
	//len = ft_printf("test:%d:\n", -54321);
	printf("%d\n", len);
	return (0);
}
