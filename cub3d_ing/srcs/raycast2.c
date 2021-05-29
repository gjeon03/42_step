/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:51:10 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:51:11 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	celling_floot(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->config.width)
	{
		y = 0;
		while (y < info->config.height)
		{
			info->buf[y][x] = info->config.f_color;
			info->buf[info->config.height - y - 1][x] = info->config.c_color;
			y++;
		}
		x++;
	}
}

int		get_text_id(t_info *info)
{
	if (info->ray.side == 0 && info->ray.raydirx > 0)
		info->ray.texx = T_W - info->ray.texx - 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->ray.texx = T_W - info->ray.texx - 1;
	if (info->ray.side == 0)
	{
		if (info->ray.raydirx > 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (info->ray.raydiry > 0)
			return (3);
		else
			return (2);
	}
}

void	print_texture(t_info *info, int x)
{
	int		y;
	int		id;
	int		color;

	if (info->ray.side == 0)
		info->ray.wallx = info->config.posy + (info->ray.perpwalldist
				* info->ray.raydiry);
	else
		info->ray.wallx = info->config.posx + (info->ray.perpwalldist
				* info->ray.raydirx);
	info->ray.wallx -= floor(info->ray.wallx);
	info->ray.texx = (int)(info->ray.wallx * (double)T_W);
	id = get_text_id(info);
	info->ray.step = 1.0 * T_H / info->ray.lineheight;
	info->ray.texpos = (info->ray.drawstart - info->config.height
			/ 2 + info->ray.lineheight / 2) * info->ray.step;
	y = info->ray.drawstart;
	while (y < info->ray.drawend)
	{
		info->ray.texy = (int)info->ray.texpos & (T_H - 1);
		info->ray.texpos += info->ray.step;
		color = info->texture[id][T_H * info->ray.texy + info->ray.texx];
		info->buf[y][x] = color;
		y++;
	}
}
