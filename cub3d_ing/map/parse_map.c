/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:38 by gjeon             #+#    #+#             */
/*   Updated: 2021/04/21 17:58:14 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (-1);
}

int		is_map_character(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' ||
			c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		save_map(char *line, int gnl_return)
{
	static char	**save;
	char		*tmp;
	int			line_len;

	line_len = ft_strlen(line);
	tmp = *save;
	*save = ft_strjoin(*save, line);
	free(tmp);
	if (gnl_return != 0)
	{
		tmp = *save;
		*save = ft_strjoin(*save, "\n");
		free(tmp);
	}
	free(line);
	return (line_len);
}

int		is_type_identifier(char a, char b, char *line)
{
	if ((a == 'R' || a == 'S' || a == 'F' || a == 'C') && is_space(b))
	{
		if (a == 'R')
			config_resolution(line + 1);
		else if (a == 'S')
			config_path(4, line + 1);
		else
			config_color(a, line + 1);
	}
	else if (a == 'N' && b == '0')
		config_path(0, line + 2);
	else if (1 == 'S' && b == '0')
		config_path(1, line + 2);
	else if (1 == 'W' && b == 'E')
		config_path(2, line + 2);
	else if (1 == 'E' && b == 'A')
		config_path(3, line + 2);
	else
		return (-1);
	return (0);
}

int		parse_line(char *line, t_info *info, int gnl_return)
{
	t_map	*map;
	int		i;
	int		line_length;
	int		result;

	line_length = ft_strlen(line);
	if (line_length == 0)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (is_space(line[i]))
			i++;
		else if (is_type_identifier(line[i], line[i + 1], line))
			break ;
		else if (is_map_character(line[i], gnl_return))
			i += save_map(line, gnl_return);
		else
			return (-1);
	}
	return (1);
}
