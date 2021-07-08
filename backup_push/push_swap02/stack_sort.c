#include "push_swap.h"

void	sort_info_init(t_sort_info *sort, t_array_stack *stack, int range, int flag)
{
	sort->ra_count = 0;
	sort->rb_count = 0;
	sort->pa_count = 0;
	sort->pb_count = 0;
	sort->rr_count = 0;
	sort->rrr_count = 0;
	if (flag == 1)
	{
		sort->pivot1 = set_pivot1(stack, range);
		sort->pivot2 = set_pivot2(stack, range);
	}
	else
		sort->pivot = set_pivot(stack, range);
}

void	rrr_count_init(t_sort_info *sort)
{
	if (sort->ra_count > sort->rb_count)
		sort->rrr_count = sort->rb_count;
	else
		sort->rrr_count = sort->ra_count;
}

void	b_to_a(t_info *info, int count)
{
	int	i;
	t_sort_info	sort;

	if (count < 3)
	{
		if (count == 2 && info->stack.b.arr[0] < info->stack.b.arr[1])
		{
			set_sa_sb(&info->stack.b, 2);
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		}
		else if (count == 2)
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		if (count != 0)
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
		return ;
	}
	sort_info_init(&sort, &info->stack.b, count, 1);
	i = 0;
	while (i < count)
	{
		if (info->stack.b.arr[0] < sort.pivot2)
			set_ra_rb(&info->stack.b, 2, &sort);
		else
		{
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &sort);
			if (info->stack.a.arr[0] < sort.pivot1)
				set_ra_rb(&info->stack.a, 1, &sort);
		}
		i++;
	}
	a_to_b(info, sort.pa_count - sort.ra_count);
	i = 0;
	rrr_count_init(&sort);
	i = 0;
	while (i++ < sort.rrr_count)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (i++ < sort.ra_count - sort.rrr_count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (i++ < sort.rb_count - sort.rrr_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, sort.ra_count);
	b_to_a(info, sort.rb_count);
}

void	a_to_b(t_info *info, int count)
{
	int	i;
	t_sort_info	sort;

	if (count < 3)
	{
		if (count == 2 && info->stack.a.arr[0] > info->stack.a.arr[1])
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	sort_info_init(&sort, &info->stack.a, count, 1);
	i = 0;
	while (i < count)
	{
		if (info->stack.a.arr[0] >= sort.pivot1)
			set_ra_rb(&info->stack.a, 1, &sort);
		else
		{
			set_pa_pb(&info->stack.b, &info->stack.a, 1, &sort);
			if (info->stack.b.arr[0] >= sort.pivot2)
				set_ra_rb(&info->stack.b, 2, &sort);
		}
		i++;
	}
	if (count != info->count)
		rrr_count_init(&sort);
	i = 0;
	while (i++ < sort.rrr_count)
		set_rrr(&info->stack.a, &info->stack.b);
	i = 0;
	while (i++ < sort.ra_count - sort.rrr_count && count != info->count)
		set_rra_rrb(&info->stack.a, 1);
	i = 0;
	while (i++ < sort.rb_count - sort.rrr_count)
		set_rra_rrb(&info->stack.b, 2);
	a_to_b(info, sort.ra_count);
	b_to_a(info, sort.rb_count);
	b_to_a(info, sort.pb_count - sort.rb_count);
}

/*void	a_to_b(t_info *info, int count)
{
	t_sort_info	sort;
	int			i;

	if (count < 3)
	{
		if (count == 2 && info->stack.a.arr[0] > info->stack.a.arr[1])
			set_sa_sb(&info->stack.a, 1);
		return ;
	}
	sort_info_init(sort, &info->stack.a);
	i = 0;
	while (i < count)
	{
		if ()
	}
}*/
