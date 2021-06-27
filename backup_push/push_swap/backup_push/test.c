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

void	set_sort_info(t_info *info, int count, int flag, t_sort_info *sort)
{
	if (flag == 1)
		info->pivot = set_pivot(info->stack.a, info, count);
	else
		info->pivot = set_pivot(info->stack.b, info, count);
	sort->ra_count = 0;
	sort->rb_count = 0;
	sort->pa_count = 0;
	sort->pb_count = 0;
}

void	b_to_a(t_info *info, int count)
{
	int	i;
	t_sort_info	sort;

	if (count < 3)
	{
		if (count == 2 && info->stack.b->data < info->stack.b->next->data)
			set_sa_sb(&info->stack.b, 2);
		return ;
	}
	set_sort_info(info, count, 2, &sort);
	while (count--)
	{
		if (info->stack.b->data <= info->pivot)
		{
			if (count > 0)
				set_ra_rb(&info->stack.b, 2, &sort);
		}
		else
			set_pa_pb(&info->stack.a, &info->stack.b, 1, &sort);
	}
	i = 1;
	while (i < sort.rb_count && sort.rb_count > 2)
	{
		set_rra_rrb(&info->stack.b, 1);
		i++;
	}
	b_to_a(info, sort.rb_count);
}

void	a_to_b(t_info *info, int count)
{
	int	i;
	t_sort_info	sort;
	int	c;

	c = count;
	if (count < 3)
	{
		if (count == 2 && info->stack.a->data > info->stack.a->next->data)
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	set_sort_info(info, count, 1, &sort);
	while (count--)
	{
		if (info->stack.a->data >= info->pivot)
		{
			if (count > 0)
				set_ra_rb(&info->stack.a, 1, &sort);
		}
		else
			set_pa_pb(&info->stack.b, &info->stack.a, 2, &sort);
	}
	i = 1;
	while (i < sort.ra_count && sort.ra_count > 2 && info->count != c)
	{
		set_rra_rrb(&info->stack.a, 1);
		i++;
	}
	a_to_b(info, sort.ra_count);
}

void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

int		main(int ac, char **av)
{
	int	arr1[10] = {8,6,2,10,4,5,9,7,3,1};
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
	while (i < 10)
	{
		set_stack(&info.stack.a, arr1[i]);
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
	i = 0;
	a_to_b(&info, info.count);
	b_to_a(&info, info.count - 2);
	a_to_b(&info, info.count - 4);
	b_to_a(&info, info.count - 6);
	a_to_b(&info, info.count - 8);
	//b_to_a(&info, info.count - 10);
	/*while (i < info.count / 2)
	{
		a_to_b(&info, info.count - i++ * 2);
		if (i < info.count / 2)
			b_to_a(&info, info.count - i++ * 2);
	}*/

	/*printf("@@@@@pivot=%d\n", set_pivot(info.stack.a, &info, 9));
	a_to_b(&info, info.count);

	printf("@@@@@pivot=%d\n", set_pivot(info.stack.b, &info, 7));
	b_to_a(&info, info.count - 2);

	printf("@@@@@pivot=%d\n", set_pivot(info.stack.a, &info, 5));
	a_to_b(&info, info.count - 4);
	b_to_a(&info, info.count - 6);
	a_to_b(&info, info.count - 8);
*/
	//while (info.stack.b != 0)
	//	set_pa_pb(&info.stack.a, &info.stack.b, 2, &info.sort);
	
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
