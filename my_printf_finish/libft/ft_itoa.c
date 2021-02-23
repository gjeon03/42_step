/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:24:50 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/14 01:07:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	int		sign;
	size_t	count;
	char	*str;

	count = 0;
	sign = 1;
	if (n < 0)
		sign = -1;
	i = n * (size_t)sign * 10;
	while (i /= 10)
		count++;
	if (n == 0 || sign < 0)
		count++;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	i = n * (size_t)sign * 10;
	while (i /= 10)
		str[--count] = '0' + (i % 10);
	if (sign < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	return (str);
}
