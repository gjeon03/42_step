#include "include/cub3d.h"

void	info_set(t_info *info)
{
	info->map.row = 1;
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
	info->key.up = 0;
	info->key.down = 0;
	info->config.width = 0;
	info->config.height = 0;
	info->config.f_color = 0;
	info->config.c_color = 0;
	info->rgb.r = 0;
	info->rgb.g = 0;
	info->rgb.b = 0;
}

int		main_loop(t_info *info)
{
	raycast(info);
	draw_sprites(info);
	imageDraw(info);
	key_update(info);
	return (0);
}

int		first_set(t_info *info, char *argv)
{
	if (info_malloc(info) == -1)
		return (print_error("ERROR\ninfo memory allocation\n", info));
	info_set(info);
	if (treat_description(argv, info) == -1)
		return (print_error("ERROR\ntreat_description\n", info));
	if ((info->buf = buf_malloc(info)) == 0
		|| (info->zBuffer = zBuffer_malloc(info)) == 0)
		return (print_error("ERROR\nbuf memorry allocation\n", info));
	return (1);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc > 3)
		print_error("ERROR\ntoo many arguments\n", &info);
	if (argc < 2)
		print_error("ERROR\nnot enough arguments\n", &info);
	if (!(info.mlx = mlx_init()))
		print_error("ERROR\nmlx fuction failed\n", &info);
	first_set(&info, argv[1]);

	/*if (info_malloc(&info) == -1)
		return (print_error("ERROR\ninfo memory allocation\n", &info));
	info_set(&info);
	if (treat_description(argv[1], &info) == -1)
		return (print_error("ERROR\ntreat_description\n", &info));
	if ((info.buf = buf_malloc(&info)) == 0
		|| (info.zBuffer = zBuffer_malloc(&info)) == 0)
		return (print_error("ERROR\nbuf memorry allocation\n", &info));
*/
	start_dir(&info);
	info.img.img = mlx_new_image(info.mlx, info.config.width,
			info.config.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img,
			&info.img.bpp, &info.img.size_l, &info.img.endian);
	if (argc == 3)
		save_bmp(&info, argv[2]);
	if (!(info.win = screen_check(&info)))
		print_error("ERROR\nmlx fuction failed\n", &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);
	mlx_hook(info.win, 3, 0, &key_release, &info);
	mlx_hook(info.win, 17, 1L<<5, cub_close, "bye");
	mlx_loop(info.mlx);
	cub_close(&info);
}
