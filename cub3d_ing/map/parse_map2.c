/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:17:03 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/07 00:37:41 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		set_map(t_info *info, char *save)
{
	int		i;
	int		j;
	int		start;

	i = -1;
	info->map.row = 1;
	while (save[i])
		if (save[i] == '\n')
			info->map.row++;
	if (!(info->map.tab = malloc(sizeof(char) * info->map.row)))
		return (-1);
	i = 0;
	j = 0;
	while (save[j] != '\n')
		j++;
	info->map.col = j;
	j = 0;
	while (i < info->map.row)
	{
		start = j;
		if (!(info->map.tab[i] = malloc(sizeof(char) * (info->map.col + 1))))
			return (-1);
		ft_strlcpy(info->map.tab[i], save + start, j + info->map.col + 1);
		i++;
		j += (info->map.col + 1);
	}
	return (0);
}

int		check_space_around_position(t_info *info, int i, int j)
{
	if (i <= 0 || i >= info->map.row || j <= 0 || j >= info->map.col)
		return (1);
	else if (info->map.tab[i][j + 1] == ' ' || info->map.tab[i][j + 1] == '\0' ||
			info->map.tab[i][j - 1] == ' ')
		return (1);
	else if ((int)ft_strlen(info->map.tab[i - 1]) <= j ||
			info->map.tab[i - 1][j] == ' ' || info->map.tab[i - 1][j] == '\0')
		return (1);
	else if ((int)ft_strlen(info->map.tab[i + 1]) <= j ||
			info->map.tab[i + 1][j] == ' ' || info->map.tab[i + 1][j] == '\0')
		return (1);
	return (0);
}

void	check_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map.tab[i])
	{
		j = 0;
		while (info->map.tab[i][j])
		{
			if (info->map.tab[i][j] != '1' &&
					info->map.tab[i][j] != ' ' &&
					check_space_around_position(info, i, j))
				print_error("map error");
			j++;
		}
		i++;
	}
}
