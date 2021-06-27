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

/*void	b_to_a(t_info *info, int count)
{
	int	i;
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	rrr_count;

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
	//set_info(info, count, 2);
	info->pivot1 = set_first_pivot(info->stack.b, info, count);
	info->pivot2 = set_second_pivot(info->stack.b, info, count);
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
		rrr_count = rb_count;
	else
		rrr_count = ra_count;
	i = rrr_count;
	while (i--)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (rrr_count + i++ < ra_count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (rrr_count + i++ < rb_count)
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
	int rrr_count;

	ra_count = 0;
	rb_count = 0;
	pb_count = 0;
	if (count < 3)
	{
		if (count == 2 && info->stack.a->data > info->stack.a->next->data)
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	//set_info(info, count, 1);
	info->pivot1 = set_first_pivot(info->stack.a, info, count);
	info->pivot2 = set_second_pivot(info->stack.a, info, count);
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
		rrr_count = rb_count;
	else
		rrr_count = ra_count;
	i = rrr_count;
	while (i--)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (rrr_count + i++ < ra_count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (rrr_count + i++ < rb_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, ra_count);
	b_to_a(info, rb_count);
	b_to_a(info, pb_count - rb_count);
}*/

void	b_to_a(t_info *info, int count)
{
	t_sort_info	sort;
	int	i;
	int	rrr;
	int	rra;
	int	rrb;
	
	sort.ra_count = 0;
	sort.rb_count = 0;
	sort.pa_count = 0;
	sort.rr_count = 0;
	if (count < 3)
	{
		if (count == 2 && info->stack.b->data < info->stack.b->next->data)
		{
			set_sa_sb(&info->stack.b, 2);
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		}
		else if (count == 2)
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		if (info->stack.b != 0)
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		return ;
	}
	sort.pivot1 = set_first_pivot(info->stack.b, info, count);
	sort.pivot2 = set_second_pivot(info->stack.b, info, count);
	i = 0;
	while (i < count)
	{
		if (sort.pa_count > 0 && info->stack.a->data >= sort.pivot2
				&& info->stack.b->data < sort.pivot1)
			set_rr(&info->stack.a, &info->stack.b, &sort);
		else if (info->stack.b->data < sort.pivot1)
			set_ra_rb(&info->stack.b, 2, &sort);
		else
		{
			if (sort.pa_count > 0 && info->stack.a->data >= sort.pivot2)
				set_ra_rb(&info->stack.a, 1, &sort);
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
			if (i + 1 == count)
			{
				if (info->stack.a->data >= sort.pivot2)
					set_ra_rb(&info->stack.a, 1, &sort);
			}
		}
		i++;
	}
	printf("^0^\n");
	/*###############################*/
	t_stack_ls *tmp;
	printf("a******\n");
	tmp = info->stack.a;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("b******\n");
	tmp = info->stack.b;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	/*###############################*/

	//a_to_b(info, sort.pa_count - sort.ra_count + sort.rr_count);
	if (sort.ra_count > sort.rb_count)
	{
		rrr = sort.rr_count + sort.rb_count;
		rra = sort.ra_count - sort.rb_count;
		rrb = 0;
	}
	else
	{
		rrr = sort.rr_count + sort.ra_count;
		rrb = sort.rb_count - sort.ra_count;
		rra = 0;
	}
	i = 0;
	while (i++ < rrr && count != info->count)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (i++ < rra && count != info->count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (i++ < rrb && count != info->count)
		set_rra_rrb(&info->stack.b, 2);
	//a_to_b(info, sort.rb_count + sort.rr_count);
	//b_to_a(info, sort.ra_count + sort.rr_count);
}

void	a_to_b(t_info *info, int count)
{
	t_sort_info	sort;
	int	i;
	int	rrr;
	int	rra;
	int	rrb;
	
	sort.ra_count = 0;
	sort.rb_count = 0;
	sort.pb_count = 0;
	sort.rr_count = 0;
	if (count < 3)
	{
		if (count == 2 && info->stack.a->data > info->stack.a->next->data)
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	sort.pivot1 = set_first_pivot(info->stack.a, info, count);
	sort.pivot2 = set_second_pivot(info->stack.a, info, count);
	i = 0;
	while (i < count)
	{
		if (sort.pb_count > 0 && info->stack.a->data >= sort.pivot2
				&& info->stack.b->data >= sort.pivot1)
			set_rr(&info->stack.a, &info->stack.b, &sort);
		else if (info->stack.a->data >= sort.pivot2)
			set_ra_rb(&info->stack.a, 1, &sort);
		else
		{
			if (sort.pb_count > 0 && info->stack.b->data >= sort.pivot1)
				set_ra_rb(&info->stack.b, 2, &sort);
			set_pa_pb(&info->stack.b, &info->stack.a, 1, &sort);
			if (i + 1 == count)
			{
				if (info->stack.b->data >= sort.pivot1)
					set_ra_rb(&info->stack.b, 2, &sort);
			}
		}
		i++;
	}
	if (sort.ra_count > sort.rb_count)
	{
		rrr = sort.rr_count + sort.rb_count;
		rra = sort.ra_count - sort.rb_count;
		rrb = 0;
	}
	else
	{
		rrr = sort.rr_count + sort.ra_count;
		rrb = sort.rb_count - sort.ra_count;
		rra = 0;
	}
	i = 0;
	while (i++ < rrr && count != info->count)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (i++ < rra && count != info->count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (i++ < rrb && count != info->count)
		set_rra_rrb(&info->stack.b, 2);

	/*###############################*/
	t_stack_ls *tmp;
	printf("a******\n");
	tmp = info->stack.a;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("b******\n");
	tmp = info->stack.b;
	while (tmp != 0)
	{
		printf("a=%d\n", tmp->data);
		tmp = tmp->next;
	}
	/*###############################*/

	//a_to_b(info, sort.ra_count + sort.rr_count);
	//b_to_a(info, sort.rb_count + sort.rr_count);
	//b_to_a(info, sort.pb_count - sort.rb_count + sort.rr_count);
	a_to_b(info, sort.ra_count + sort.rr_count);
	//b_to_a(info, sort.pb_count - sort.rb_count + sort.rr_count);
	b_to_a(info, sort.rb_count + sort.rr_count);
}

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

int		main(int ac, char **av)
{
	int	arr1[20] = {20,13,6,12,19,17,4,8,14,9,18,5,11,2,16,7,15,3,10,1};
	//int	arr1[10] = {1,11,3,73,16,98,55,50,6,32};
	//int arr1[100] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	
	t_info	info;
	int		i;
	t_stack_ls *tmp;

	//for (int k = 0; k < 100; k++)
	//	swap(&arr1[rand() % 100], &arr1[rand() % 100]);
	
	info.stack.a = 0;
	info.stack.b = 0;
	info.count = 0;
	i = 0;
	while (i < 20)
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
