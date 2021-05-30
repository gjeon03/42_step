/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:26:03 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/07 00:43:17 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		file_exists(char *file_name)
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen(file_name);
	if (!file_name || len == 0)
		return (0);
	while (file_name[len - 1 - i] != 'm' && i <= len)
		i++;
	if (file_name[len - 4 - i] != '.' && file_name[len - 3 - i] != 'x' &&
				file_name[len - 2 - i] != 'p' && file_name[len - 1 - i] != 'm')
		return (0);
	return (1);
}

void	path_free(t_info *info)
{
	int i;

	i = 0;
	while (info->path[i] && i < 5)
		free(info->path[i++]);
	free(info->path);
	info->path = 0;
}

int		config_path(int index, char *line, t_info *info)
{
	int		start;
	int		end;
	char	*path;
	int		i;

	start = 0;
	while (is_space(line[start]))
		start++;
	end = ft_strlen(line);
	if (!(path = ft_substr(line, start, end - start)))
		return (print_error("ERROR\ninvalid path\n", info));
	if (!(file_exists(path)))
		return (print_error("ERROR\ninvalid path\n", info));
	i = 0;
	while (end - i >= 0)
	{
		if (path[end - i] == 'm')
			path[end - i + 1] = '\0';
		i++;
	}
	info->path[index] = path;
	return (1);
}

int		color_rgb(char *line, int *rgb, int i, t_info *info)
{
	int	num;
	int	flag;

	num = i;
	flag = 0;
	if (ft_isdigit(line[num]) != 0)
	{
		while (line[num] && ft_isdigit(line[num]))
		{
			*rgb = (*rgb * 10 + (line[num++] - '0'));
			flag++;
		}
	}
	else
		print_error("ERROR\nThe color values are incorrect.\n", info);
	num++;
	if (*rgb < 0 || *rgb > 255 || flag > 3)
		print_error("ERROR\nThe color values are incorrect.\n", info);
	return (num);
}

int		config_color(char location, char *line, t_info *info)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	i = color_rgb(line, &info->rgb.r, i, info);
	i = color_rgb(line, &info->rgb.g, i, info);
	i = color_rgb(line, &info->rgb.b, i, info);
	while (line[i - 1])
	{
		if (is_space(line[i - 1]))
			i++;
		else
			print_error("ERROR\nThe color values are incorrect.\n", info);
	}
	info->rgb.color = (info->rgb.r * 256 * 256) + (info->rgb.g * 256)
			+ info->rgb.b;
	if (location == 'F')
		info->config.f_color = info->rgb.color;
	else if (location == 'C')
		info->config.c_color = info->rgb.color;
	info->rgb.r = 0;
	info->rgb.g = 0;
	info->rgb.b = 0;
	return (1);
}
