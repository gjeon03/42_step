#include "push_swap.h"

int		set_pivot(t_array_stack *stack, int range)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < range)
	{
		count = 0;
		j = 0;
		while (j < range)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == (range) / 2)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("Error\n"));
}

int		set_pivot1(t_array_stack *stack, int range)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < range)
	{
		count = 0;
		j = 0;
		while (j < range)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == (range) / 3)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("Error\n"));
}

int		set_pivot2(t_array_stack *stack, int range)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < range)
	{
		count = 0;
		j = 0;
		while (j < range)
		{
			if (stack->arr[i] < stack->arr[j])
				count++;
			j++;
		}
		if (count == ((range) / 3) * 2)
			return (stack->arr[i]);
		i++;
	}
	return (error_msg("Error\n"));
}
