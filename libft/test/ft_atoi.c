/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 22:25:36 by gjeon             #+#    #+#             */
/*   Updated: 2020/12/21 22:56:35 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *str, int *sign)
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

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	sign = 1;
	i = check(str, &sign);
	while ('0' <= str[i] && str[i] <= '9')
	{
		j *= 10;
		j += (str[i] - '0');
		i++;
	}
	return (j * sign);
}
