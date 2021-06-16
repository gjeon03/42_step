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

void	b_to_a(t_info *info, int count)
{
	static int	pivot;

	set_pa_pb(&info->stack.a, &info->stack.b);
	if (count == 1)
		return ;
	if (info->stack.a->data > info->stack.a->next->data)
		set_sa_sb(&info->stack.a);
	//a_to_b(info, rb_count);
	b_to_a(info, count - 1);
}

void	a_to_b(t_info *info, int count)
{
	int	pivot;
	int	i;
	int	ra_count;
	int	pb_count;

	if (count == 2)
	{
		if (info->stack.a->data > info->stack.a->next->data)
			set_ra_rb(&info->stack.a);
		return ;
	}
	pivot = set_pivot(info->stack.a, info, count);
	i = 0;
	ra_count = 0;
	pb_count = 0;
	while (i < count)
	{
		if (info->stack.a->data > pivot)
		{
			set_ra_rb(&info->stack.a);
			ra_count++;
		}
		else
		{
			set_pa_pb(&info->stack.b, &info->stack.a);
			pb_count++;
		}
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		set_rra_rrb(&info->stack.a);
		i++;
	}
	a_to_b(info, ra_count);
	//b_to_a(info, pb_count);
}

int		main(int ac, char **av)
{
	int	arr1[10] = {2,4,5,1,7,9,3,8,6,10};
	t_info	info;
	int		i;
	t_stack_ls *tmp;

	info.stack.a = 0;
	info.stack.b = 0;
	info.count = 0;
	i = 0;
	while (i < 10)
	{
		set_stack(&info.stack.a, i, arr1[i]);
		info.count++;
		i++;
	}
	printf("count=%d\n", info.count);
	tmp = info.stack.a;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("******\n");
	//set_pivot(info.stack.a, &info);
	//printf("pivot = %d\n", info.pivot);
	a_to_b(&info, info.count);
	b_to_a(&info, info.count - 2);
	/*###############################*/
	printf("a******\n");
	tmp = info.stack.a;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("b******\n");
	tmp = info.stack.b;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	/*###############################*/
	stack_lsclear(&info.stack.a);
	return (0);
}
