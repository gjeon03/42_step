/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:57:41 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:57:42 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		info_malloc(t_info *info)
{
	int	i;

	if (!(info->path = malloc(sizeof(char *) * 5)))
		return (-1);
	if (!(info->texture = malloc(sizeof(int *) * 5)))
	{
		free(info->path);
		return (-1);
	}
	i = 0;
	while (i < 5)
	{
		info->path[i] = 0;
		info->texture[i] = 0;
		i++;
	}
	return (1);
}

void	buf_free(t_info *info)
{
	int	i;

	i = 0;
	if (info->buf)
	{
		while (info->buf[i] && i < info->config.height)
			free(info->buf[i++]);
		free(info->buf);
		info->buf = 0;
	}
	if (info->zbuffer)
		free(info->zbuffer);
}

void	malloc_clear(t_info *info)
{
	if (info->path)
		path_free(info, 5);
	if (info->map.tab)
		map_free(info);
	if (info->texture)
		texture_free(info, 5);
	if (info->sprites)
		lstclear(&info->sprites);
	buf_free(info);
}

int		**buf_malloc(t_info *info)
{
	int	**tmp;
	int	i;
	int	j;

	j = 0;
	if (!(tmp = malloc(sizeof(int*) * info->config.height)))
		return (0);
	i = 0;
	while (i < info->config.height)
	{
		if (!(tmp[i] = malloc(sizeof(int) * info->config.width)))
			return (0);
		ft_bzero(tmp[i], info->config.width);
		i++;
	}
	return (tmp);
}

double	*zbuffer_malloc(t_info *info)
{
	double	*tmp;

	if (!(tmp = malloc(sizeof(double) * info->config.width)))
		return (0);
	ft_bzero(tmp, info->config.width);
	return (tmp);
}
