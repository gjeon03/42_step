/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:23:06 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/20 19:09:19 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(long long n)
{
	char		*str;
	int			len;
	long long	m;
	int			num;

	len = ft_intlen(n);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	m = n;
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	num = m % 10;
	num = ABS(num);
	str[--len] = num + '0';
	while (m /= 10)
	{
		num = m % 10;
		num = ABS(num);
		str[--len] = num + '0';
	}
	return (str);
}
