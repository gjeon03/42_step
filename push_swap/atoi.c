/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:25:36 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 02:39:36 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('0' <= str[i] && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	j;
	int					sign;

	j = 0;
	sign = 1;
	i = check(str, &sign);
	if (digit_check((char *)str + i))
		return (0);
	while ('0' <= str[i] && str[i] <= '9')
	{
		j *= 10;
		j += (str[i] - '0');
		i++;
	}
	if (j > LLONG_MAX && sign == -1)
		return (0);
	if (j >= LLONG_MAX && sign == 1)
		return (-1);
	if (j > INT_MAX && sign == 1)
		return (0);
	if (j > (unsigned long long)INT_MAX + 1 && sign == -1)
		return (0);
	return (j * sign);
}
