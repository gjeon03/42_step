#include "mlx.h"
#include <stdlib.h>

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_mlx;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	int			ir;
	int			ig;
	int			ib;
	int			arr[3];
	int			color;
}				t_color;

int	close(int keycode, t_mlx *app)
{
	if (keycode == 53)
		mlx_destroy_window(app->mlx, app->win);
	return (0);
}

int	main(void)
{
	const int	image_width = 256;
	const int	image_height = 256;
	t_mlx		app;
	int			i;
	int			j;
	t_color		rgb;

	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, 700, 400, "step1");
	app.img = mlx_new_image(app.mlx, image_width, image_height);
	app.data = (int *)mlx_get_data_addr(app.img, &app.bpp, &app.size_l, &app.endian);

	j = 0;
	while (j < image_height)
	{
		i = 0;
		while (i < image_width)
		{
			rgb.r = (double)i / (image_width - 1);
			rgb.g = (image_height - (double)j - 1) / (image_height - 1);
			rgb.b = 0.25;

			rgb.ir = 255.999 * rgb.r;
			rgb.ig = 255.999 * rgb.g;
			rgb.ib = 255.999 * rgb.b;

			rgb.arr[0] = rgb.ir * 256 * 256;
			rgb.arr[1] = rgb.ig * 256;
			rgb.arr[2] = rgb.ib;

			rgb.color = rgb.arr[0] + rgb.arr[1] + rgb.arr[2];
			app.data[j * 256 + i] = mlx_get_color_value(app.mlx, rgb.color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);
	mlx_hook(app.win, 2, 1L<<0, close, &app);
	mlx_loop(app.mlx);
}
