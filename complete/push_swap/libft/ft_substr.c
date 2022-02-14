/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 01:29:39 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:49:50 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (ft_strlen(s) > start)
		ft_strlcpy(str, s + start, len + 1);
	else
		str[0] = '\0';
	return (str);
}
