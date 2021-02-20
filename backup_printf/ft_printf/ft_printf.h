/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:30 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/21 03:53:08 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef TYPE
#  define TYPE "csdiupxX%"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_info
{
	char		type;
	int			zero;
	int			minus;
	int			dot;
	size_t		width;
	size_t		prec;
	int			prec_flag;
	int			sign;
}				t_info;

int				ft_printf(const char *format, ...);
int				ft_format(char *format, va_list ap);
int				printf_type(va_list ap, t_info *info);
void			check_flags(char ch, t_info *info, va_list ap);
void			star_flags(t_info *info, va_list ap);

int				c_format(char ch, t_info *info);
int				s_format(char *str, t_info *info);
int				d_format(int nb, t_info *info);
int				u_format(unsigned int nb, t_info *info);
int				p_format(unsigned long long nb, t_info *info);
int				x_format(unsigned int nb, t_info *info);

char			*width_prec(char *nb_str, t_info *info);
char			*prec_set(char *str, t_info *info);
char			*zero_flags(char *str, t_info *info);

char			*ft_itoa_u(unsigned int nb);
char			*ft_itoa_p(unsigned long long nb);
char			*ft_itoa_x(unsigned int nb, t_info *info);

void			set_info(t_info *info);
int				ft_putchar(char ch);
int				ft_putstr_l(char *str);

#endif
