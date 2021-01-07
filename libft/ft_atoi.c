/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:25:36 by gjeon             #+#    #+#             */
/*   Updated: 2020/12/28 18:50:13 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' ||
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

int	ft_atoi(const char *str)
{
	int			i;
	long long	j;
	int			sign;

	j = 0;
	sign = 1;
	i = check(str, &sign);
	while ('0' <= str[i] && str[i] <= '9')
	{
		j *= 10;
		j += (str[i] - '0');
		i++;
	}
	if (sign > 0 && j >= 9223372036854775807)
		return (-1);
	return (j * sign);
}
