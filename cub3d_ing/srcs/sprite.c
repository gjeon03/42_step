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

int		sortSprites(int *order, double *dist, int amount)
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
	double		spriteX;
	double		spriteY;
	double		invDet;

	sprites = order_find(info->sprites, s_order);
	spriteX = sprites->x - info->config.posX;
	spriteY = sprites->y - info->config.posY;
	invDet = 1.0 / (info->player.planeX * info->player.dirY
			- info->player.dirX * info->player.planeY);
	sprite->transformX = invDet * (info->player.dirY * spriteX
			- info->player.dirX * spriteY);
	sprite->transformY = invDet * (-info->player.planeY * spriteX
			+ info->player.planeX * spriteY);
	sprite->spriteScreenX = (int)((info->config.width / 2)
			* (1 + sprite->transformX / sprite->transformY));
	sprite->vMoveScreen = (int)(0.0 / sprite->transformY);
}

void	sprite_xy(t_info *info, t_sprite *sprite)
{
	sprite->spriteHeight = (int)fabs(info->config.height / sprite->transformY);
	sprite->drawStartY = -sprite->spriteHeight / 2
			+ info->config.height / 2 + sprite->vMoveScreen;
	if (sprite->drawStartY < 0)
		sprite->drawStartY = 0;
	sprite->drawEndY = sprite->spriteHeight / 2
			+ info->config.height / 2 + sprite->vMoveScreen;
	if (sprite->drawEndY >= info->config.height)
		sprite->drawEndY = info->config.height - 1;
	sprite->spriteWidth = (int)fabs((info->config.height / sprite->transformY) / 1);
	sprite->drawStartX = -sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawStartX < 0)
		sprite->drawStartX = 0;
	sprite->drawEndX = sprite->spriteWidth / 2 + sprite->spriteScreenX;
	if (sprite->drawEndX >= info->config.width)
		sprite->drawEndX = info->config.width - 1;
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
		s_dist[i] = ((info->config.posX - tmp->x) * (info->config.posX - tmp->x)
				+ (info->config.posY - tmp->y) * (info->config.posY - tmp->y));
		tmp = tmp->next;
		i++;
	}
	if (sortSprites(s_order, s_dist, info->config.sprite_count) == -1)
		return (cub_close("sprite_malloc error\n"));
	i = 0;
	while (i < info->config.sprite_count)
	{
		sprite_camera(info, &info->sprite, s_order[i]);
		sprite_xy(info, &info->sprite);
		pix_sprites(info, &info->sprite);
		i++;
	}
	return (1);
}