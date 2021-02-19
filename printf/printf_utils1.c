/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 22:25:09 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/19 16:04:17 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_info(t_info *info)
{
	info->zero = 0;
	info->digit = 0;
	info->minus = 0;
	info->plus = 0;
	info->blank = 0;
	info->dot = 0;
	info->star = 0;
	info->dot_digit = 0;
	info->star_digit = 0;
}

int		ft_putchar(char ch)
{
	write(1, &ch, 1);
	return (1);
}

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
	if (n == 0)
		count++;
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[count] = '\0';
	i = n * (size_t)16;
	while (i /= 16)
		str[--count] = hexademical[i % 16];
	if (n == 0)
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
