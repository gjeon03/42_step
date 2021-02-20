/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:01:06 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/27 19:59:55 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isnum(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == 'f'
		|| c == 'e'
		|| c == 'g'
		|| c == 'o');
}

int	ft_isnump(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == 'p'
		|| c == 'f'
		|| c == 'e'
		|| c == 'g'
		|| c == 'o');
}

int	is_deci(char c)
{
	return (c == 'f'
		|| c == 'g'
		|| c == 'e');
}

int	putp(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	is_spec(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'o'
		|| c == 'u'
		|| c == 'x' || c == 'X'
		|| c == 'e' || c == 'E'
		|| c == 'f' || c == 'F'
		|| c == 'g' || c == 'G'
		|| c == 'a' || c == 'A'
		|| c == 'c' || c == 'C'
		|| c == 's' || c == 'S'
		|| c == 'p'
		|| c == 'n'
		|| c == 'm'
		|| c == '%');
}
