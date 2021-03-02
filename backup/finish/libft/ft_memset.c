/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:32:00 by gjeon             #+#    #+#             */
/*   Updated: 2021/02/20 22:23:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- > 0)
		((unsigned char*)b)[i++] = (unsigned char)c;
	((unsigned char*)b)[i] = '\0';
	return (b);
}
