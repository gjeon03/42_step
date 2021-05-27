/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:37:08 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:37:10 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

int		sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	if (!(sprites = (t_pair*)malloc(sizeof(t_pair) * amount)))
		return (-1);
	i = 0;
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
	return (0);
}

void	sprite_camera(t_info *info, t_sprite *sprite, int s_order)
{
	t_sprites	*sprites;
	double		spritex;
	double		spritey;
	double		invdet;

	sprites = order_find(info->sprites, s_order);
	spritex = sprites->x - info->config.posx;
	spritey = sprites->y - info->config.posy;
	invdet = 1.0 / (info->player.planex * info->player.diry
			- info->player.dirx * info->player.planey);
	sprite->transformx = invdet * (info->player.diry * spritex
			- info->player.dirx * spritey);
	sprite->transformy = invdet * (-info->player.planey * spritex
			+ info->player.planex * spritey);
	sprite->spritescreenx = (int)((info->config.width / 2)
			* (1 + sprite->transformx / sprite->transformy));
	sprite->vmovescreen = (int)(0.0 / sprite->transformy);
}

void	sprite_xy(t_info *info, t_sprite *sprite)
{
	sprite->s_height = (int)fabs(info->config.height / sprite->transformy);
	sprite->drawstarty = -sprite->s_height / 2
			+ info->config.height / 2 + sprite->vmovescreen;
	if (sprite->drawstarty < 0)
		sprite->drawstarty = 0;
	sprite->drawendy = sprite->s_height / 2
			+ info->config.height / 2 + sprite->vmovescreen;
	if (sprite->drawendy >= info->config.height)
		sprite->drawendy = info->config.height - 1;
	sprite->s_width = (int)fabs((info->config.height
			/ sprite->transformy) / 1);
	sprite->drawstartx = -sprite->s_width / 2 + sprite->spritescreenx;
	if (sprite->drawstartx < 0)
		sprite->drawstartx = 0;
	sprite->drawendx = sprite->s_width / 2 + sprite->spritescreenx;
	if (sprite->drawendx >= info->config.width)
		sprite->drawendx = info->config.width - 1;
}

int		draw_sprites(t_info *info)
{
	int			s_order[info->config.sprite_count];
	double		s_dist[info->config.sprite_count];
	int			i;
	t_sprites	*tmp;

	i = 0;
	tmp = info->sprites;
	while (i < info->config.sprite_count)
	{
		s_order[i] = i;
		s_dist[i] = ((info->config.posx - tmp->x) * (info->config.posx - tmp->x)
				+ (info->config.posy - tmp->y) * (info->config.posy - tmp->y));
		tmp = tmp->next;
		i++;
	}
	if (sort_sprites(s_order, s_dist, info->config.sprite_count) == -1)
		return (print_error("ERROR\nsprite malloc allocation\n", info));
	i = 0;
	while (i < info->config.sprite_count)
	{
		sprite_camera(info, &info->sprite, s_order[i++]);
		sprite_xy(info, &info->sprite);
		pix_sprites(info, &info->sprite);
	}
	return (1);
}
