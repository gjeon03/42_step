#include <stdio.h>
#include <unistd.h>

void	hoyeon(char *st)
{
	for(int i = 0; i < 8; i++)
	{
		write(1, &st[i], 1);
	}
}

int	main(void)
{
	printf("hello!\n");
	hoyeon("hoyeon!\n");
	return (0);
}
