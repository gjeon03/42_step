/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:28:22 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/08 12:18:43 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		*screen_check(t_info *info)
{
	int max_x;
	int max_y;

	mlx_get_screen_size(info->mlx, &max_x, &max_y);
	if (max_x < info->config.width)
		info->config.width = max_x;
	if (max_y < info->config.height)
		info->config.height = max_y;
	return (mlx_new_window(info->mlx, info->config.width,
			info->config.height, WIN_TITLE));
}

int		check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (!file_name || len < 5)
		return (-1);
	if (file_name[len] != 'd' || file_name[len - 1] != 'u' ||
			file_name[len - 2] != 'c' || file_name[len - 3] != '.')
		return (-1);
	return (1);
}

void	verify_params(t_info *info)
{
	if (!(info->config.width))
		print_error("ERROR\nno resolution width input\n", info);
	if (!(info->config.height))
		print_error("ERROR\nno resolution height inputT\n", info);
	if (!(info->config.f_color))
		print_error("ERROR\nno floor color input\n", info);
	if (!(info->config.c_color))
		print_error("ERROR\nno ceiling color input\n", info);
	if (!info->path[0] || !info->path[1] || !info->path[2] ||
		!info->path[3] || !info->path[4])
		print_error("ERROR\nmissing texture path\n", info);
}

int		treat_description(char *file_name, t_info *info)
{
	int		fd;
	int		gnl_return;
	char	*line;
	int		error_ch;

	error_ch = 1;
	if (!check_file_name(file_name))
		return (print_error("ERROR\nFile format is not correct\n", info));
	if (!(fd = open(file_name, O_RDONLY)))
		return (print_error("ERROR\nCouldn't open map file\n", info));
	while ((gnl_return = get_next_line(fd, &line)) >= 0)
	{
		error_ch = parse_line(line, gnl_return, info);
		free(line);
		if (gnl_return == 0)
			break ;
	}
	close(fd);
	if ((load_texture(info) == -1))
		return (print_error("ERROR\ntexture memory allocation\n", info));
	return (error_ch);
}
