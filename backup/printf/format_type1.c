/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_type1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:29:28 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/16 17:24:12 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_format(char ch, t_info *info)
{
	int		len;
	char	*str;

	len = 0;
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	str[0] = ch;
	str[1] = '\0';
	str = set_flags(str, info);
	len = ft_putstr_l(str);
	free(str);
	return (len);
}

int	s_format(char *str, t_info *info)
{
	size_t	len;
	char	*temp;

	len = 0;
	if (str == 0)
		str = "(null)";
	temp = ft_strdup(str);
	temp = set_flags(temp, info);
	len = ft_putstr_l(temp);
	free(temp);
	return (len);
}

int	d_format(int nb, t_info *info)
{
	char	*nb_str;
	int		len;

	nb_str = ft_itoa(nb);
	nb_str = set_flags(nb_str, info);
	len = ft_putstr_l(nb_str);
	free(nb_str);
	return (len);
}

int	u_format(unsigned int nb, t_info *info)
{
	char			*nb_str;
	int				len;

	nb_str = ft_itoa_u(nb);
	nb_str = set_flags(nb_str, info);
	len = ft_putstr_l(nb_str);
	free(nb_str);
	return (len);
}

int	p_format(unsigned long long nb, t_info *info)
{
	char	*nb_str;
	int		len;

	nb_str = ft_itoa_p(nb);
	len = ft_putstr_l(nb_str);
	nb_str = set_flags(nb_str, info);
	free(nb_str);
	return (len);
}
