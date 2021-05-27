/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:46:37 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:46:39 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	wallcalculation(t_info *info)
{
	info->ray.lineheight = (int)(info->config.height / info->ray.perpwalldist);
	info->ray.drawstart = -info->ray.lineheight / 2 + info->config.height / 2;
	if (info->ray.drawstart < 0)
		info->ray.drawstart = 0;
	info->ray.drawend = info->ray.lineheight / 2 + info->config.height / 2;
	if (info->ray.drawend >= info->config.height)
		info->ray.drawend = info->config.height - 1;
}

void	dda_algorithm(t_info *info)
{
	info->ray.hit = 0;
	while (info->ray.hit == 0)
	{
		if (info->ray.sidedistx < info->ray.sidedisty)
		{
			info->ray.sidedistx += info->ray.deltadistx;
			info->ray.mapx += info->ray.stepx;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sidedisty += info->ray.deltadisty;
			info->ray.mapy += info->ray.stepy;
			info->ray.side = 1;
		}
		if (info->map.tab[info->ray.mapx][info->ray.mapy] == '1'
				&& info->map.tab[info->ray.mapx][info->ray.mapy] != '2')
			info->ray.hit = 1;
	}
	if (info->ray.side == 0)
		info->ray.perpwalldist = (info->ray.mapx - info->config.posx
				+ (1 - info->ray.stepx) / 2) / info->ray.raydirx;
	else
		info->ray.perpwalldist = (info->ray.mapy - info->config.posy
				+ (1 - info->ray.stepy) / 2) / info->ray.raydiry;
}

void	dist_calculation(t_info *info)
{
	if (info->ray.raydirx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidedistx = (info->config.posx - info->ray.mapx)
				* info->ray.deltadistx;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidedistx = (info->ray.mapx + 1.0 - info->config.posx)
				* info->ray.deltadistx;
	}
	if (info->ray.raydiry < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidedisty = (info->config.posy - info->ray.mapy)
				* info->ray.deltadisty;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidedisty = (info->ray.mapy + 1.0 - info->config.posy)
				* info->ray.deltadisty;
	}
}

void	ray_init(t_info *info, int x)
{
	info->ray.camerax = (2 * x / (double)(info->config.width)) - 1;
	info->ray.raydirx = info->player.dirx + info->player.planex
			* info->ray.camerax;
	info->ray.raydiry = info->player.diry + info->player.planey
			* info->ray.camerax;
	info->ray.mapx = (int)info->config.posx;
	info->ray.mapy = (int)info->config.posy;
	info->ray.deltadistx = fabs(1 / info->ray.raydirx);
	info->ray.deltadisty = fabs(1 / info->ray.raydiry);
}

int		raycast(t_info *info)
{
	int	x;
	int y;

	celling_floot(info);
	x = 0;
	while (x < info->config.width)
	{
		ray_init(info, x);
		dist_calculation(info);
		dda_algorithm(info);
		wallcalculation(info);
		print_texture(info, x);
		info->zbuffer[x] = info->ray.perpwalldist;
		x++;
	}
	return (0);
}
