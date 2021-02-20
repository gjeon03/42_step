/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putout_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:05:10 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/26 19:22:38 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putzero(char *save, t_print p)
{
	while (p.field > p.show)
	{
		ft_putchar_fd(' ', 1);
		p.field--;
	}
	if (p.spec == 'p' || p.sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		p.field -= 2;
		p.width -= 2;
		p.show -= 2;
	}
	if (ft_isnump(p.spec) && (p.minus || p.plus))
	{
		ft_putchar_fd(*save++, 1);
		p.field--;
		p.width--;
		p.show--;
	}
	while (p.show-- > p.width)
		ft_putchar_fd('0', 1);
	while (p.width--)
		ft_putchar_fd(*save++, 1);
	return ;
}

void	pout(char *save, t_print p)
{
	if (p.flag == 'L')
		putleft(save, p);
	else if (p.flag == '0')
		putzero(save, p);
	else if (p.flag == 'R')
		putright(save, p);
	if (save)
		free(save);
}
