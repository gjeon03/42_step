/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:44:45 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/22 02:44:48 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	pix_sprites(t_info *info, t_sprite *sprite)
{
	sprite->stripe = sprite->drawStartX;
	while (sprite->stripe < sprite->drawEndX)
	{
		sprite->texX = (int)((256 * (sprite->stripe - (-sprite->spriteWidth
			/ 2 + sprite->spriteScreenX)) * T_WIDTH
			/ sprite->spriteWidth) / 256);
		if (sprite->transformY > 0 && sprite->stripe > 0
			&& sprite->stripe < info->config.width
			&& sprite->transformY < info->zBuffer[sprite->stripe])
		{
			sprite->y = sprite->drawStartY;
			while (sprite->y < sprite->drawEndY)
			{
				sprite->d = (sprite->y - sprite->vMoveScreen) * 256
					- info->config.height * 128 + sprite->spriteHeight * 128;
				sprite->texY = ((sprite->d * T_HEIGHT) / sprite->spriteHeight) / 256;
				sprite->color = info->texture[4][T_WIDTH
					* sprite->texY + sprite->texX];
				if ((sprite->color & 0x00FFFFFF) != 0)
					info->buf[sprite->y][sprite->stripe] = sprite->color;
				sprite->y++;
			}
		}
		sprite->stripe++;
	}
}
