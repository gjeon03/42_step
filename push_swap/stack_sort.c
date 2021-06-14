#include "push_swap.h"

void	set_sa_sb(t_stack_ls **stack)
{
	t_stack_ls	*tmp;

	if ((*stack) != 0 && (*stack)->next != 0)
	{
		tmp = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		stack_lsadd_front(stack, tmp);
	}
}

void	set_pa_pb(t_stack_ls **a, t_stack_ls **b)
{
	t_stack_ls	*tmp;

	if (*b != 0)
	{
		tmp = *b;
		*b = (*b)->next;
		stack_lsadd_front(a, tmp);
	}
}

void	set_ra_rb(t_stack_ls **a)
{
	t_stack_ls	*tmp;

	if (*a != 0)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = 0;
		stack_lsadd_back(a, tmp);
	}
}

void	set_rra_rrb(t_stack_ls **a)
{
	t_stack_ls	*tmp;

	if (*a != 0 && (*a)->next != 0)
	{
		tmp = stack_lslast(*a);
		stack_lsadd_front(a, tmp);
	}
}
