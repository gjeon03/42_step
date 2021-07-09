#include "push_swap.h"

int		ft_strchar_count(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = malloc(sizeof(char) * (n + 1))))
		return (0);
	while (str[i] && i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	blank_handling(t_info *info, char *str, int count)
{
	char	**tmp;
	int		i;
	int		j;
	int		start;

	if (!(tmp = malloc(sizeof(char*) * count)))
		error_msg("Error\n");
	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			tmp[j++] = ft_strndup(str + start, i - start);
			start = i + 1;
		}
		i++;
	}
	tmp[j] = ft_strndup(str + start, i - start);
	set_stack(info, tmp, count);
	i = 0;
	while (i < count)
		free(tmp[i++]);
	free(tmp);
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

int		main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		return (0);
	else if (ac == 2 && (info.count = (ft_strchar_count(av[1]) + 1)) > 1)
		blank_handling(&info, av[1], info.count);
	else
	{
		info.count = ac - 1;
		set_stack(&info, av + 1, ac - 1);
	}
	if (!(sort_check(&info)))
		return (0);
	if (info.stack.a.top != 2)
	{
		a_to_b(&info, info.count);
		if (info.stack.b.top != -1)
			set_pa_pb(&info.stack.a, &info.stack.b, 2, &info.sort);
	}
	else
		arr3_sort(&info);
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
