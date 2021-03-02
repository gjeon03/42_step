/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:12:48 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/19 16:05:29 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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