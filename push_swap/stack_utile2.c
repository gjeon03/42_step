/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utile2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:19:50 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:19:51 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_pop_first(t_array_stack *pstack)
{
	if (is_empty(pstack) != TRUE)
	{
		ft_memmove(&pstack->arr[0], &pstack->arr[1], sizeof(int) * pstack->top);
		pstack->top -= 1;
	}
}

void	stack_pop_end(t_array_stack *pstack)
{
	if (is_empty(pstack) != TRUE)
		pstack->top -= 1;
}

void	stack_push_first(t_array_stack *pstack, int data)
{
	pstack->top += 1;
	ft_memmove(&pstack->arr[1], &pstack->arr[0], sizeof(int) * pstack->top);
	pstack->arr[0] = data;
}

void	stack_push_end(t_array_stack *pstack, int data)
{
	pstack->top += 1;
	pstack->arr[pstack->top] = data;
}
