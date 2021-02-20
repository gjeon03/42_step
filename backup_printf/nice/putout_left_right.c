/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putout_left_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:06:48 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/21 01:32:21 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putleft_num(char *save, t_print *p)
{
	if (p->spec == 'p' || p->sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		p->field -= 2;
		p->width -= 2;
		p->show -= 2;
	}
	if (p->minus || p->plus)
	{
		ft_putchar_fd(*save++, 1);
		p->field--;
		p->width--;
		p->show--;
	}
	while (p->field && (p->show > p->width))
	{
		ft_putchar_fd('0', 1);
		p->field--;
		p->show--;
	}
	while (p->show-- && p->field--)
		ft_putchar_fd(*save++, 1);
}

void	putleft(char *save, t_print p)
{
	if (!(ft_isnump(p.spec)))
	{
		while (p.show && p.field)
		{
			ft_putchar_fd(*save++, 1);
			p.show--;
			p.field--;
		}
	}
	else
		putleft_num(save, &p);
	while (p.field--)
		ft_putchar_fd(' ', 1);
}

char	*putright_num(char *save, t_print *p)
{
	if (p->spec == 'p' || p->sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		p->field -= 2;
		p->width -= 2;
		p->show -= 2;
	}
	if (p->minus || p->plus)
	{
		ft_putchar_fd(*save++, 1);
		p->show--;
		p->field--;
		p->width--;
	}
	while (p->show > p->width && p->field)
	{
		ft_putchar_fd('0', 1);
		p->show--;
		p->field--;
	}
	return (save);
}

void	putright(char *save, t_print p)
{
	while (p.field > p.show)
	{
		ft_putchar_fd(' ', 1);
		p.field--;
	}
	if (ft_isnump(p.spec))
		save = putright_num(save, &p);
	while (p.show--)
		ft_putchar_fd(*save++, 1);
	return ;
}
