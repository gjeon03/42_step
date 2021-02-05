/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:00:47 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/06 00:44:48 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	if (info->type == 'c')
		return (c_format(va_arg(ap, int), info));
	else if (info->type == '%')
		return (c_format('%', info));
	else if (info->type == 's')
		return (s_format(va_arg(ap, char *), info));
	else if (info->type == 'd' || info->type == 'i')
		return (d_format(va_arg(ap, int), info));
	else if (info->type == 'u')
		return (u_format(va_arg(ap, unsigned int), info));
	else if (info->type == 'p')
		return (p_format(va_arg(ap, unsigned long long), info));
	else if (info->type == 'x' || info->type == 'X')
		return (x_format(va_arg(ap, unsigned int), info));
	return (0);
}

void	set_star(t_info *info, va_list ap)
{
	int		star_digit;
	char	*temp;
	int		i;

	info->star = 1;
	star_digit = va_arg(ap, int);
	temp = ft_itoa(star_digit);
	i = 0;
	printf("=====%s\n", temp);
	while (temp[i])
		check_flags(temp[i++], info, ap);
	free(temp);
}

void	check_flags(char format_ch, t_info *info, va_list ap)
{
	if (format_ch == '0' && !info->zero)
		info->zero = 1;
	else if (format_ch == '-' && !info->minus)
		info->minus = 1;
	else if (ft_isdigit(format_ch) && !info->dot)
		info->digit = (info->digit * 10) + (format_ch - '0');
	else if (format_ch == '.' && !info->dot)
		info->dot = 1;
	else if (ft_isdigit(format_ch))
		info->dot_digit = (info->dot_digit * 10) + (format_ch - '0');
	else if (format_ch == '*')
		set_star(info, ap);
	else if (format_ch == '+')
		info->plus = 1;
}

int		ft_format(char *format, va_list ap)
{
	int		i;
	t_info	*info;
	int		len;

	i = 0;
	len = 0;
	if (!(info = malloc(sizeof(t_info))))
		return (0);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			set_info(info);
			while (format[++i] && ft_strchr(TYPE, format[i]) == 0)
				check_flags(format[i], info , ap);
			info->type = format[i];
			len += print_type(ap, info);
			i++;
		}
	}
	free(info);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = ft_format((char *)format, ap);
	va_end(ap);
	return (len);
}
