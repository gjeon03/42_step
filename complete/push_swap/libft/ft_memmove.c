/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:10:17 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:50:58 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	if (s2 < s1)
		while (n--)
			((unsigned char *)s1)[n] = ((unsigned char *)s2)[n];
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
