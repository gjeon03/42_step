/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr3_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:18:31 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:18:35 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arr3_sort(t_info *info)
{
	if (info->stack.a.arr[0] > info->stack.a.arr[1])
		set_sa_sb(&info->stack.a, 1);
	if (info->stack.a.arr[1] > info->stack.a.arr[2])
	{
		set_rra_rrb(&info->stack.a, 1);
		if (info->stack.a.arr[0] > info->stack.a.arr[1])
			set_sa_sb(&info->stack.a, 1);
	}
}
