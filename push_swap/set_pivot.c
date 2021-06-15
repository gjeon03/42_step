#include "push_swap.h"

int		set_pivot(t_stack_ls *stack, t_info *info)
{
	int			count;
	t_stack_ls	*tmp;
	int			pivot;
	t_stack_ls	*tmp2;

	tmp = stack;
	while (tmp != NULL)
	{
		count = 0;
		tmp2 = stack;
		pivot = tmp->data;
		if (tmp2 == NULL)
			return (0) ;
		while (tmp2 != NULL)
		{
			if (pivot > tmp2->data)
				count++;
			tmp2 = tmp2->next;
		}
		if (count == info->count / 2)
		{
			info->pivot = pivot;
			return (pivot);
		}
		tmp = tmp->next;
	}
	return (0);
}