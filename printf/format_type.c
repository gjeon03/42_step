/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:29:28 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/03 00:45:27 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_format(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	s_format(char *str)
{
	size_t	len;

	len = 0;
	if (str == 0)
		str = "(null)";
	printf("ft==%s\n",str);
	/*while (str[len])
	{
		c_format(str[len++]);
		len++;
	}*/
	return (len);
}
