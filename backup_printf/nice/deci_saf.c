/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deci_saf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 19:41:23 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 19:56:13 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_esaf2(t_print *p)
{
	char	*exnum;
	int		i;

	exnum = malloc(sizeof(char) * 4);
	exnum[0] = (p->exp < 0) ? '-' : '+';
	exnum[1] = '0';
	i = ABS(p->exp);
	exnum[2] = i + '0';
	exnum[3] = '\0';
	return (exnum);
}

char	*make_esaf(char *saf, t_print *p)
{
	char	*etxt;
	char	*exnum;
	char	*tmp;
	char	*tmp2;

	etxt = ft_strdup("e");
	if (p->exp < -9)
		exnum = ft_itoa(p->exp);
	else if (p->exp > 9)
	{
		tmp = ft_strdup("+");
		tmp2 = ft_itoa(p->exp);
		exnum = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		exnum = make_esaf2(p);
	tmp = ft_strjoin(etxt, exnum);
	free(etxt);
	free(exnum);
	tmp2 = ft_strjoin(saf, tmp);
	free(saf);
	free(tmp);
	return (tmp2);
}

char	*make_sgsaf(t_print *p)
{
	char	*saf;
	int		i;
	int		j;

	i = p->pcs;
	if (i < 2)
	{
		saf = ft_strdup(".");
		p->pcs = 0;
		i = 0;
	}
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = p->dans[2100 - j] + '0';
	if (p->spec == 'e')
		saf = make_esaf(saf, p);
	return (saf);
}

char	*make_gsaf(t_print *p)
{
	char	*saf;
	int		i;
	int		j;

	while (p->pcs && !p->dans[2101 - p->pcs])
		p->pcs--;
	i = p->pcs;
	if (i == 0)
		saf = ft_strdup("");
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = p->dans[2100 - j] + '0';
	if (p->spec == 'e')
		saf = make_esaf(saf, p);
	return (saf);
}

char	*make_fsaf(t_print *p)
{
	char	*saf;
	char	*etext;
	int		i;
	int		j;
	int		upnum;

	i = p->pcs;
	if (i == 0 && !p->sharp)
		saf = ft_strdup("");
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = p->dans[2100 - j] + '0';
	j = 0;
	if (p->spec == 'e')
		saf = make_esaf(saf, p);
	return (saf);
}
