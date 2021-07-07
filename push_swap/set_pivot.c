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
	/*
	* stack a,b info
	*/
	printf("-----pivot_stack-----\n");
	printf("range=%d\n", range);
	printf("top=%d\n", stack->top);
	for (int k = 0; k <= stack->top; k++)
		printf("%d ", stack->arr[k]);
	printf("\n-----------------\n");
	return (error_msg("ERROR\npivot\n"));
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
	return (error_msg("ERROR\npivot1\n"));
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
	/*
	* stack a,b info
	*/
	printf("-----pivot_stack-----\n");
	printf("range=%d\n", range);
	for (int k = 0; k <= stack->top; k++)
		printf("%d ", stack->arr[k]);
	printf("\n-----------------\n");
	return (error_msg("ERROR\npivot2\n"));
}
