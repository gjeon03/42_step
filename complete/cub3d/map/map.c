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
	return (mlx_new_window(info->mlx, info->config.width,
			info->config.height, WIN_TITLE));
}

int		check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name) - 1;
	if (file_name == 0 || len < 5)
		return (0);
	if (file_name[len] != 'b' || file_name[len - 1] != 'u' ||
			file_name[len - 2] != 'c' || file_name[len - 3] != '.')
		return (0);
	return (1);
}

void	verify_params(t_info *info)
{
	if (!(info->config.width))
		print_error("ERROR\nno resolution width input\n", info);
	if (!(info->config.height))
		print_error("ERROR\nno resolution height inputT\n", info);
	if (!info->path[0] || !info->path[1] || !info->path[2] ||
		!info->path[3] || !info->path[4])
		print_error("ERROR\nmissing texture path\n", info);
	if (info->m_end != 1)
		print_error("ERROR\nNo map information.\n", info);
	if (info->config.dir_flag != 1)
		print_error("ERROR\nThe location information is incorrect.\n", info);
}

int		treat_description(char *file_name, t_info *info)
{
	int		fd;
	int		gnl_return;
	char	*line;
	int		error_ch;

	error_ch = 1;
	if (check_file_name(file_name) == 0)
		return (print_error("ERROR\nFile format is not correct\n", info));
	if ((fd = open(file_name, O_RDONLY)) <= 0)
		return (print_error("ERROR\nCouldn't open map file\n", info));
	while ((gnl_return = get_next_line(fd, &line)) >= 0)
	{
		error_ch = parse_line(line, gnl_return, info);
		free(line);
		if (gnl_return == 0 || error_ch == -1)
			break ;
	}
	if (gnl_return < 0)
		return (print_error("ERROR\ngnl fail\n", info));
	close(fd);
	verify_params(info);
	if ((load_texture(info) == -1))
		return (print_error("ERROR\ntexture memory allocation\n", info));
	return (error_ch);
}
