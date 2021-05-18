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
	int		error_ch;

	error_ch = 1;
	if (!check_file_name(file_name))
		return (-1);
	if (!(fd = open(file_name, O_RDONLY)))
		return (-1);
	while ((gnl_return = get_next_line(fd, &line)) >= 0)
	{
		error_ch = parse_line(line, gnl_return, info);
		free(line);
		if (gnl_return == 0)
			break ;
	}
	close(fd);
	return (error_ch);
}
