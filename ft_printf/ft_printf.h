/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:30 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/19 17:46:45 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef TYPE
#  define TYPE "csdiupxX%"
# endif

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./libft/libft.h"
#include <stdio.h>

typedef struct s_info
{
	char	type;
	int		dot;
	size_t	width;
	size_t	prec;
}			t_info;

void		check_flags(char ch, t_info *info, va_list ap);

int			ft_printf(const char *format, ...);
void		set_info(t_info *info);
int			c_format(char ch, t_info *info);
int			s_format(char *str, t_info *info);
int			d_format(int nb, t_info *info);

char		*dot_flags(char *nb_str, t_info *info);

int			ft_putchar(char ch);
int			ft_putstr_l(char *str);

#endif
