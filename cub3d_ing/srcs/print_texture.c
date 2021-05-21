#include "../include/cub3d.h"

int		get_text_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->rayDirX > 0)
			return (2);
		else
			return (1);
	}
	else
	{
		if (ray->rayDirY > 0)
			return (0);
		else
			return (3);
	}
}

void	print_texture(t_info *info, t_ray *ray, int x, t_img *img)
{
	int		i;
	int		id;
	int		texY;
	int		texX;
	double	wallx;

	id = get_text_id(ray);
	if (ray->side == 0)
		wallx = info->window->posY + (ray->perpWallDist * ray->rayDirY);
	else
		wallx = info->window->posX + (ray->perpWallDist * ray->rayDirX);
	wallx -= floor(wallx);
	texX = (int)(wallx * T_WIDTH);
	i = ray->drawStart;
	while (i <= ray->drawEnd)
	{
		texY = abs((((i * 256 - info->window->height * 128 + ray->lineheight * 128)
					* 64) / ray->lineheight) / 256);
		ft_memcpy(mlx->img_addr + 4 * width * i + x * 4,
		&mlx->tex[id].data[tex_y % mlx->tex[id].img_height *
								mlx->tex[id].size_l + tex_x %
								mlx->tex[id].img_width *
								mlx->tex[id].bpp / 8], sizeof(int));
		i++;
	}
}