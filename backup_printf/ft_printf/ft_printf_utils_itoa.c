/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:06:40 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 03:52:51 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int n)
{
	size_t	i;
	size_t	count;
	char	*str;

	count = 0;
	i = n * (size_t)10;
	while (i /= 10)
		count++;
	if (n == 0)
		count++;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	i = n * (size_t)10;
	while (i /= 10)
		str[--count] = '0' + (i % 10);
	if (n == 0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa_p(unsigned long long n)
{
	size_t	i;
	size_t	count;
	char	*str;
	char	*hexademical;

	hexademical = ft_strdup("0123456789abcdef");
	count = 2;
	i = n * (size_t)16;
	while (i /= 16)
		count++;
	count += n == 0 ? 1 : 0;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[count] = '\0';
	i = n * (size_t)16;
	while (i /= 16)
		str[--count] = hexademical[i % 16];
	if (n == 0 && count > 2)
		str[2] = '0';
	free(hexademical);
	return (str);
}

char	*ft_itoa_x(unsigned int n, t_info *info)
{
	size_t	i;
	size_t	count;
	char	*str;
	char	*hexademical;

	if (info->type == 'x')
		hexademical = ft_strdup("0123456789abcdef");
	else if (info->type == 'X')
		hexademical = ft_strdup("0123456789ABCDEF");
	count = 0;
	i = n * (size_t)16;
	while (i /= 16)
		count++;
	if (n == 0)
		count++;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	i = n * (size_t)16;
	while (i /= 16)
		str[--count] = hexademical[i % 16];
	if (n == 0)
		str[0] = '0';
	free(hexademical);
	return (str);
}
