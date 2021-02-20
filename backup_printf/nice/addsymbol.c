/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addsymbol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:54:06 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 17:13:20 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(char *save, t_print *p)
{
	char *pre;
	char *tmp;

	if ((p->spec == 'x' || p->spec == 'X') && *save && *save != '0')
		p->sharp_x = 1;
	if (p->spec == 'o' && *save != '0')
		pre = ft_strdup("0");
	else if (p->spec == 'x' && p->sharp_x)
		pre = ft_strdup("0x");
	else if (p->spec == 'X' && p->sharp_x)
		pre = ft_strdup("0X");
	else
		return (save);
	tmp = save;
	save = ft_strjoin(pre, save);
	free(pre);
	free(tmp);
	return (save);
}

char	*ft_addplus(char *save, t_print p)
{
	char *join;
	char *pre;
	long c;

	c = (long)p.plus;
	pre = ft_chrdup(c);
	join = ft_strjoin(pre, save);
	free(pre);
	free(save);
	return (join);
}
