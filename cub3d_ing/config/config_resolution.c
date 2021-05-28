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
	int	fd;
	int	len;

	len = ft_strlen(file_name);
	if (!file_name || len == 0)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (!(file_name[len - 4] == '.' && file_name[len - 3] == 'x' &&
				file_name[len - 2] == 'p' && file_name[len - 1] == 'm'))
		return (-1);
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

int		config_color(char location, char *line, t_info *info)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
		info->rgb.r = (info->rgb.r * 10 + (line[i++] - '0'));
	i++;
	while (line[i] && ft_isdigit(line[i]))
		info->rgb.g = info->rgb.g * 10 + (line[i++] - '0');
	i++;
	while (line[i] && ft_isdigit(line[i]))
		info->rgb.b = info->rgb.b * 10 + (line[i++] - '0');
	info->rgb.color = (info->rgb.r * 256 * 256) + (info->rgb.g * 256)
			+ info->rgb.b;
	if (location == 'F')
		info->config.f_color = info->rgb.color;
	else if (location == 'C')
		info->config.c_color = info->rgb.color;
	return (1);
}
