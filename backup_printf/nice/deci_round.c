/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:42:26 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 19:55:47 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round_over5(int i, t_print *p)
{
	p->dans[2100 - i] = 0;
	if (i)
		p->dans[2100 - i + 1]++;
	else
		p->ians[0]++;
}

void	ft_round_is5(int pcs, t_print *p)
{
	int	j;

	p->dans[2100 - pcs] = 0;
	if (pcs == 0 && p->ians[0] % 2)
		p->ians[0]++;
	else if (pcs && (p->dans[2100 - pcs + 1] % 2))
		p->dans[2100 - pcs + 1]++;
	else
	{
		j = 2100;
		while (j > pcs && !p->dans[2100 - j])
			j--;
		if (j != pcs)
		{
			if (pcs == 0)
				p->ians[0]++;
			else
				p->dans[2100 - pcs + 1]++;
		}
	}
}

void	ft_round_moveup(int pcs, t_print *p)
{
	int	j;

	j = -1;
	while (++j < 2100)
	{
		if (p->dans[j] > 9)
		{
			p->dans[j] -= 10;
			p->dans[j + 1]++;
		}
	}
	if (p->dans[2100] > 9 || (pcs == 0 && p->dans[2100] > 5))
	{
		p->dans[2100] -= 10;
		p->ians[0]++;
	}
	j = -1;
	while (++j < 800)
	{
		if (p->ians[j] > 9)
		{
			p->ians[j] -= 10;
			p->ians[j + 1]++;
		}
	}
}

void	ft_round(t_print *p)
{
	int	i;

	i = p->pcs;
	if (p->dans[2100 - i] > 5)
		ft_round_over5(i, p);
	if (p->dans[2100 - i] == 5)
		ft_round_is5(i, p);
	ft_round_moveup(i, p);
}
