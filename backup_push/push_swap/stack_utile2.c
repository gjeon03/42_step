#include "push_swap.h"

t_stack_ls	*stack_lslast(t_stack_ls *lst)
{
	t_stack_ls	*tmp;

	if (lst)
	{
		while (lst->next)
		{
			if (lst->next->next == 0)
				tmp = lst;
			lst = lst->next;
		}
	}
	tmp->next = 0;
	return (lst);
}

int			stack_lssize(t_stack_ls *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}