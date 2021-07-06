#include "push_swap.h"

int		malloc_stack(t_info *info, int total)
{
	if (!(info->stack.a.arr = malloc(sizeof(int) * total)))
		return (error_msg("ERROR\n"));
	if (!(info->stack.b.arr = malloc(sizeof(int) * total)))
	{
		free(info->stack.a.arr);
		return (error_msg("ERROR\n"));
	}
	stack_init(&info->stack.a);
	stack_init(&info->stack.b);
	return (1);
}

/*int		stack_peek(t_array_stack *pstack) {
	if (is_empty(pstack) == TRUE)
		return (error_msg("ERROR\n"));
	return (pstack->arr[pstack->top]);                                                                       
}*/

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
		stack_push_end(&info->stack.a, ft_atoi(str[i]));
}
