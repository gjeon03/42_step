/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:30:04 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/07 21:55:26 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict s1, const void *restrict s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
		if (((unsigned char*)s2)[i] == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (0);
}
