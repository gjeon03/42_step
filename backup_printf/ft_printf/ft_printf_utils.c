/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:02:45 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 02:36:37 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_info(t_info *info)
{
	info->dot = 0;
	info->zero = 0;
	info->minus = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_flag = 0;
	info->sign = 0;
}

int		ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int		ft_putstr_l(char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len])
		write(1, &str[len++], 1);
	return (len);
}
