/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utile1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:19:43 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:43:43 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	malloc_stack(t_info *info, int total)
{
	info->stack.a.arr = malloc(sizeof(int) * total);
	if (info->stack.a.arr == 0)
		return (error_msg("Error\n", info));
	info->stack.b.arr = malloc(sizeof(int) * total);
	if (info->stack.b.arr == 0)
	{
		free(info->stack.a.arr);
		return (error_msg("Error\n", info));
	}
	stack_init(&info->stack.a);
	stack_init(&info->stack.b);
	return (1);
}

void	stack_init(t_array_stack *pstack)
{
	pstack->top = -1;
}

int	is_empty(t_array_stack *pstack)
{
	if (pstack->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

void	set_stack(t_info *info, char **str, int total)
{
	int		i;
	int		num;
	char	c;

	info->count = total;
	if (total == 1)
	{
		c = **str;
		if (!ft_isdigit(c))
			error_msg("Error\n", info);
	}
	if (!(malloc_stack(info, total)))
		return ;
	i = -1;
	while (++i < total)
	{
		num = ft_atoi(str[i]);
		if (num == 0 && ft_strlen(str[i]) > 1)
			error_msg("Error\n", info);
		stack_push_end(&info->stack.a, num);
	}
}
