/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:47:39 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 21:51:16 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	make_fans(double d, t_print *p)
{
	unsigned long long	val;
	unsigned long long	manti;
	int					exp;

	manti = 0;
	val = *(unsigned long long*)&d;
	if (d)
		manti = (val & ((1ULL << 52) - 1)) + (1ULL << 52);
	val >>= 52;
	exp = val & ((1 << 11) - 1);
	exp -= 1023;
	val >>= 11;
	p->minus = val ? -1 : 0;
	if (exp == 1024)
		ft_nanflag(manti, p);
	make_ians(manti, exp, p);
	make_dans(manti, exp, p);
}

char	*make_fpre(t_print *p)
{
	char	*pre;
	char	*minus;
	char	*tmp;
	int		i;
	int		j;

	i = 800;
	while (!p->ians[i] && i)
		i--;
	if (!(pre = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	j = i + 1;
	while (--j >= 0)
		pre[i - j] = (p->ians[j] + '0');
	pre[i + 1] = '\0';
	if (p->minus)
	{
		minus = ft_chrdup('-');
		tmp = pre;
		pre = ft_strjoin(minus, pre);
		free(minus);
		free(tmp);
	}
	return (pre);
}

char	*ft_deci_save(t_print *p)
{
	char	*save;
	char	*pre;
	char	*saf;

	if (p->gflag && !p->sharp)
		saf = make_gsaf(p);
	else if (p->gflag && p->sharp)
		saf = make_sgsaf(p);
	else
		saf = make_fsaf(p);
	pre = make_fpre(p);
	save = ft_strjoin(pre, saf);
	free(pre);
	free(saf);
	return (save);
}

char	*ft_deci(va_list *list, t_print *p)
{
	double	d;
	int		exp;
	char	*save;

	d = va_arg(*list, double);
	p->pcs = MIN(2100, p->pcs);
	if (p->pcs < 0)
		p->pcs = 6;
	if (p->spec == 'g' && p->pcs == 0)
		p->pcs = 1;
	make_fans(d, p);
	if (p->isnan)
		return (ft_isnan(p->isnan));
	if (p->gflag)
		check_deci(p);
	if (p->spec == 'e')
		convert_deci(p);
	ft_round(p);
	if (p->spec == 'e' || (p->gflag && p->sdig == 1 && p->pcs == 0))
		ft_echeck(p);
	return (ft_deci_save(p));
}
