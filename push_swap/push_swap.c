#include "push_swap.h"

void swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		main(int ac, char **av)
{
	char	**arr;
	t_info	info;

	arr = malloc(sizeof(char) * 10);
	for (int k = 0; k < 10; k++)
		arr[k] = malloc(sizeof(char) * 10);
	for (int k = 0; k < 10; k++)
		arr[k] = ft_itoa(k + 1);

	for (int k = 0; k < 50; k++)
		swap(&arr[rand() % 9], &arr[rand() % 9]);

	/*
	* arr info
	*/
	printf("-------arr-------\n");
	if (ac == 1)
	{
		for (int k = 0; k < 10; k++)
			printf("%s ", arr[k]);
	}
	else
	{
		for (int k = 1; k < ac; k++)
			printf("%s ", av[k]);
	}
	printf("\n");

	/*
	* set stack
	*/
	if (ac == 1)
		set_stack(&info, arr, 10);
	else
		set_stack(&info, av + 1, ac - 1);

	/*
	* stack a,b info
	*/
	printf("-----a_stack-----\n");
	for (int k = 0; k <= info.stack.a.top; k++)
		printf("%d ", info.stack.a.arr[k]);
	printf("\n-----b_stack-----\n");
	for (int k = 0; k <= info.stack.b.top; k++)
		printf("%d ", info.stack.b.arr[k]);
	printf("\n-----------------\n");

	/*
	* sort test
	*/
	//set_sa_sb(&info.stack.a, 1);
	//set_pa_pb(&info.stack.b, &info.stack.a, 1, &info.sort);
	//set_pa_pb(&info.stack.b, &info.stack.a, 1, &info.sort);
	//set_pa_pb(&info.stack.b, &info.stack.a, 1, &info.sort);
	//set_ra_rb(&info.stack.a, 1, &info.sort);
	//set_rra_rrb(&info.stack.a, 1);
	//set_ss(&info.stack.a, &info.stack.b);
	//set_rr(&info.stack.a, &info.stack.b, &info.sort);
	//set_rrr(&info.stack.a, &info.stack.b);

	if (ac == 1)
		info.count = 10;
	else
		info.count = ac - 1;
	a_to_b(&info, info.count);

	/*
	* stack a,b info
	*/
	printf("-----a_stack-----\n");
	for (int k = 0; k <= info.stack.a.top; k++)
		printf("%d ", info.stack.a.arr[k]);
	printf("\n-----b_stack-----\n");
	for (int k = 0; k <= info.stack.b.top; k++)
		printf("%d ", info.stack.b.arr[k]);
	printf("\n-----------------\n");

	return (0);
}
