/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 02:31:18 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:44:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	charset_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == 0)
		return (2);
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

char	**malloc_error(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

size_t	start_end(char *s, char c, size_t set, int division)
{
	size_t	i;

	i = set;
	if (division == 0)
	{
		while (s[i] && s[i] == c)
			i++;
	}
	else
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}

void	i_end_init(size_t *i, size_t *end)
{
	*i = 0;
	*end = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	char	**arr;
	size_t	end;
	size_t	i;

	if (s == 0)
		return (0);
	arr = (char **)malloc(sizeof(char *) * charset_count((char *)s, c));
	if (arr == 0)
		return (0);
	i_end_init(&i, &end);
	while (s[end])
	{
		start = start_end((char *)s, c, end, 0);
		end = start_end((char *)s, c, start, 1);
		if (end - start != 0)
		{
			arr[i] = (char *)malloc(sizeof(char) * (end - start + 1));
			if (arr[i] == 0)
				return (malloc_error(arr));
			ft_strlcpy(arr[i++], ((char *)&s[start]), end - start + 1);
		}
	}
	arr[i] = 0;
	return (arr);
}
