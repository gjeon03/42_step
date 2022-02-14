/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:02:45 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/23 16:15:22 by gjeon            ###   ########.fr       */
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
	info->l_format = 0;
	info->h_format = 0;
	info->plus = 0;
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

void	h_hh_type(va_list ap, void *nb, t_info *info)
{
	if (info->type == 'd' || info->type == 'i')
	{
		if (info->h_format == 2)
			*(long long *)nb = (signed char)va_arg(ap, int);
		else if (info->h_format == 1)
			*(long long *)nb = (short int)va_arg(ap, int);
	}
	else
	{
		if (info->h_format == 2)
			*(unsigned long long *)nb = (unsigned char)va_arg(ap, unsigned int);
		else if (info->h_format == 1)
			*(unsigned long long *)nb =
				(unsigned short int)va_arg(ap, unsigned int);
	}
}

void	l_ll_type(va_list ap, void *nb, t_info *info)
{
	if (info->type == 'd' || info->type == 'i')
	{
		if (info->l_format == 2)
			*(long long *)nb = va_arg(ap, long long);
		else if (info->l_format == 1)
			*(long long *)nb = va_arg(ap, long);
		else if (info->h_format > 0)
			h_hh_type(ap, nb, info);
		else
			*(long long *)nb = va_arg(ap, int);
	}
	else
	{
		if (info->l_format == 2)
			*(unsigned long long *)nb = va_arg(ap, unsigned long long);
		else if (info->l_format == 1)
			*(unsigned long long *)nb = va_arg(ap, unsigned long);
		else if (info->h_format > 0)
			h_hh_type(ap, nb, info);
		else
			*(unsigned long long *)nb = va_arg(ap, unsigned int);
	}
}
