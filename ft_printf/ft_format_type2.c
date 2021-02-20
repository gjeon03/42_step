/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:13:06 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/20 01:59:24 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_format(unsigned int nb, t_info *info)
{
	int		len;
	char	*nb_str;
	char	*temp;

	nb_str = ft_itoa_x(nb, info);
	if (info->dot || info->width)
		temp = width_prec(nb_str, info);
	else
		temp = nb_str;
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}
