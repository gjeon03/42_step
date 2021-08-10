/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:18:50 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:18:52 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(char *str, t_info *info)
{
	ft_putstr_fd(str, 1);
	if (info->stack.a.arr && info->stack.b.arr)
	{
		free(info->stack.a.arr);
		free(info->stack.b.arr);
	}
	exit(0);
	return (-1);
}
