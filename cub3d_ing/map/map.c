/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:28:22 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/03 05:30:57 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int		treat_description(char *file_name, t_info *info)
{
	int		fd;
	int		gnl_return;
	char	*line;

	if (!check_file_name(file_name))
		return (-1);
	if (!(fd = open(file_name, O_RDONLY)))
		return (-1);
	while ((gnl_return = get_next_line(fd, &line)) >= 0)
	{
		parse_line(line, info, gnl_return);
		free(line);
	}
	close(fd);
	return (1);
}
