/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:12:59 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:18:38 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == 0)
		return ((char *)s1);
	while (*s1 && n-- >= ft_strlen(s2))
	{
		if (*s1 == *s2)
		{
			if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
				return ((char *)s1);
		}
		s1++;
	}
	return (0);
}
