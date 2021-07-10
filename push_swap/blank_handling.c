/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blank_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:18:42 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:22:07 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strchar_count(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * (n + 1));
	if (tmp == 0)
		return (0);
	while (str[i] && i < n)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

void	tmp_free(char **tmp, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(tmp[i++]);
	free(tmp);
}

void	blank_handling(t_info *info, char *str, int count)
{
	char	**tmp;
	int		i;
	int		j;
	int		start;

	tmp = malloc(sizeof(char *) * count);
	if (tmp == 0)
		error_msg("Error\n");
	i = 0;
	j = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			tmp[j++] = ft_strndup(str + start, i - start);
			start = i + 1;
		}
		i++;
	}
	tmp[j] = ft_strndup(str + start, i - start);
	set_stack(info, tmp, count);
	tmp_free(tmp, count);
}
