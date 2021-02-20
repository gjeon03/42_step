/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_check_and_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:39:49 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 19:40:50 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_deci2(t_print *p)
{
	int	i;
	int	j;

	i = -1;
	while (2101 + i > 0 && !p->dans[2101 + i])
		i--;
	p->exp = (i == -2101) ? 0 : i;
	p->ians[0] = p->dans[2101 + i];
	j = 0;
	while (2101 + i + --j >= 0)
		p->dans[2101 + j] = p->dans[2101 + i + j];
}

void	convert_deci(t_print *p)
{
	int i;
	int j;
	int k;

	i = 800;
	while (!p->ians[i] && i)
		i--;
	if (i > 0)
	{
		p->exp = i;
		j = -1;
		while (i + ++j <= 2100)
			p->dans[j] = p->dans[i + j];
		k = -1;
		while (j + ++k <= 2100)
		{
			p->dans[j + k] = p->ians[k];
			p->ians[k] = 0;
		}
		p->ians[0] = p->ians[k];
		p->ians[k] = 0;
	}
	if (i == 0 && p->ians[0] == 0)
		convert_deci2(p);
}

void	ft_echeck(t_print *p)
{
	int j;

	if (p->ians[1])
	{
		if (p->gflag)
			p->spec = 'e';
		p->exp++;
		j = -1;
		while (1 + ++j <= 2100)
			p->dans[j] = p->dans[1 + j];
		p->dans[2100] = p->ians[0];
		p->ians[0] = 0;
		p->ians[0] = p->ians[1];
		p->ians[1] = 0;
	}
}

void	check_deci2(t_print *p)
{
	int	i;

	i = -1;
	while (2101 + i > 0 && !p->dans[2101 + i])
		i--;
	p->exp = (i == -2101) ? 0 : i;
	if (p->exp)
	{
		i = -1;
		while (!p->dans[2100 - ++i])
			p->pcs++;
	}
	if (p->sharp)
		p->pcs--;
}

void	check_deci(t_print *p)
{
	int i;
	int tmp;

	tmp = p->pcs;
	i = 800;
	while (!p->ians[i] && i)
		i--;
	if (i > 0)
		p->exp = i;
	p->sdig = (i > 0 || (i == 0 && p->ians[0])) ? i + 1 : 0;
	p->pcs = (i > 0 || (i == 0 && p->ians[0])) ? p->pcs - p->sdig : p->pcs;
	if (i == 0 && p->ians[0] == 0)
		check_deci2(p);
	p->spec = (p->exp < -4 || p->pcs < 0) ? 'e' : 'f';
	p->pcs = (p->spec == 'e') ? tmp - 1 : p->pcs;
}
