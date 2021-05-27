/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:55:31 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:55:33 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pix_sprites(t_info *info, t_sprite *sprite)
{
	sprite->stripe = sprite->drawstartx;
	while (sprite->stripe < sprite->drawendx)
	{
		sprite->texx = (int)((256 * (sprite->stripe - (-sprite->s_width
			/ 2 + sprite->spritescreenx)) * T_W
			/ sprite->s_width) / 256);
		if (sprite->transformy > 0 && sprite->stripe > 0
				&& sprite->stripe < info->config.width
				&& sprite->transformy < info->zbuffer[sprite->stripe])
		{
			sprite->y = sprite->drawstarty;
			while (sprite->y < sprite->drawendy)
			{
				sprite->d = (sprite->y - sprite->vmovescreen) * 256
					- info->config.height * 128 + sprite->s_height * 128;
				sprite->texy = ((sprite->d * T_H) / sprite->s_height) / 256;
				sprite->c = info->texture[4][T_W * sprite->texy
						+ sprite->texx];
				if ((sprite->c & 0x00FFFFFF) != 0)
					info->buf[sprite->y][sprite->stripe] = sprite->c;
				sprite->y++;
			}
		}
		sprite->stripe++;
	}
}
