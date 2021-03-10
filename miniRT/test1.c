#include "mlx/mlx.h"
#define ESC 53
#include <stdio.h>

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
}

int	window_set(int keycode, t_vars *vars)
{
	if (keycode == 18)
		vars->win = mlx_new_window(vars->mlx, 1920, 1080, "keycode1");
	else if (keycode == 19)
		vars->win = mlx_new_window(vars->mlx, 600, 600, "keycode1");
}

int	color_map(t_vars *vars, int w, int h)
{
	int		x;
	int		y;
	double	color;

	x = -1;
	while (x++ < w)
	{
		y = -1;
		while (y++ < h)
		{
			//color = (x * 255) / w + ((((w - x) * 255) / w) << 16) + (((y * 255) / h) << 8);
			mlx_pixel_put(vars->mlx, vars->win, x, y, color);
		}
	}
}

int	main(void)
{
	t_vars	vars;
	int		x;
	int		y;

	x = 1920;
	y = 1080;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, x, y, "miniRT");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	color_map(&vars, x, y);
	mlx_loop(vars.mlx);
}
