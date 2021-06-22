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

void	set_info(t_info *info, int count, int flag)
{
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	pb_count;

	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	pb_count = 0;
	if (flag == 1)
	{
		info->pivot1 = set_first_pivot(info->stack.a, info, count);
		info->pivot2 = set_second_pivot(info->stack.a, info, count);
	}
	else
	{
		info->pivot1 = set_first_pivot(info->stack.b, info, count);
		info->pivot2 = set_second_pivot(info->stack.b, info, count);
	}
	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	pb_count = 0;
}

void	b_to_a(t_info *info, int count)
{
	int	i;
	int	ra_count;
	int	rb_count;
	int	pa_count;

	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	if (count < 3)
	{
		if (count == 2 && info->stack.b->data < info->stack.b->next->data)
			set_sa_sb(&info->stack.b, 2);
		if (count != 0)
			set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
		return ;
	}
	set_info(info, count, 2);
	while (count--)
	{
		if (info->stack.b->data < info->pivot1)
		{
			set_ra_rb(&info->stack.b, 2, info);
			rb_count++;
		}
		else
		{
			set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
			pa_count++;
			if (info->stack.b->data >= info->pivot2)
			{
				set_ra_rb(&info->stack.a, 1, info);
				ra_count++;
			}
		}
	}
	a_to_b(info, pa_count - ra_count);
	if (ra_count > rb_count)
		i = rb_count;
	else
		i = ra_count;
	while (i--)
		set_rrr(&info->stack.a, &info->stack.b);
	if (ra_count > rb_count)
		i = rb_count;
	else
		i = ra_count;
	while (i < ra_count)
	{
		set_rra_rrb(&info->stack.a, 1);
		i++;
	}
	while (i++ < rb_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, rb_count);
	b_to_a(info, ra_count);
}

void	a_to_b(t_info *info, int count)
{
	int	i;
	int	ra_count;
	int	rb_count;
	int	pb_count;

	ra_count = 0;
	rb_count = 0;
	pb_count = 0;
	if (count < 3)
	{
		if (count == 2 && info->stack.a->data > info->stack.a->next->data)
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	set_info(info, count, 1);
	while (count--)
	{
		if (info->stack.a->data >= info->pivot2)
		{
			set_ra_rb(&info->stack.a, 1, info);
			ra_count++;
		}
		else
		{
			set_pa_pb(&info->stack.b, &info->stack.a, 2, info);
			pb_count++;
			if (info->stack.b->data >= info->pivot1)
			{
				set_ra_rb(&info->stack.b, 2, info);
				rb_count++;
			}
		}
	}
	if (ra_count > rb_count)
		i = rb_count;
	else
		i = ra_count;
	while (i--)
	{
		set_rrr(&info->stack.a, &info->stack.b);
	}
	if (ra_count > rb_count)
		i = rb_count;
	else
		i = ra_count;
	while (i < ra_count)
	{
		set_rra_rrb(&info->stack.a, 1);
		i++;
	}
	while (i++ < rb_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, ra_count);
	b_to_a(info, rb_count);
	b_to_a(info, pb_count - rb_count);
}

void	arr5_sort(t_info *info, int count)
{
	info->pivot1 = set_pivot(info->stack.a, info, count);
	while (info->stack.a->next != 0 && info->stack.a->next->next != 0)
	{
		if (info->stack.a->data > info->pivot1)
			set_ra_rb(&info->stack.a, 1, info);
		else
			set_pa_pb(&info->stack.b, &info->stack.a, 2, info);
	}
	if (info->stack.a->data > info->stack.a->next->data)
		set_sa_sb(&info->stack.a, 1);
	info->pivot1 = set_pivot(info->stack.b, info, count - 2);
	while (info->stack.b->next != 0 && info->stack.b->next->next != 0)
	{
		if (info->stack.b->data <= info->pivot1)
			set_ra_rb(&info->stack.b, 2, info);
		else
			set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
	}
	if (info->stack.b->data < info->stack.b->next->data)
		set_sa_sb(&info->stack.b, 2);
	set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
	set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
}

void	arr3_sort(t_info *info, int count)
{
	set_pa_pb(&info->stack.b, &info->stack.a, 2, info);
	if (info->stack.a->data > info->stack.a->next->data)
		set_sa_sb(&info->stack.a, 1);
	if (info->stack.a->next->data < info->stack.b->data)
	{
		set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
		set_ra_rb(&info->stack.a, 1, info);
	}
	else if (info->stack.a->data < info->stack.b->data)
	{
		set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
		set_sa_sb(&info->stack.a, 1);
	}
	else
		set_pa_pb(&info->stack.a, &info->stack.b, 1, info);
}

int		main(int ac, char **av)
{
	int	arr1[10] = {6,4,8,9,5,2,7,3,10,1};
	t_info	info;
	int		i;
	t_stack_ls *tmp;

	info.stack.a = 0;
	info.stack.b = 0;
	info.count = 0;
	i = 0;
	while (i < 10)
	{
		set_stack(&info.stack.a, arr1[i]);
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
	//arr5_sort(&info, 5);
	a_to_b(&info, info.count);
	//b_to_a(&info, info.count);

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
