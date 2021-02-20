/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 00:27:25 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 19:59:21 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make_save2(va_list *list, t_print p, char *save)
{
	if (ft_isnum(p.spec) && !is_deci(p.spec)
			&& p.pcs == 0 && !ft_strncmp(save, "0\0", 2))
		*save = '\0';
	if (p.sharp)
		save = ft_sharp(save, &p);
	if (p.plus && !p.minus && ft_isnum(p.spec))
		save = ft_addplus(save, p);
	p.width = ft_strlen(save);
	if (ft_isnump(p.spec) && p.flag == '0' && p.pcs < 0)
		p.show = MAX(p.field, p.width);
	else if (is_deci(p.spec) && p.flag == '0')
		p.show = MAX(p.field, p.width);
	else if (p.spec == 'p' || p.sharp_x)
		p.show = MAX(p.width, p.pcs + 2);
	else if (ft_isnum(p.spec))
		p.show = MAX(p.width, (p.pcs + ((p.minus + p.plus) != 0)));
	else if (p.flag == '0')
		p.show = MAX(p.field, p.width);
	else if (p.spec == 'c' || p.spec == '%')
		p.show = 1;
	else
		p.show = (p.pcs < 0) ? p.width : MIN(p.width, p.pcs);
	p.field = MAX(p.field, p.show);
	pout(save, p);
	return (p.field);
}

int	make_save1(va_list *list, t_print p, size_t len)
{
	char	*save;

	if (p.spec == 'c')
		save = ft_convert_c(list, p);
	else if (p.spec == 's')
		save = ft_strdup(va_arg(*list, char*));
	else if (p.spec == 'd' || p.spec == 'i')
		save = ft_convert_di(list, &p);
	else if (is_deci(p.spec))
		save = ft_deci(list, &p);
	else if (ft_isnump(p.spec))
		save = ft_convert_uxp(list, p);
	else if (p.spec == '%')
		save = ft_strdup("%");
	else if (p.spec == 'n')
		return (ft_convert_n(list, len, p));
	else
		return (0);
	if (!save)
		save = ft_strdup("(null)");
	return (make_save2(list, p, save));
}

int	parse(const char **s, va_list *list, size_t len)
{
	t_print	p;

	p = def(0, 0);
	p = get_flag(s, p);
	p = get_field(s, list, p);
	p.pcs = get_precision(s, list);
	p.hhll = get_hhll(s);
	p.spec = **s;
	if (p.spec == 'g')
		p.gflag = 1;
	if (p.flag & 1)
		p.flag = 'L';
	else if (p.flag & (1 << 4))
		p.flag = '0';
	else
		p.flag = 'R';
	if (is_spec(**s))
		(*s)++;
	return (make_save1(list, p, len));
}

int	ft_printf(const char *s, ...)
{
	va_list list;
	size_t	len;

	len = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar_fd(*s++, 1);
			len++;
		}
		else if (*s++ == '%')
			len += parse(&s, &list, len);
	}
	va_end(list);
	return (len);
}
