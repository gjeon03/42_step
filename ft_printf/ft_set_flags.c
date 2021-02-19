/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:53:53 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/20 02:01:37 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prec_set(char *str, t_info *info)
{
	char	*prec_temp;
	size_t	size;
	size_t	len;

	len = ft_strlen(str);
	size = (info->type == 's' && info->dot) ||\
			(str[0] == '0' && info->dot) ||\
			info->prec > len ?\
			info->prec : ft_strlen(str);
	if (!(prec_temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (info->type == 's' && info->dot)
		ft_strlcpy(prec_temp, str, size + 1);
	else
	{
		ft_memset(prec_temp, '0', size);
		ft_strlcpy(prec_temp + size - len, str, size + 1);
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
	temp = ft_strjoin(width_temp, prec_temp);
	free(width_temp);
	free(prec_temp);
	return (temp);
}
