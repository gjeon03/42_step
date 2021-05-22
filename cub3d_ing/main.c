#include "include/cub3d.h"

void	info_set(t_info *info)
{
	info->map.row = 1;
	//info->map->col = 0;
	info->map.map_flag = 0;
	info->config.dir_flag = 0;
	info->config.sprite_count = 0;
	info->sprites = 0;
	info->key.w = 0;
	info->key.s = 0;
	info->key.a = 0;
	info->key.d = 0;
	info->key.l = 0;
	info->key.r = 0;
}

int		main_loop(t_info *info)
{
	//t_ray		ray;
	//ray.mapX = (int)info->config.posX;
	//ray.mapY = (int)info->config.posY;
	//info->img.img = mlx_new_image(info->mlx, info->config.width, info->config.height);
	//info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	//start_dir(info);
	raycast(info);
	draw_sprites(info);
	imageDraw(info);
	key_update(info);
	//mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	//mlx_destroy_image(info->mlx, info->img.img);
	return (0);
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		i;
	int		error;

	if (info_malloc(&info) == -1)
		return (cub_close("memory error\n"));
	info_set(&info);
	error = treat_description(argv[1], &info);
	i = 0;
	if (error == -1)
		return (cub_close("treat_description error\n"));
	info.mlx = mlx_init();
	if ((load_texture(&info) == -1))
		return (cub_close("texture error\n"));
	if ((info.buf = buf_malloc(&info)) == 0
		|| (info.zBuffer = zBuffer_malloc(&info)) == 0)
		return (cub_close("memorry error\n"));
	start_dir(&info);
	info.win = mlx_new_window(info.mlx, info.config.width, info.config.height, WIN_TITLE);
	info.img.img = mlx_new_image(info.mlx, info.config.width, info.config.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 3, 0, &key_release, &info);
	mlx_hook(info.win, 17, 1L<<5, cub_close, "bye");
	mlx_loop(info.mlx);
	malloc_clear(&info);
	return (0);
}
