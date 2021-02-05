/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:30 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/05 21:26:51 by gjeon            ###   ########.fr       */
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
	int		zero;
	size_t	digit;
	int		minus;
	int		plus;
	int		blank;
	int		dot;
	int		dot_digit;
	int		star;
	int		star_digit;
}			t_info;

void		check_flags(char ch, t_info *info, va_list ap);

int			ft_printf(const char *format, ...);
int			c_format(char ch, t_info *info);
int			s_format(char *str, t_info *info);
int			d_format(int nb, t_info *info);
int			u_format(unsigned int nb, t_info *info);
int			p_format(unsigned long long nb, t_info *info);
int			x_format(unsigned int nb, t_info *info);

int			ft_putchar(char ch);
int			ft_putstr_l(char *str);
void		set_info(t_info *info);
char		*ft_itoa_u(unsigned int nb);
char		*ft_itoa_p(unsigned long long nb);
char		*ft_itoa_x(unsigned int nb, t_info *info);
char		*set_flags(char *nb_str, t_info *info);
char		*zero_flags(char *nb_str, t_info *info);
char		*minus_flags(char *nb_str, t_info *info);
char		*plus_flags(char *nb_str);

int	print_str(char *str);

#endif
