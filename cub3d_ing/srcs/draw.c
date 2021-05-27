/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:58:51 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:58:52 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	image_draw(t_info *info)
{
	int x;
	int	y;

	y = 0;
	while (y < info->config.height)
	{
		x = 0;
		while (x < info->config.width)
		{
			info->img.data[y * info->config.width + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	start_dir(t_info *info)
{
	info->player.movespeed = 0.05;
	info->player.rotspeed = 0.05;
	if (info->config.dir == 'N')
	{
		info->player.dirx = -1.0;
		info->player.diry = 0.0;
		info->player.planex = 0.0;
		info->player.planey = 0.66;
	}
	else if (info->config.dir == 's')
	{
		info->player.dirx = 1.0;
		info->player.diry = 0.0;
		info->player.planex = 0.0;
		info->player.planey = -0.66;
	}
	start_dir2(info);
}

void	start_dir2(t_info *info)
{
	if (info->config.dir == 'W')
	{
		info->player.dirx = 0.0;
		info->player.diry = -1.0;
		info->player.planex = -0.66;
		info->player.planey = 0.0;
	}
	else if (info->config.dir == 'E')
	{
		info->player.dirx = 0.0;
		info->player.diry = 1.0;
		info->player.planex = 0.66;
		info->player.planey = 0.0;
	}
}
