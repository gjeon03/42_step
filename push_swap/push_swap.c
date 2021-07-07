#include "push_swap.h"

int		get_next_line(char **line)
{
	static char	*back;
	char		*buf;
	ssize_t		read_size;
	char		*tmp;
	char		*back_tmp;

	if (line == 0)
		return (-1);
	if (back == 0)
	{
		if (!(buf = malloc(sizeof(char) * 100001)))
			return (-1);
		back = ft_strndup("", 0);
		while ((read_size = read(0, buf, 100000)) > 0)
		{
			buf[read_size] = 0;
			tmp = ft_strjoin(back, buf);
			free(back);
			back = tmp;
		}
		free(buf);
	}
	back_tmp = ft_strchr(back, '\n');
	if (back_tmp)
	{
		*line = ft_strndup(back, back_tmp - back);
		back += back_tmp - back + 1;
		return (1);
	}
	else
	{
		*line = ft_strndup(back, ft_strchr(back, '\0') - back);
		back = 0;
		return (0);
	}
}


char	**blank_handling(char *str)
{
	char	**tmp;
	int		i;
	int		j;
	int		len;
	int		start;

	len = ft_strlen(str);
	i = 0;
	start = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == ' ')
		{
			
		}
		i++;
		*str + i;
	}
	return ();
}

int		sort_check(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->stack.a.top)
	{
		j = i + 1;
		while (j <= info->stack.a.top)
		{
			if (info->stack.a.arr[i] == info->stack.a.arr[j])
				return (0);
			if (info->stack.a.arr[i] > info->stack.a.arr[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

void	swap(char **a, char **b)
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

	arr = malloc(sizeof(char) * 500);
	for (int k = 0; k < 500; k++)
		arr[k] = malloc(sizeof(char) * 10);
	for (int k = 0; k < 500; k++)
		arr[k] = ft_itoa(k + 1);

	for (int k = 0; k < 500; k++)
		swap(&arr[rand() % 499], &arr[rand() % 499]);

	/*
	* arr info
	*/
/*	printf("-------arr-------\n");
	if (ac == 1)
	{
		for (int k = 0; k < 100; k++)
			printf("%s ", arr[k]);
	}
	else
	{
		for (int k = 1; k < ac; k++)
			printf("%s ", av[k]);
	}
	printf("\n");
*/
	/*
	* set stack
	*/
	if (ac == 1)
		info.count = 500;
	else
		info.count = ac - 1;
	if (ac == 1)
		set_stack(&info, arr, 500);
	else
		set_stack(&info, av + 1, ac - 1);

	if (!(sort_check(&info)))
		error_msg("end\n");
	/*
	* stack a,b info
	*/
/*	printf("-----a_stack-----\n");
	for (int k = 0; k <= info.stack.a.top; k++)
		printf("%d ", info.stack.a.arr[k]);
	printf("\n-----b_stack-----\n");
	for (int k = 0; k <= info.stack.b.top; k++)
		printf("%d ", info.stack.b.arr[k]);
	printf("\n-----------------\n");
*/
	/*
	* sort test
	*/
	//set_sa_sb(&info.stack.a, 1);
	//set_pa_pb(&info.stack.b, &info.stack.a, 1, &info.sort);
	//set_ra_rb(&info.stack.a, 1, &info.sort);
	//set_rra_rrb(&info.stack.a, 1);
	//set_ss(&info.stack.a, &info.stack.b);
	//set_rr(&info.stack.a, &info.stack.b, &info.sort);
	//set_rrr(&info.stack.a, &info.stack.b);

	a_to_b(&info, info.count);

	/*
	* stack a,b info
	*/
/*	printf("-----a_stack-----\n");
	for (int k = 0; k <= info.stack.a.top; k++)
		printf("%d ", info.stack.a.arr[k]);
	printf("\n-----b_stack-----\n");
	for (int k = 0; k <= info.stack.b.top; k++)
		printf("%d ", info.stack.b.arr[k]);
	printf("\n-----------------\n");
*/
	return (0);
}
