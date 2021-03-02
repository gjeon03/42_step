/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:13:06 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/23 16:11:08 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_format(va_list ap, t_info *info)
{
	int		len;
	char	*nb_str;
	char	*temp;

	nb_str = ft_itoa_x(ap, info);
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

void	n_format(int nb, va_list ap, t_info *info)
{
	int				*len;
	signed char		*hh;
	short int		*h;
	long int		*l;
	long long int	*ll;

	if (info->h_format == 2)
		if (!!(hh = va_arg(ap, signed char *)))
			*hh = nb;
	if (info->h_format == 1)
		if (!!(h = va_arg(ap, short int *)))
			*h = nb;
	if (info->l_format == 2)
		if (!!(ll = va_arg(ap, long long int *)))
			*ll = nb;
	if (info->l_format == 1)
		if (!!(l = va_arg(ap, long int *)))
			*l = nb;
	if (nb != 0)
		if (!!(len = va_arg(ap, int *)))
			*len = nb;
}
