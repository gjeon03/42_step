/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:48:24 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/16 22:58:00 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (c == 0)
		return ((char*)s + s_len);
	while (s_len--)
	{
		if (*(s + s_len) == c)
			return ((char*)s + s_len);
	}
	return (0);
}
