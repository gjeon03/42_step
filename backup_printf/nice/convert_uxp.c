/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:39:40 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 23:08:56 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_st(size_t n)
{
	char		*str;
	int			len;
	size_t		m;
	int			num;

	len = 1;
	m = n;
	while (m /= 10)
		len++;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	str[--len] = n % 10 + '0';
	while (n /= 10)
		str[--len] = n % 10 + '0';
	return (str);
}

char	*ft_convert_p(size_t n, char *set, t_print p)
{
	char	*pre;
	char	*saf;
	char	*save;

	pre = ft_strdup("0x");
	if (!n && p.pcs == 0)
		saf = ft_strdup("");
	else if (!n)
		saf = ft_strdup("0");
	else
		saf = ft_convert(n, set, 16);
	save = ft_strjoin(pre, saf);
	if (pre)
		free(pre);
	if (saf)
		free(saf);
	return (save);
}

char	*ft_convert(size_t n, const char *set, int base)
{
	char	*src;
	int		len;
	size_t	m;

	m = n;
	len = 1;
	while (m /= base)
		len++;
	if (!(src = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	src[len] = '\0';
	src[--len] = set[n % base];
	while (n /= base)
		src[--len] = set[n % base];
	return (src);
}

char	*ft_convert_uxp(va_list *list, t_print p)
{
	char	*save;
	size_t	n;

	n = 0;
	if (p.hhll == 'L' || p.spec == 'p')
		n = va_arg(*list, unsigned long long int);
	else if (p.hhll == 'l')
		n = va_arg(*list, unsigned long int);
	else if (p.hhll == 'h')
		n = (unsigned short int)va_arg(*list, unsigned int);
	else if (p.hhll == 'H')
		n = (unsigned char)va_arg(*list, unsigned int);
	else
		n = va_arg(*list, unsigned int);
	if (p.spec == 'u')
		save = ft_itoa_st(n);
	if (p.spec == 'x')
		save = ft_convert(n, "0123456789abcdef", 16);
	if (p.spec == 'X')
		save = ft_convert(n, "0123456789ABCDEF", 16);
	if (p.spec == 'p')
		save = ft_convert_p(n, "0123456789abcdef", p);
	if (p.spec == 'o')
		save = ft_convert(n, "01234567", 8);
	return (save);
}
