/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:17:03 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/08 12:09:23 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_free(t_info *info)
{
	int i;

	i = 0;
	while (i < info->map.row)
		free(info->map.tab[i++]);
	free(info->map.tab);
	info->map.tab = 0;
}

int		set_map(t_info *info, char *save)
{
	int		i;
	int		j;
	int		col;
	int		start;

	i = -1;
	if (!(info->map.tab = malloc(sizeof(char*) * (info->map.row + 1))))
		return (print_error("ERROR\ntable memory allocation\n", info));
	i = 0;
	start = 0;
	col = 0;
	j = 0;
	while (i < info->map.row)
	{
		col = 0;
		while (save[col] != '\n')
			col++;
		if (!(info->map.tab[i] = malloc(sizeof(char) * (col + 1))))
			return (print_error("ERROR\ntable memory allocation\n", info));
		ft_strlcpy(info->map.tab[i], save, col + 1);
		i++;
		save += col + 1;
	}
	return (0);
}

int		check_space_around_position(t_info *info, int i, int j)
{
	if (i <= 0 || i >= info->map.row || j <= 0)
		return (1);
	else if (info->map.tab[i][j + 1] == ' ' ||
			info->map.tab[i][j + 1] == '\0' ||
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

int		map_error(t_info *info, int i, int j)
{
	if ((info->map.tab[i][j] != '1' &&
			info->map.tab[i][j] != ' ' &&
			check_space_around_position(info, i, j)) ||
			info->config.dir_flag > 1)
		return (-1);
	return (1);
}

int		check_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->map.row)
	{
		j = 0;
		while (info->map.tab[i][j])
		{
			if (ft_strchr(DIR_CH, info->map.tab[i][j]))
			{
				info->config.posx = (double)i + 0.5;
				info->config.posy = (double)j + 0.5;
				info->config.dir = info->map.tab[i][j];
				info->config.dir_flag++;
			}
			if (info->map.tab[i][j] == '2')
				sprites_lts(i, j, info);
			if ((map_error(info, i, j)) == -1)
				return (print_error("ERROR\nThe map is not correct.\n", info));
			j++;
		}
		i++;
	}
	return (1);
}
