#include "push_swap.h"

void	set_ss(t_stack_ls **a, t_stack_ls **b)
{
	set_sa_sb(a, 0);
	set_sa_sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	set_rr(t_stack_ls **a, t_stack_ls **b, t_info *info)
{
	set_ra_rb(a, 0, info);
	set_ra_rb(b, 0, info);
	ft_putstr_fd("rr\n", 1);
}

void	set_rrr(t_stack_ls **a, t_stack_ls **b)
{
	set_rra_rrb(a, 0);
	set_rra_rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}