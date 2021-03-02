/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:31:18 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/13 18:24:21 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	charset_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count + 1);
}

size_t	start_set(char *s, char c, size_t end)
{
	size_t	i;

	i = end;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

size_t	end_set(char *s, char c, size_t start)
{
	size_t	i;

	i = start;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	char	**arr;
	size_t	end;
	size_t	i;

	if (s == 0)
		return (0);
	if (!(arr = (char**)malloc(sizeof(char *) * charset_count((char*)s, c))))
		return (0);
	i = 0;
	end = 0;
	while (s[end])
	{
		start = start_set((char*)s, c, end);
		end = end_set((char*)s, c, start);
		if (end - start != 0)
		{
			if (!(arr[i] = (char*)malloc(sizeof(char) * (end - start + 1))))
				return (0);
			ft_strlcpy(arr[i++], ((char*)&s[start]), end - start + 1);
		}
	}
	arr[i] = 0;
	return (arr);
}
