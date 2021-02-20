/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:57:39 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/05 21:00:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_format(unsigned int nb, t_info *info)
{
	int		len;
	char	*nb_str;

	nb_str = ft_itoa_x(nb, info);
	nb_str = set_flags(nb_str, info);
	len = ft_putstr_l(nb_str);
	free(nb_str);
	return (len);
}
