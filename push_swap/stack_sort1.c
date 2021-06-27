#include "push_swap.h"

void	set_sa_sb(int *stack, int flag)
{
	int	tmp;

	if (stack[0] != NULL && stack[1] != NULL)
	{
		tmp = stack[1];
		stack[1] = stack[0];
		stack[0] = tmp;
	}
	if (flag == 1)
		ft_putstr_fd("sa\n", 1);
	else if (flag == 2)
		ft_putstr_fd("sb\n", 1);
}

void	set_pa_pb(int *a, int *b, int flag, t_sort_info *info)
{
	int	*tmp;

	if (b[0] != NULL)
	{
		tmp = b[0];
		ft_memmove(&b[0], &b[1], sizeof(int));
		//b[intlen(b) - 1] = NULL;
		ft_memmove(&a[1], &a[0], sizeof(int));
		a[0] = tmp;
	}
	if (flag == 2)
	{
		ft_putstr_fd("pa\n", 1);
		info->pa_count++;
	}
	else if (flag == 1)
	{
		ft_putstr_fd("pb\n", 1);
		info->pb_count++;
	}
}

void	set_ra_rb(int *stack, int flag, t_sort_info *info)
{
	int	tmp;

	if (stack[0] != NULL && stack[1] != NULL)
	{
		tmp = stack[0];
		ft_memmove(stack[0], stack[1], sizeof(int));
		//stack[intlen(stack) - 1] = NULL;
		stack[intlen(stack) - 1] = tmp;
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

void	set_rra_rrb(int *stack, int flag)
{
	int	tmp;

	if (stack[0] != NULL && stack[1] != NULL)
	{
		tmp = stack[intlen(stack) - 1];
		ft_memmove(stack[1], stack[0], sizeof(int));
		stack[0] = tmp;
	}
	if (flag == 1)
		ft_putstr_fd("rra\n", 1);
	else if (flag == 2)
		ft_putstr_fd("rrb\n", 1);
}
