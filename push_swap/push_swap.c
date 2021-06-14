/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:27:27 by gjeon             #+#    #+#             */
/*   Updated: 2021/06/10 17:27:29 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_info *info)
{
	int			pivot;
	t_stack_ls	*tmp;
	int			i;

	pivot = info->stack.a->data;
	tmp = info->stack.a->next;
	i = 0;
	while (i < 5)
	{
		if (tmp->data > pivot)
			set_ra_rb(&info->stack.a);
		else
			set_pa_pb(&info->stack.b, &info->stack.a);
		tmp = tmp->next;
	}
}

int		main(int ac, char **av)
{
	int	arr1[5] = {4,2,5,1,3};
	t_info	info;
	int		i;
	t_stack_ls *tmp;

	info.stack.a = 0;
	info.stack.b = 0;
	i = 0;
	while (i < 5)
	{
		set_stack(&info.stack.a, i, arr1[i]);
		i++;
	}
	
	quick_sort(&info);

	while (info.stack.a != 0)
	{
		printf("a=%d\n", info.stack.a->data);
		info.stack.a = info.stack.a->next;
	}
	printf("******\n");
	while (info.stack.b != 0)
	{
		printf("b=%d\n", info.stack.b->data);
		info.stack.b = info.stack.b->next;
	}
	stack_lsclear(&info.stack.a);
	return (0);
}
