/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 21:18:20 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/17 02:02:06 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define X1 0x01
#define X2 0x02
#define X3 0x04
#define X4 0x08
#define X5 0x10
#define X6 0x20
#define X7 0x40
#define X8 0x80
#define FC1 0x80
#define FC2 0x800

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
