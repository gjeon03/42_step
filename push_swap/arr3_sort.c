#include "push_swap.h"

void	arr3_sort(t_info *info)
{
	while (1)
	{
		if (info->stack.a.arr[0] < info->stack.a.arr[1] &&
				info->stack.a.arr[0] < info->stack.a.arr[2])
		{
			set_pa_pb(&info->stack.b, &info->stack.a, 1, &info->sort);
			if (info->stack.a.arr[0] > info->stack.a.arr[1])
				set_sa_sb(&info->stack.a, 1);
			set_pa_pb(&info->stack.a, &info->stack.b, 2, &info->sort);
			break ;
		}
		else if (info->stack.a.arr[0] < info->stack.a.arr[1])
		{
			set_rra_rrb(&info->stack.a, 1);
			break ;
		}
		else
			set_ra_rb(&info->stack.a, 1, &info->sort);
	}
}
