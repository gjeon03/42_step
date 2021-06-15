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
	int	pivot;
	int	i;
	int	rb_count;
	int	pa_count;

	if (count == 1)
	{
		set_pa_pb(&info->stack.a, &info->stack.b);
		return ;
	}
	pivot = set_pivot(info->stack.b, info);
	i = 0;
	rb_count = 0;
	pa_count = 0;
	while (i < count)
	{
		if (info->stack.b->data > pivot)
		{
			set_ra_rb(&info->stack.b);
			rb_count++;
		}
		else
		{
			set_pa_pb(&info->stack.a, &info->stack.b);
			pa_count++;
		}
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		set_rra_rrb(&info->stack.b);
		i++;
	}
	a_to_b(info, rb_count);
	b_to_a(info, pa_count);
}

void	a_to_b(t_info *info, int count)
{
	int	pivot;
	int	i;
	int	ra_count;
	int	pb_count;

	printf("#####\n");
	if (count == 1)
		return ;
	pivot = set_pivot(info->stack.a, info);
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
	b_to_a(info, pb_count);
}

int		main(int ac, char **av)
{
	int	arr1[5] = {10,7,9,3,2};
	t_info	info;
	int		i;
	t_stack_ls *tmp;

	info.stack.a = 0;
	info.stack.b = 0;
	info.count = 0;
	i = 0;
	while (i < 5)
	{
		set_stack(&info.stack.a, i, arr1[i]);
		info.count++;
		i++;
	}
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

	printf("******\n");
	tmp = info.stack.a;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("******\n");
	tmp = info.stack.b;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	stack_lsclear(&info.stack.a);
	return (0);
}
