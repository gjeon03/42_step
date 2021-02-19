/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:57:49 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/19 17:48:13 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_format(char ch, t_info *info)
{
	int		len;
	char	str[2];

	str[0] = ch;
	str[1] = '\0';
	len = ft_putstr_l(str);
	return (len);
}

int	s_format(char *str, t_info *info)
{
	size_t	len;
	char	*temp;

	if (str == 0)
		str = "(null)";
	if (info->dot)
		temp = dot_flags(str, info);
	else
		temp = ft_strdup(str);
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}

int	d_format(int nb, t_info *info)
{
	char	*temp;
	char	*nb_str;
	int		len;

	nb_str = ft_itoa(nb);
	if (info->dot)
		temp = dot_flags(nb_str, info);
	else
		temp = nb_str;
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}
