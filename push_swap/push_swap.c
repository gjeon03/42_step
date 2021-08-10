/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:18:59 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 04:20:39 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_info *info)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (i < info->stack.a.top)
	{
		j = i + 1;
		while (j <= info->stack.a.top)
		{
			if (info->stack.a.arr[i] == info->stack.a.arr[j])
				return (2);
			if (info->stack.a.arr[i] > info->stack.a.arr[j])
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 1)
		return (1);
	return (0);
}

void	info_init(t_info *info)
{
	info->stack.a.arr = 0;
	info->stack.b.arr = 0;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		return (0);
	info_init(&info);
	info.count = (ft_strchar_count(av[1]) + 1);
	if (ac == 2 && info.count > 1)
		blank_handling(&info, av[1], info.count);
	else
	{
		info.count = ac - 1;
		set_stack(&info, av + 1, ac - 1);
	}
	info.check = sort_check(&info);
	if (!(info.check))
		return (0);
	else if (info.check == 2)
		error_msg("Error\n", &info);
	if (info.stack.a.top != 2)
		a_to_b(&info, info.count);
	else
		arr3_sort(&info);
	if (info.stack.b.top != -1)
		set_pa_pb(&info.stack.a, &info.stack.b, 2, &info.sort);
	return (stack_free(&info));
}
