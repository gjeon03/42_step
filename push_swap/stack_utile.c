#include "push_swap.h"

int		intlen(int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int		malloc_stack(t_info *info, int total)
{
	if (!(info->stack.a = malloc(sizeof(int) * total)))
		return (error_msg("ERROR\n"));
	if (!(info->stack.b = malloc(sizeof(int) * total)))
	{
		free(info->stack.a);
		return (error_msg("ERROR\n"));
	}
	ft_memset(info->stack.a, '\0', total);
	ft_memset(info->stack.b, '\0', total);
	return (1);
}

void stack_pop(Stack *pstack)
{
	if (is_empty(pstack) == TRUE)
		pstack->top -= 1;
}

void	stack_push(t_array_stack *pstack, int data)
{
	pstack->top += 1;
	pstack->arr[pstack->top] = data;
}

void	stack_init(t_array_stack *pstack)
{
	pstack->top = -1;
}

int		is_empty(t_array_stack *pstack)
{
	if (pstack->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

void	set_stack(t_info *info, char **str, int total)
{
	int	i;

	info->count = total;
	if (!(malloc_stack(info, total)))
		return ;
	i = -1;
	while (++i < total)
		info->a[i] = ft_atoi(str[i]);
}
