#include "mlx.h"
#include "vec.h"

int	main(void)
{
	//image
	const float	aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = image_width / aspect_ratio;

	//start mlx
	t_mlx		*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, 800, 600, "test1");
	app->img = mlx_new_image(app->mlx, image_width, image_height);
	app->data = (int *)mlx_get_data_addr(app->mlx, &app->bpp, &app->size_l, &app->endian);

	//camera
	double		viewport_height = 2.0;
	double		viewport_width = aspect_ratio * viewport_height;
	double		focal_length = 1.0;

	t_vec3		origin = {0, 0, 0};
	t_vec3		horizontal = {viewport_width, 0, 0};
	t_vec3		vertical = {0, viewport_height, 0};
	t_vec3		any = {0, 0, focal_length};
	t_vec3		lower_left_corner = v_sub(origin, v_add(v_add(v_div(horizontal, 2), v_div(vertical, 2)), any));

	//render
	int			j = 0;
	int			i;
	while (j < image_height)
	{
		i = 0;
		while (i < image_width)
		{
			double	u = (double)i / (image_width - 1);
			double	v = (image_height - (double)j - 1) / (image_height - 1);

			t_vec3	a = origin;
			t_vec3	b = v_add(lower_left_corner, v_add(v_mul_n(horizontal, u), v_mul_n(v_sub(vertical, origin), v)));
			t_vec3	pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx, app->win, i, j, app->int_color);
			app->data[j * image_width + i] = app->int_color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
	mlx_loop(app->mlx);
}
