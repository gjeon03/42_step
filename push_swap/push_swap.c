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

	if (count == 0)
		return ;
	if (count == 1)
	{
		//if (count == 2 && info->stack.b->data < info->stack.b->next->data)
		//	set_sa_sb(&info->stack.b);
		set_pa_pb(&info->stack.a, &info->stack.b);
		return ;
	}
	if (count == 2 && info->stack.b->data < info->stack.b->next->data)
		set_sa_sb(&info->stack.b);
	/*if (count == 1)
	{
		set_pa_pb(&info->stack.a, &info->stack.b);
		return ;
	}*/
	pivot = set_pivot(info->stack.b, info, count);
	i = 0;
	rb_count = 0;
	pa_count = 0;
	while (i < count)
	{
		if (info->stack.b->data < pivot)
		{
			printf("rb\n");
			set_ra_rb(&info->stack.b);
			rb_count++;
		}
		else
		{
			printf("pb\n");
			set_pa_pb(&info->stack.a, &info->stack.b);
			pa_count++;
		}
		i++;
	}
	i = 0;
	while (i < rb_count)
	{
		printf("rrb\n");
		set_rra_rrb(&info->stack.b);
		i++;
	}
	//a_to_b(info, pa_count);
	b_to_a(info, rb_count);
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
		{
			set_sa_sb(&info->stack.a);
			printf("sa\n");
		}
		return ;
	}
	if (count == 1)
		return ;
	pivot = set_pivot(info->stack.a, info, count);
	i = 0;
	ra_count = 0;
	pb_count = 0;
	while (i < count)
	{
		if (info->stack.a->data > pivot)
		{
			printf("ra\n");
			set_ra_rb(&info->stack.a);
			ra_count++;
		}
		else
		{
			printf("pa\n");
			set_pa_pb(&info->stack.b, &info->stack.a);
			pb_count++;
		}
		i++;
	}
	i = 0;
	while (i < ra_count)
	{
		printf("rra\n");
		set_rra_rrb(&info->stack.a);
		i++;
	}
	a_to_b(info, ra_count);
	//b_to_a(info, pb_count);
}

int		main(int ac, char **av)
{
	int	arr1[10] = {4,2,10,7,5,3,8,1,6,9};
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
	a_to_b(&info, info.count);
	i = 1;
	while (info.stack.b != 0)
	{
		b_to_a(&info, info.count - 2 * i);
		if (info.stack.b != 0)
			a_to_b(&info, info.count - 2 * i);
		i++;
	}
	/*tmp = info.stack.b;
	while (tmp != 0)
	{
		set_pa_pb(&info.stack.a, &info.stack.b);
		tmp = tmp->next;
	}*/

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
