/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:49:04 by gjeon             #+#    #+#             */
/*   Updated: 2020/12/27 18:49:39 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	src_size;
	size_t	dest_size;

	j = 0;
	src_size = 0;
	dest_size = 0;
	while (dest[dest_size] != 0)
		dest_size++;
	i = dest_size;
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	while (src[src_size] != 0)
		src_size++;
	if (size > dest_size)
		return (dest_size + src_size);
	return (dest_size + size);
}
