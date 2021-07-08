#include "push_swap.h"

void	set_sa_sb(t_array_stack *stack, int flag)
{
	int	tmp;

	if (is_empty(stack) != TRUE)
	{
		tmp = stack->arr[1];
		stack->arr[1] = stack->arr[0];
		stack->arr[0] = tmp;
		if (flag == 1)
			ft_putstr_fd("sa\n", 1);
		else if (flag == 2)
			ft_putstr_fd("sb\n", 1);
	}
}

void	set_pa_pb(t_array_stack *a, t_array_stack *b, int flag, t_sort_info *sort)
{
	int	tmp;

	if (is_empty(b) != TRUE)
	{
		tmp = b->arr[0];
		stack_pop_first(b);
		stack_push_first(a, tmp);
		if (flag == 2)
		{
			ft_putstr_fd("pa\n", 1);
			sort->pa_count++;
		}
		else if (flag == 1)
		{
			ft_putstr_fd("pb\n", 1);
			sort->pb_count++;
		}
	}
}

void	set_ra_rb(t_array_stack *stack, int flag, t_sort_info *sort)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->arr[0];
		stack_pop_first(stack);
		stack_push_end(stack, tmp);
		if (flag == 1)
		{
			ft_putstr_fd("ra\n", 1);
			sort->ra_count++;
		}
		else if (flag == 2)
		{
			ft_putstr_fd("rb\n", 1);
			sort->rb_count++;
		}
	}
}

void	set_rra_rrb(t_array_stack *stack, int flag)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->arr[stack->top];
		stack_pop_end(stack);
		stack_push_first(stack, tmp);
		if (flag == 1)
			ft_putstr_fd("rra\n", 1);
		else if (flag == 2)
			ft_putstr_fd("rrb\n", 1);
	}
}
