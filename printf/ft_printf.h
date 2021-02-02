/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:10:30 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/02 16:38:42 by gjeon            ###   ########.fr       */
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

typedef struct s_info
{
	char	type;
}			t_info;

int	ft_printf(const char *format, ...);

#endif
