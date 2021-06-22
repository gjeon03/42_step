/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:46:29 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:46:31 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_rotright(t_info *info)
{
	double oldirx;
	double oldplanex;

	if (info->key.r == 1)
	{
		oldirx = info->player.dirx;
		info->player.dirx = info->player.dirx
			* cos(-info->player.rotspeed) - info->player.diry
			* sin(-info->player.rotspeed);
		info->player.diry = oldirx
			* sin(-info->player.rotspeed) + info->player.diry
			* cos(-info->player.rotspeed);
		oldplanex = info->player.planex;
		info->player.planex = info->player.planex
			* cos(-info->player.rotspeed) - info->player.planey
			* sin(-info->player.rotspeed);
		info->player.planey = oldplanex
			* sin(-info->player.rotspeed) + info->player.planey
			* cos(-info->player.rotspeed);
	}
}

void	player_rotleft(t_info *info)
{
	double oldirx;
	double oldplanex;

	if (info->key.l == 1)
	{
		oldirx = info->player.dirx;
		info->player.dirx = info->player.dirx
			* cos(info->player.rotspeed) - info->player.diry
			* sin(info->player.rotspeed);
		info->player.diry = oldirx
			* sin(info->player.rotspeed) + info->player.diry
			* cos(info->player.rotspeed);
		oldplanex = info->player.planex;
		info->player.planex = info->player.planex
			* cos(info->player.rotspeed) - info->player.planey
			* sin(info->player.rotspeed);
		info->player.planey = oldplanex
			* sin(info->player.rotspeed) + info->player.planey
			* cos(info->player.rotspeed);
	}
}
