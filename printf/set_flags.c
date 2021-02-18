/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 22:50:16 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/18 23:54:15 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_flags(char *nb_str, t_info *info)
{
	if (info->digit || info->dot)
	{
		if (info->minus)
		{
			if (ft_strlen(nb_str) < info->digit)
				nb_str = minus_flags(nb_str, info);
		}
		else
		{
			//if (ft_strlen(nb_str) < info->digit)
				nb_str = zero_flags(nb_str, info);
			if (info->plus && nb_str[0] != '-')
				nb_str[0] = '+';
		}
	}
	else if (info->plus && nb_str[0] != '-')
		nb_str = plus_flags(nb_str);
	return (nb_str);
}

char	*zero_flags(char *nb_str, t_info *info)
{
	char	*temp;
	size_t	len;
	int		minus;

	minus = nb_str[0] == '-' ? 1 : 0;
	len = ft_strlen(nb_str);
	if (!(temp = (char *)malloc(sizeof(char) *\
					(info->digit + 1))))
		return (0);
	if (info->zero || info->dot)
		ft_memset(temp, '0', info->digit + minus);
	else
		ft_memset(temp, ' ', info->digit + minus);
	ft_strlcpy(temp + (info->digit - len),\
			nb_str, len + 1);
	free(nb_str);
	return (temp);
}

char	*minus_flags(char *nb_str, t_info *info)
{
	char	*temp;
	size_t	len;
	int		minus;

	minus = nb_str[0] == '-' ? 1 : 0;
	len = ft_strlen(nb_str);
	if (!(temp = (char *)malloc(sizeof(char) *\
					(info->digit + 1))))
		return (0);
	ft_memset(temp, ' ', info->digit + minus);
	temp[info->digit] = '\0';
	ft_strlcpy(temp, nb_str, len + 1);
	temp[len] = ' ';
	free(nb_str);
	return (temp);
}

char	*plus_flags(char *nb_str)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(nb_str);
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	temp[0] = '+';
	ft_strlcpy(temp + 1, nb_str, len + 2);
	free(nb_str);
	return (temp);
}
