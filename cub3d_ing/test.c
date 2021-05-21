#include "./include/cub3d.h"

void	malloc_clear(t_info *info)
{
	int	i;

	free(info->window);
	i = 0;
	while (i < 5)
	{
		free(info->path[i]);
		info->path[i++] = 0;
		free(info->texture[i]);
		info->texture[i++] = 0;
	}
	i = 0;
	while (i < info->map->row)
	{
		free(info->map->tab[i]);
		info->map->tab[i++] = 0;
	}
	free(info->map->tab);
	free(info->map);
	free(info->path);
	free(info->texture);
	free(info->key);
}

int		info_malloc(t_info *info)
{
	if (!(info->map = malloc(sizeof(t_map))))
		return (-1);
	if (!(info->window = malloc(sizeof(t_window))))
		return (-1);
	if (!(info->path = malloc(sizeof(char *) * 5)))
		return (-1);
	if (!(info->color = malloc(sizeof(t_color))))
		return (-1);
	if (!(info->texture = malloc(sizeof(int *) * 5)))
		return (-1);
	if (!(info->key = malloc(sizeof(t_key))))
		return (-1);
	return (1);
}

t_info	info_set(t_info *info)
{
	info->map->row = 0;
	info->map->map_flag = 0;
	info->window->dirY = 0.0;
	info->window->planeX = 0.0;
	info->window->planeY = 0.66;
	info->window->moveSpeed = 0.05;
	info->window->rotSpeed = 0.05;
	info->window->dir_flag = 0;
	info->window->sprite_count = 0;
	return (*info);
}

int		main_loop(t_info *info)
{
	t_ray	ray;

	info->img.img = mlx_new_image(info->mlx, info->window->width, info->window->height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	ray.mapX = (int)info->window->posX;
	ray.mapY = (int)info->window->posY;
	//move_player(info, &ray);
	key_update(info);
	raycast(info, &ray, &info->img);
	draw_sprites(info, &ray, &info->img);
	//imageDraw(info, &ray);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	mlx_destroy_image(info->mlx, info->img.img);
	return (0);
}

int		main(void)
{
	t_info	info;
	int		i;
	int		error;

	if (info_malloc(&info) == -1)
		return (cub_close("memorry error\n"));
	info = info_set(&info);
	error = treat_description("map.cub", &info);
	i = 0;
	if (error == -1)
		return (cub_close(""));
	info.mlx = mlx_init();
	//if ((load_texture(&info, &info.img) == -1)
	//	print_error("texture error");
	get_textures(info);
	info.win = mlx_new_window(info.mlx, info.window->width, info.window->height, WIN_TITLE);
	//info.img.img = mlx_new_image(info.mlx, info.mlx->width, info.mlx->height);
	//info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 3, 0, &key_release, &info);
	mlx_hook(info.win, 17, 1L<<5, cub_close, "bye");
	mlx_loop(info.mlx);
	malloc_clear(&info);
	return (0);
}
