#include "push_swap.h"

void	set_ss(t_array_stack *a, t_array_stack *b)
{
	if (a->top > 0 && b->top > 0)
	{
		set_sa_sb(a, 0);
		set_sa_sb(b, 0);
		ft_putstr_fd("ss\n", 1);
	}
	else if (a->top > 0)
		set_sa_sb(a, 1);
	else if (b->top > 0)
		set_sa_sb(b, 2);
}

void	set_rr(t_array_stack *a, t_array_stack *b, t_sort_info *sort)
{
	if (a->top > 0 && b->top > 0)
	{
		set_ra_rb(a, 0, sort);
		set_ra_rb(b, 0, sort);
		sort->rr_count++;
		ft_putstr_fd("rr\n", 1);
	}
	else if (a->top > 0)
		set_ra_rb(a, 1, sort);
	else if (b->top > 0)
		set_ra_rb(b, 2, sort);
}

void	set_rrr(t_array_stack *a, t_array_stack *b)
{
	if (a->top > 0 && b->top > 0)
	{
		set_rra_rrb(a, 0);
		set_rra_rrb(b, 0);
		ft_putstr_fd("rrr\n", 1);
	}
	else if (a->top > 0)
		set_rra_rrb(a, 1);
	else if (b->top > 0)
		set_rra_rrb(b, 2);
	
}
