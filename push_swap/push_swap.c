#include "push_swap.h"

void swap(char *a, char *b)
{
	char *tmp = a;

	a = b;
	b = tmp;
}

int		main(int ac, char **av)
{
	char arr1[10][10] = {"1","2","3","4","5","6","7","8","9","10"};
	t_info	info;
	int		i;

	for (int k = 0; k < 10; k++)
		swap(arr1[rand() % 10], arr1[rand() % 10]);

	i = 0;
	//set_stack(&info, arr1, 10)
	
	return (0);
}
