#include "push_swap.h"

int		set_pivot(t_array_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->top + 1)
	{
		count = 0;
		j = 0;
		while (j < stack->top + 1)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == (stack->top + 1) / 2)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("ERROR\npivot1\n"));
}

int		set_pivot1(t_array_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->top + 1)
	{
		count = 0;
		j = 0;
		while (j < stack->top + 1)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == (stack->top + 1) / 3)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("ERROR\npivot1\n"));
}

int		set_pivot2(t_array_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->top + 1)
	{
		count = 0;
		j = 0;
		while (j < stack->top + 1)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == ((stack->top + 1) / 3) * 2)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("ERROR\npivot2\n"));
}
