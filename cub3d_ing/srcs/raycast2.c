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
	if (info->ray.side == 0 && info->ray.rayDirX > 0)
		info->ray.texX = T_WIDTH - info->ray.texX - 1;
	if (info->ray.side == 1 && info->ray.rayDirY < 0)
		info->ray.texX = T_WIDTH - info->ray.texX - 1;
	if (info->ray.side == 0)
	{
		if (info->ray.rayDirX > 0)
			return (2);
		else
			return (1);
	}
	else
	{
		if (info->ray.rayDirY > 0)
			return (0);
		else
			return (3);
	}
}

void	print_texture(t_info *info, int x)
{
	int		y;
	int		id;
	int		color;

	if (info->ray.side == 0)
		info->ray.wallx = info->config.posY + (info->ray.perpWallDist * info->ray.rayDirY);
	else
		info->ray.wallx = info->config.posX + (info->ray.perpWallDist * info->ray.rayDirX);
	info->ray.wallx -= floor(info->ray.wallx);
	info->ray.texX = (int)(info->ray.wallx * (double)T_WIDTH);
	id = get_text_id(info);
	info->ray.step = 1.0 * T_HEIGHT / info->ray.lineHeight;
	info->ray.texPos = (info->ray.drawStart - info->config.height
			/ 2 + info->ray.lineHeight / 2) * info->ray.step;
	y = info->ray.drawStart;
	while (y < info->ray.drawEnd)
	{
		info->ray.texY = (int)info->ray.texPos & (T_HEIGHT - 1);
		info->ray.texPos += info->ray.step;
		color = info->texture[id][T_HEIGHT * info->ray.texY + info->ray.texX];
		info->buf[y][x] = color;
		y++;
	}
}