/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:00:47 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/03 00:47:50 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(va_list ap, t_info info)
{
	if (info.type == 'c')
		return (c_format(va_arg(ap, int)));
	else if (info.type == '%')
		return (c_format('%'));
	else if (info.type == 's')
		return (s_format(va_arg(ap, char *)));
	else if (info.type == 'd' || info.type == 'i')
		return (0);
	else if (info.type == 'u')
		return (0);
	else if (info.type == 'p')
		return (0);
	else if (info.type == 'x')
		return (0);
	else if (info.type == 'X')
		return (0);
	return (0);
}

int	ft_format(char *format, va_list ap)
{
	int		i;
	t_info	info;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			len++;
			ft_putchar_fd(format[i++], 1);
		}
		if (format[i] == '%')
		{
			if (format[++i] && ft_strchr(TYPE, format[i]) != 0)
			{
				info.type = format[i];
				len += print_type(ap, info);
			}
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_format((char *)format, ap);
	va_end(ap);
	return (len);
}
