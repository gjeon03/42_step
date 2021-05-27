/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:45:06 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:45:07 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	player_movright(t_info *info)
{
	char	ch;

	if (info->key.d == 1)
	{
		ch = info->map.tab[(int)(info->config.posx
				+ info->player.planex * info->player.movespeed)]
				[(int)(info->config.posy)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posx += info->player.planex
					* info->player.movespeed;
		ch = info->map.tab[(int)(info->config.posx)]
				[(int)(info->config.posy + info->player.planey
				* info->player.movespeed)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posy += info->player.planey
					* info->player.movespeed;
	}
}

void	player_movleft(t_info *info)
{
	char	ch;

	if (info->key.a == 1)
	{
		ch = info->map.tab[(int)(info->config.posx
				- info->player.planex * info->player.movespeed)]
				[(int)(info->config.posy)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posx -= info->player.planex
					* info->player.movespeed;
		ch = info->map.tab[(int)(info->config.posx)]
				[(int)(info->config.posy - info->player.planey
				* info->player.movespeed)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posy -= info->player.planey
					* info->player.movespeed;
	}
}

void	player_movback(t_info *info)
{
	char	ch;

	if (info->key.s == 1 || info->key.down == 1)
	{
		ch = info->map.tab[(int)(info->config.posx
				- info->player.dirx * info->player.movespeed)]
				[(int)(info->config.posy)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posx -= info->player.dirx
					* info->player.movespeed;
		ch = info->map.tab[(int)(info->config.posx)]
				[(int)(info->config.posy
				- info->player.diry * info->player.movespeed)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posy -= info->player.diry
					* info->player.movespeed;
	}
}

void	player_movforward(t_info *info)
{
	char	ch;

	if (info->key.w == 1 || info->key.up == 1)
	{
		ch = info->map.tab[(int)(info->config.posx
				+ info->player.dirx * info->player.movespeed)]
				[(int)(info->config.posy)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posx += info->player.dirx
					* info->player.movespeed;
		ch = info->map.tab[(int)(info->config.posx)]
				[(int)(info->config.posy
				+ info->player.diry * info->player.movespeed)];
		if ((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posy += info->player.diry
					* info->player.movespeed;
	}
}

void	key_update(t_info *info)
{
	player_movforward(info);
	player_movback(info);
	player_movleft(info);
	player_movright(info);
	player_rotright(info);
	player_rotleft(info);
}
