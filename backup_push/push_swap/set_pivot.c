#include "push_swap.h"

int		set_first_pivot(t_stack_ls *stack, t_info *info, int p_count)
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
		if (count == p_count / 3)
		{
			info->pivot = pivot;
			return (pivot);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		set_second_pivot(t_stack_ls *stack, t_info *info, int p_count)
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
		if (count == p_count * 2 / 3)
		{
			info->pivot = pivot;
			return (pivot);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		set_pivot(t_stack_ls *stack, t_info *info, int p_count)
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
		if (count == p_count / 2)
		{
			info->pivot = pivot;
			return (pivot);
		}
		tmp = tmp->next;
	}
	return (0);
}