#include "push_swap.h"

void	arr5_sort(t_info *info, int count)
{
	info->pivot1 = set_pivot(info->stack.a, info, count);
	while (info->stack.a->next != 0 && info->stack.a->next->next != 0)
	{
		if (info->stack.a->data > info->pivot1)
			set_ra_rb(&info->stack.a, 1, &info->sort);
		else
			set_pa_pb(&info->stack.b, &info->stack.a, 2, &info->sort);
	}
	if (info->stack.a->data > info->stack.a->next->data)
		set_sa_sb(&info->stack.a, 1);
	info->pivot1 = set_pivot(info->stack.b, info, count - 2);
	while (info->stack.b->next != 0 && info->stack.b->next->next != 0)
	{
		if (info->stack.b->data <= info->pivot1)
			set_ra_rb(&info->stack.b, 2, &info->sort);
		else
			set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
	}
	if (info->stack.b->data < info->stack.b->next->data)
		set_sa_sb(&info->stack.b, 2);
	set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
	set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
}

void	arr3_sort(t_info *info, int count)
{
	set_pa_pb(&info->stack.b, &info->stack.a, 2, &info->sort);
	if (info->stack.a->data > info->stack.a->next->data)
		set_sa_sb(&info->stack.a, 1);
	if (info->stack.a->next->data < info->stack.b->data)
	{
		set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
		set_ra_rb(&info->stack.a, 1, &info->sort);
	}
	else if (info->stack.a->data < info->stack.b->data)
	{
		set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
		set_sa_sb(&info->stack.a, 1);
	}
	else
		set_pa_pb(&info->stack.a, &info->stack.b, 1, &info->sort);
}