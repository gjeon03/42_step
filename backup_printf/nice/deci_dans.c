/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_dans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:43:37 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 22:00:38 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dans_fix(t_print *p, int j)
{
	p->dans[j] -= 10;
	p->dans[j + 1]++;
}

void	make_dans2(int dbox[2101], int dbit[2101], t_print *p)
{
	int	i;
	int	j;

	i = 2101;
	while (--i >= 0)
	{
		if (dbit[i])
		{
			j = 0;
			while (++j < 2101)
				if ((p->dans[j] += dbox[j]) > 9)
					dans_fix(p, j);
		}
		j = 0;
		while (++j < 2101)
		{
			if (dbox[j] % 2)
				dbox[j - 1] += 5;
			dbox[j] /= 2;
		}
	}
}

void	make_dans(unsigned long long manti, int exp, t_print *p)
{
	int	dbox[2101];
	int	dbit[2101];
	int	i;
	int	j;

	i = 0;
	while (i < 2101)
	{
		dbox[i] = 0;
		dbit[i++] = 0;
	}
	dbox[2100] = 5;
	i = 52 - exp;
	j = 0;
	while (--i >= 0)
	{
		if (i < 53)
			dbit[2100 - j] = 1 & (manti >> i);
		j++;
	}
	make_dans2(dbox, dbit, p);
}
