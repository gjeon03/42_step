/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:57:56 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 15:14:48 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_c(va_list *list, t_print p)
{
	char	*save;
	long	j;

	if (p.hhll == 'l')
		save = ft_chrdup(va_arg(*list, long));
	else
		save = ft_chrdup((unsigned char)va_arg(*list, int));
	return (save);
}

int		ft_convert_n(va_list *list, size_t len, t_print p)
{
	signed char		*tmphh;
	short int		*tmph;
	long int		*tmpl;
	long long int	*tmpll;
	int				*tmp;

	if (p.hhll == 'H')
		if (!!(tmphh = va_arg(*list, signed char*)))
			*tmphh = len;
	if (p.hhll == 'h')
		if (!!(tmph = va_arg(*list, short int*)))
			*tmph = len;
	if (p.hhll == 'l')
		if (!!(tmpl = va_arg(*list, long int*)))
			*tmpl = len;
	if (p.hhll == 'L')
		if (!!(tmpll = va_arg(*list, long long int*)))
			*tmpll = len;
	if (p.hhll == 0)
		if (!!(tmp = va_arg(*list, int*)))
			*tmp = len;
	return (0);
}

char	*ft_convert_di(va_list *list, t_print *p)
{
	char		*save;
	long long	n;

	n = 0;
	if (p->hhll == 'l')
		n = va_arg(*list, long int);
	else if (p->hhll == 'L')
		n = va_arg(*list, long long int);
	else if (p->hhll == 'h')
		n = (short int)va_arg(*list, int);
	else if (p->hhll == 'H')
		n = (signed char)va_arg(*list, int);
	else
		n = va_arg(*list, int);
	save = ft_itoa(n);
	if (*save == '-')
		p->minus = 1;
	return (save);
}
