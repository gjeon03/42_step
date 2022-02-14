/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:12:38 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/13 19:02:22 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		is_map_character(char c, t_info *info)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' ||
			c == 'W' || c == 'E')
	{
		if (info->config.color_flag < 2)
			print_error("ERROR\nlack of config information\n", info);
		return (1);
	}
	return (0);
}

int		save_map(char *line, int gnl_return, t_info *info)
{
	static char	*save;
	char		*tmp;
	int			line_len;

	line_len = ft_strlen(line);
	tmp = ft_strjoin(save, line);
	if (save != 0)
		free(save);
	save = tmp;
	if (gnl_return != 0)
	{
		info->map.row++;
		tmp = ft_strjoin(save, "\n");
		free(save);
		save = tmp;
	}
	else
	{
		tmp = ft_strjoin(save, "\n");
		free(save);
		save = tmp;
		set_map(info, save);
		info->map.map_flag = 1;
	}
	return (line_len);
}

int		is_type_identifier(char a, char b, char *line, t_info *info)
{
	if (a == 'S' && is_space(b))
		return (config_path(4, line + 1, info));
	else if ((a == 'F' || a == 'C') && is_space(b))
	{
		info->config.color_flag++;
		return (config_color(a, line + 1, info));
	}
	else if (a == 'N' && b == 'O')
		return (config_path(0, line + 2, info));
	else if (a == 'S' && b == 'O')
		return (config_path(1, line + 2, info));
	else if (a == 'W' && b == 'E')
		return (config_path(2, line + 2, info));
	else if (a == 'E' && b == 'A')
		return (config_path(3, line + 2, info));
	return (0);
}

int		parse_line(char *line, int gnl_return, t_info *info)
{
	int	i;

	i = 0;
	if (gnl_return == 0)
		save_map(line, gnl_return, info);
	else
	{
		while (line[i] != '\0')
		{
			if (is_space(line[i]))
				i++;
			else if (is_type_identifier(line[i], line[i + 1], line + i, info))
				break ;
			else if (is_map_character(line[i], info))
			{
				info->m_end = 1;
				return (save_map(line, gnl_return, info));
			}
			else
				return (-1);
		}
	}
	if (info->map.map_flag == 1)
		return (check_map(info));
	return (1);
}
