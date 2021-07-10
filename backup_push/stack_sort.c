/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:19:34 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:45:55 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_info_init(t_sort_info *sort, t_array_stack *stack, int range)
{
	sort->ra_count = 0;
	sort->rb_count = 0;
	sort->pa_count = 0;
	sort->pb_count = 0;
	sort->rr_count = 0;
	sort->rrr_count = 0;
	sort->pivot = set_pivot(stack, range);
}

void	sort_three(t_info *info, t_array_stack *stack, int flag)
{
	if (stack->arr[0] < stack->arr[1])
	{
		set_ra_rb(stack, flag, &info->sort);
		if (stack->arr[0] > stack->arr[1])
			set_sa_sb(stack, flag);
		set_rra_rrb(stack, flag);
		if (stack->arr[0] > stack->arr[1])
			set_sa_sb(stack, flag);
	}
	else
	{
		set_sa_sb(stack, flag);
		set_ra_rb(stack, flag, &info->sort);
		if (stack->arr[0] > stack->arr[1])
			set_sa_sb(stack, flag);
		set_rra_rrb(stack, flag);
		if (stack->arr[0] > stack->arr[1])
			set_sa_sb(stack, flag);
	}
}

void	sort_two(t_info *info, int count)
{
	if (count == 2 && info->stack.b.arr[0] < info->stack.b.arr[1])
	{
		set_sa_sb(&info->stack.b, 2);
		set_pa_pb(&info->stack.a, &info->stack.b, 2, &info->sort);
	}
	else if (count == 2)
		set_pa_pb(&info->stack.a, &info->stack.b, 2, &info->sort);
}

void	b_to_a(t_info *info, int count)
{
	int			i;
	t_sort_info	sort;

	if (count < 3)
	{
		sort_two(info, count);
		if (count != 0)
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		return ;
	}
	sort_info_init(&sort, &info->stack.b, count);
	i = count;
	while (i--)
	{
		if (info->stack.b.arr[0] < sort.pivot)
			set_ra_rb(&info->stack.b, 2, &sort);
		else
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
	}
	while (i++ < sort.rb_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, sort.pa_count);
	b_to_a(info, sort.rb_count);
}

void	a_to_b(t_info *info, int count)
{
	int			i;
	t_sort_info	sort;

	if (count < 4)
	{
		if (count == 3)
			sort_three(info, &info->stack.a, 1);
		if (count == 2 && info->stack.a.arr[0] > info->stack.a.arr[1])
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	sort_info_init(&sort, &info->stack.a, count);
	i = count;
	while (i--)
	{
		if (info->stack.a.arr[0] > sort.pivot)
			set_ra_rb(&info->stack.a, 1, &sort);
		else
			set_pa_pb(&info->stack.b, &info->stack.a, 1, &sort);
	}
	while (i++ < sort.ra_count && count != info->count)
		set_rra_rrb(&info->stack.a, 1);
	a_to_b(info, sort.ra_count);
	b_to_a(info, sort.pb_count);
}
