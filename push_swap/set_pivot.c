/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:19:11 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:31:05 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_pivot(t_array_stack *stack, int range)
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
