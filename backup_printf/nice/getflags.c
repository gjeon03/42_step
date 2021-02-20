/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:21:00 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 13:41:49 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	def(char c, long n)
{
	t_print	p;
	int		i;

	p.flag = c;
	p.sharp = n;
	p.sharp_x = n;
	p.plus = n;
	p.field = n;
	p.hhll = c;
	p.pcs = -1;
	p.spec = c;
	p.width = n;
	p.minus = n;
	p.show = n;
	p.isnan = c;
	p.exp = n;
	p.sdig = n;
	p.gflag = n;
	i = 0;
	while (i < 401)
		p.ians[i++] = 0;
	i = 0;
	while (i < 2101)
		p.dans[i++] = 0;
	return (p);
}

t_print	get_flag(const char **s, t_print p)
{
	int flag;
	int sharp;
	int plus;

	while (**s == '0' || **s == '-' || **s == '#' || **s == ' ' || **s == '+')
	{
		if (**s == '0' || **s == '-')
		{
			p.flag |= **s;
			(*s)++;
		}
		else if (**s == '#')
		{
			p.sharp |= **s;
			(*s)++;
		}
		else if (**s == ' ' || **s == '+')
		{
			p.plus |= **s;
			(*s)++;
		}
	}
	return (p);
}

int		get_precision(const char **s, va_list *list)
{
	long	i;
	int		sign;

	i = 0;
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			(*s)++;
			return (va_arg(*list, int));
		}
		sign = (**s == '-') ? -1 : 1;
		if (**s == '-')
			(*s)++;
		while (ft_isdigit(**s))
		{
			i = i * 10 + (**s - '0');
			(*s)++;
		}
		return (i * sign);
	}
	return (-1);
}

char	get_hhll(const char **s)
{
	if (**s == 'h')
	{
		(*s)++;
		if (**s == 'h')
		{
			(*s)++;
			return ('H');
		}
		else
			return ('h');
	}
	else if (**s == 'l')
	{
		(*s)++;
		if (**s == 'l')
		{
			(*s)++;
			return ('L');
		}
		else
			return ('l');
	}
	return (0);
}

t_print	get_field(const char **s, va_list *list, t_print p)
{
	long i;

	i = 0;
	if (**s == '*')
	{
		(*s)++;
		i = va_arg(*list, int);
		if (i < 0)
			p.flag |= '-';
	}
	else if (**s != '0')
	{
		while (ft_isdigit(**s))
		{
			i = i * 10 + **s - '0';
			(*s)++;
		}
	}
	p.field = ABS(i);
	return (p);
}
