/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:11:44 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:49:14 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;

	i = 0;
	ch = (unsigned char *)s;
	while (i < n)
	{
		if (ch[i] == (unsigned char)c)
			return (ch + i);
		i++;
	}
	return (0);
}
