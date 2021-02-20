/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_type1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:57:49 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/20 01:58:54 by gjeon            ###   ########.fr       */
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
	if (info->dot || info->width)
		temp = width_prec(str, info);
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
	if (info->dot || info->width)
		temp = width_prec(nb_str, info);
	else
		temp = nb_str;
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}

int	u_format(unsigned int nb, t_info *info)
{
	char	*temp;
	char	*nb_str;
	int		len;

	nb_str = ft_itoa_u(nb);
	if (info->dot || info->width)
		temp = width_prec(nb_str, info);
	else
		temp = nb_str;
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}

int	p_format(unsigned long long nb, t_info *info)
{
	char	*nb_str;
	int		len;

	nb_str = ft_itoa_p(nb);
	len = ft_putstr_l(nb_str);
	free(nb_str);
	return (len);
}
