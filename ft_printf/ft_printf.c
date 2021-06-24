/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:37:36 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/23 18:39:01 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	if (info->type == 'c')
		return (c_format(va_arg(ap, int), info));
	else if (info->type == 's')
		return (s_format(va_arg(ap, char *), info));
	else if (info->type == 'd' || info->type == 'i')
		return (d_format(ap, info));
	else if (info->type == 'u')
		return (u_format(ap, info));
	else if (info->type == 'p')
		return (p_format(va_arg(ap, unsigned long long), info));
	else if (info->type == 'x' || info->type == 'X')
		return (x_format(ap, info));
	else if (info->type == '%')
		return (c_format('%', info));
	return (0);
}

void	star_flags(t_info *info, va_list ap)
{
	int		star_width;
	char	*temp;
	int		i;

	star_width = va_arg(ap, int);
	temp = ft_itoa(star_width);
	i = 0;
	while (temp[i])
		check_flags(temp[i++], info, ap);
	free(temp);
}

void	check_flags(char format_ch, t_info *info, va_list ap)
{
	if (format_ch == '.' && !info->dot)
		info->dot = 1;
	else if (format_ch == '0' && !info->zero &&
			info->width == 0 && info->prec == 0)
		info->zero = 1;
	else if (format_ch == '-' && info->dot)
	{
		info->prec_flag = 1;
		info->prec = 1;
	}
	else if (format_ch == '-' && !info->minus && info->width == 0)
		info->minus = 1;
	else if (ft_isdigit(format_ch) && !info->dot)
		info->width = (info->width * 10) + (format_ch - '0');
	else if (ft_isdigit(format_ch) && !info->prec_flag)
		info->prec = (info->prec * 10) + (format_ch - '0');
	else if (format_ch == '*')
		star_flags(info, ap);
	else if (format_ch == 'l')
		info->l_format++;
	else if (format_ch == 'h')
		info->h_format++;
	else if (format_ch == '+')
		info->plus = 1;
}

int		ft_format(char *format, va_list ap, int i)
{
	t_info	*info;
	int		len;

	len = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (0);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			len += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			set_info(info);
			while (format[++i] && ft_strchr(TYPE, format[i]) == 0)
				check_flags(format[i], info, ap);
			info->type = format[i];
			if (format[i] && ft_strchr(TYPE, format[i]))
				len += print_type(ap, info);
			if (info->type == 'n')
				n_format(len, ap, info);
			i += format[i] && ft_strchr(TYPE, format[i]) ? 1 : 0;
		}
	}
	free(info);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	va_start(ap, format);
	len = ft_format((char *)format, ap, i);
	va_end(ap);
	return (len);
}
