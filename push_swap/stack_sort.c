#include "push_swap.h"

void	set_sa_sb(t_stack_ls **stack, int flag)
{
	t_stack_ls	*tmp;

	if ((*stack) != 0 && (*stack)->next != 0)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		stack_lsadd_front(stack, tmp);
	}
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("sb\n", 1);
}

void	set_pa_pb(t_stack_ls **a, t_stack_ls **b, int flag, t_info *info)
{
	t_stack_ls	*tmp;

	if (*b != 0)
	{
		tmp = *b;
		*b = (*b)->next;
		stack_lsadd_front(a, tmp);
	}
	if (flag == 1)
	{
		ft_putstr_fd("pa\n", 1);
		info->pa_count++;
	}
	else if (flag == 2)
	{
		ft_putstr_fd("pb\n", 1);
		info->pb_count++;
	}
}

void	set_ra_rb(t_stack_ls **a, int flag, t_info *info)
{
	t_stack_ls	*tmp;

	if (*a != 0)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = 0;
		stack_lsadd_back(a, tmp);
	}
	if (flag == 1)
	{
		ft_putstr_fd("ra\n", 1);
		info->ra_count++;
	}
	else if (flag == 2)
	{
		ft_putstr_fd("rb\n", 1);
		info->rb_count++;
	}
}

void	set_rra_rrb(t_stack_ls **a, int flag)
{
	t_stack_ls	*tmp;

	if (*a != 0 && (*a)->next != 0)
	{
		tmp = stack_lslast(*a);
		stack_lsadd_front(a, tmp);
	}
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rrb\n", 1);
}
