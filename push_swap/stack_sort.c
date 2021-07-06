#include "push_swap.h"

void	sort_info_init(t_sort_info *sort, t_array_stack *stack)
{
	sort->ra_count = 0;
	sort->rb_count = 0;
	sort->pa_count = 0;
	sort->pb_count = 0;
	sort->rr_count = 0;
	//sort->pivot1 = set_pivot1(stack);
	//sort->pivot2 = set_pivot2(stack);
	sort->pivot1 = set_pivot(stack);
}

void	b_to_a(t_info *info, int count)
{
	int	i;
	t_sort_info	sort;

	if (count < 3)
	{
		if (count == 2 && info->stack.b.arr[0] < info->stack.b.arr[1])
			set_sa_sb(&info->stack.b, 2);
		if (count != 0)
			set_pa_pb(&info->stack.a, &info->stack.b, 1, &sort);
		return ;
	}
	sort_info_init(&sort, &info->stack.b);
	
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
	sort_info_init(&sort, &info->stack.a);
	i = 0;
	while (i < count)
	{
		if (info->stack.a.arr[0] > sort.pivot1)
			set_ra_rb(&info->stack.a, 1, &sort);
		else
			set_pa_pb(&info->stack.b, &info->stack.a, 1, &sort);
		i++;
	}
	i = -1;
	while (i++ < sort.ra_count  && count != info->count)
		set_rra_rrb(&info->stack.a, 1);
	a_to_b(info, sort.ra_count);
	//b_to_a(info, sort.pb_count);
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
