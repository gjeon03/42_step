/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:07:37 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/21 12:09:52 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wbyte(long n)
{
	int	i;

	if (n <= 255)
		return (1);
	i = 0;
	if (n >= FC5)
		i++;
	if (n >= FC4)
		i++;
	if (n >= FC3)
		i++;
	if (n >= FC2)
		i++;
	if (n >= FC1)
		i++;
	i++;
	return (i);
}

int		unicode_topindex(int size, long n)
{
	if (size == 1)
		return (n);
	else if (size == 2)
		return (0b11000000 + n);
	else if (size == 3)
		return (0b11100000 + n);
	else if (size == 4)
		return (0b11110000 + n);
	else if (size == 5)
		return (0b11111000 + n);
	else if (size == 6)
		return (0b11111100 + n);
	else
		return (0);
}

char	*ft_chrdup(long n)
{
	char	*chr;
	int		size;
	int		i;

	size = ft_wbyte(n);
	if (!(chr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	chr[i] = '\0';
	while (--i)
	{
		chr[i] = (X8 + n % X7);
		n /= X7;
	}
	chr[0] = unicode_topindex(size, n);
	return (chr);
}
