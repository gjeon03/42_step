/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:53:53 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/19 17:54:39 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dot_flags(char *str, t_info *info)
{
	char	*width_temp;
	char	*prec_temp;
	char	*temp;
	size_t	len;

	if (!(prec_temp = (char *)malloc(sizeof(char) * (info->prec + 1))))
		return (0);
	ft_memset(prec_temp, '0', info->prec);
	if (info->type == 's')
		ft_strlcpy(prec_temp , str, info->prec + 1);
	else
		ft_strlcpy(prec_temp + info->prec - ft_strlen(str), str, info->prec + 1);
	if (info->width > info->prec)
	{
		len = ft_strlen(prec_temp);
		if (!(width_temp = (char *)malloc(sizeof(char) * (info->width - len + 1))))
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
