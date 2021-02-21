/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_itoa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 01:06:40 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 22:30:28 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_d(va_list ap, t_info *info)
{
	long long	i;
	long long	count;
	char		*str;
	long long	nb;

	count = 0;
	if (info->l_format == 1)
		nb = va_arg(ap, long);
	else
		nb = info->l_format == 2 ? va_arg(ap, long long) : va_arg(ap, int);
	info->sign = nb < 0 ? -1 : 1;
	i = nb * 10 * info->sign;
	while (i /= 10)
		count++;
	if (nb == 0 || info->sign < 0)
		count++;
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	i = nb * 10 * info->sign;
	while (i /= 10)
		str[--count] = '0' + (i % 10);
	str[0] = info->sign < 0 ? '-' : str[0];
	str[0] = nb == 0 ? '0' : str[0];
	return (str);
}

char	*ft_itoa_u(va_list ap, t_info *info)
{
	unsigned long long	i;
	unsigned long long	count;
	char				*str;
	unsigned long long	nb;

	count = 0;
	if (info->l_format == 1)
		nb = va_arg(ap, unsigned long);
	else if (info->l_format == 2)
		nb = va_arg(ap, unsigned long long);
	else
		nb = va_arg(ap, unsigned int);
	i = nb * 10;
	while (i /= 10)
		count++;
	if (nb == 0)
		count++;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	i = nb * 10;
	while (i /= 10)
		str[--count] = '0' + (i % 10);
	if (nb == 0)
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
