/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:24:50 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 02:12:42 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itoa_init(int *sign, size_t *i, int n)
{
	int	num;

	if (n < 0)
		*sign = -1;
	else
		*sign = 1;
	num = *sign;
	*i = n * (size_t)num;
}

size_t	set_count(int i, int n, int sign)
{
	int	count;

	count = 0;
	while (i)
	{
		count++;
		i /= 10;
	}
	if (n == 0 || sign < 0)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	i;
	int		sign;
	size_t	count;
	char	*str;

	itoa_init(&sign, &i, n);
	count = set_count(i, n, sign);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == 0)
		return (0);
	str[count] = '\0';
	i = n * (size_t)sign;
	while (i)
	{
		str[--count] = '0' + (i % 10);
		i /= 10;
	}
	if (sign < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
