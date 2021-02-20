/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:13:06 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 06:36:12 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_format(unsigned int nb, t_info *info)
{
	int		len;
	char	*nb_str;
	char	*temp;

	nb_str = ft_itoa_x(nb, info);
	if (info->minus)
		temp = width_prec(nb_str, info);
	else if (info->dot && !info->prec_flag)
		temp = width_prec(nb_str, info);
	else if (info->zero && info->width > ft_strlen(nb_str))
		temp = zero_flags(nb_str, info);
	else if (info->width)
		temp = width_prec(nb_str, info);
	else
		temp = nb_str;
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}

void	n_format(int nb, va_list ap)
{
	int	*len;

	if (nb != 0)
	{
		len = va_arg(ap, int *);
		*len = nb;
	}
}
