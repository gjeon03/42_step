/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_ians_nanflag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:44:10 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 21:51:17 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ians_fix(t_print *p, int j)
{
	p->ians[j] -= 10;
	p->ians[j + 1]++;
}

void	make_ians2(int ibox[801], int ibit[2101], t_print *p)
{
	int	i;
	int j;

	i = -1;
	while (++i <= 2100)
	{
		if (ibit[i])
		{
			j = 800;
			while (--j >= 0)
				if ((p->ians[j] += ibox[j]) > 9)
					ians_fix(p, j);
		}
		j = 800;
		while (--j >= 0)
		{
			if ((ibox[j] *= 2) > 9)
			{
				ibox[j] -= 10;
				ibox[j + 1]++;
			}
		}
	}
}

void	make_ians(unsigned long long manti, int exp, t_print *p)
{
	int	ibox[801];
	int	ibit[2101];
	int	i;
	int	j;

	i = 0;
	while (i < 801)
		ibox[i++] = 0;
	i = 0;
	while (i < 2101)
		ibit[i++] = 0;
	ibox[0] = 1;
	i = 52 - exp;
	j = 0;
	while (i < 53)
	{
		if (i >= 0)
			ibit[j] = 1 & (manti >> i);
		i++;
		j++;
	}
	make_ians2(ibox, ibit, p);
}

void	ft_nanflag(unsigned long long manti, t_print *p)
{
	if (!(manti & (((1ULL << 52) - 1))) && p->minus)
		p->isnan = 'I';
	else if (!(manti & (((1ULL << 52) - 1))) && !p->minus)
		p->isnan = 'i';
	else
	{
		p->isnan = 'n';
		p->plus = 0;
	}
	if (p->flag == '0')
		p->flag = 'R';
	p->pcs = 3;
}

char	*ft_isnan(char c)
{
	char *save;

	save = NULL;
	if (c == 'I')
		save = ft_strdup("-inf");
	if (c == 'i')
		save = ft_strdup("inf");
	if (c == 'n')
		save = ft_strdup("nan");
	return (save);
}
