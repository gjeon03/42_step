/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:53:53 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 04:49:26 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_flags(char *str, t_info *info)
{
	char	*temp;
	size_t	len;
	int		size;

	len = ft_strlen(str);
	if (!(temp = (char *)malloc(sizeof(char) * (info->width + 1))))
		return (0);
	ft_memset(temp, '0', info->width);
	size = info->width - len + info->sign;
	ft_strlcpy(temp + size, str + info->sign, len + 1);
	if (info->sign == 1)
		temp[0] = '-';
	free(str);
	return (temp);
}

char	*prec_set(char *str, t_info *info)
{
	char	*prec_temp;
	size_t	p_size;
	size_t	len;
	int		size;

	len = ft_strlen(str);
	p_size = (info->type == 's' && info->dot && !info->prec_flag) ||\
			(str[0] == '0' && info->dot && ft_strlen(str) == 1) ||\
			info->prec >= len ?\
			info->prec + info->sign : ft_strlen(str);
	if (!(prec_temp = (char *)malloc(sizeof(char) * (p_size + 1))))
		return (0);
	if (info->type == 's' && info->dot)
		ft_strlcpy(prec_temp, str, p_size + 1);
	else
	{
		ft_memset(prec_temp, '0', p_size);
		size = p_size - len + info->sign;
		ft_strlcpy(prec_temp + size, str + info->sign, p_size + 1);
		if (info->sign == 1)
			prec_temp[0] = '-';
	}
	return (prec_temp);
}

char	*width_prec(char *str, t_info *info)
{
	char	*width_temp;
	char	*prec_temp;
	char	*temp;
	size_t	len;

	prec_temp = prec_set(str, info);
	len = ft_strlen(prec_temp);
	if (info->width > len)
	{
		if (!(width_temp = (char *)malloc(sizeof(char) *\
						(info->width - len + 1))))
			return (0);
		ft_memset(width_temp, ' ', info->width - len);
	}
	else
		width_temp = ft_strdup("");
	if (info->minus == 1)
		temp = ft_strjoin(prec_temp, width_temp);
	else
		temp = ft_strjoin(width_temp, prec_temp);
	free(width_temp);
	free(prec_temp);
	return (temp);
}
