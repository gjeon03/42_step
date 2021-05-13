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

int		config_resolution(char *line,  t_info *info)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (is_space(line[i]) || line[i] == 'R')
		i++;
	while (ft_isdigit(line[i]))
	{
		x = (x * 10) + (line[i] - '0');
		i++;
	}
	while (is_space(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		y = (y * 10) + (line[i] - '0');
		i++;
	}
	if (line[i] != '\0')
		return (-1);
	else
	{
		info->window->width = x;
		info->window->height = y;
	}
	return (1);
}

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

int		config_path(int index, char *line, t_info *info)
{
	int		start;
	int		end;
	char	*path;
	
	start = 0;
	while (is_space(line[start]))
		start++;
	end = ft_strlen(line);
	path = ft_substr(line, start, end - start);
	if (!path || !file_exists(path))
		return (print_error("invalid path"));
	info->path->path[index] = path;
	return (1);
}

int		config_color(char location, char *line, t_info *info)
{
	int				i;
	int				r;
	int				g;
	int				b;
	unsigned int	color;

	i = 0;
	while (is_space(line[i]))
		i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		r = r * 10 + (line[i] - '0');
		i++;
	}
	i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		g = g * 10 + (line[i] - '0');
		i++;
	}
	i++;
	while (line[i] && ft_isdigit(line[i]))
	{
		b = b * 10 + (line[i] - '0');
		i++;
	}
	color = (r * 256 * 256) + (g * 256) + b;
	if (location == 'F')
		info->color.f_color = color;
	else if (location == 'C')
		info->color.c_color = color;
	return (1);
}
