#include "push_swap.h"

void	set_ss(int *a, int *b)
{
	set_sa_sb(a, 0);
	set_sa_sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	set_rr(int *a, int *b, t_sort_info *sort)
{
	set_ra_rb(a, 0, sort);
	set_ra_rb(b, 0, sort);
	sort->rr_count++;
	ft_putstr_fd("rr\n", 1);
}

void	set_rrr(int *a, int *b)
{
	set_rra_rrb(a, 0);
	set_rra_rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
