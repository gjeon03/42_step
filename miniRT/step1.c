#include "mlx.h"
#include "vec3.h"
#include "ray.h"
#include "color.h"

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

int	close(int keycode, t_mlx *app)
{
	if (keycode == 53)
		mlx_destroy_window(app->mlx, app->win);
	return (0);
}

color	ray_color(t_ray r)
{
	t_vec3	unit_direction;
	double	t;

	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (add(multiply(color_(1.0, 1.0, 1.0), 1.0 - t),
				multiply(color_(0.5, 0.7, 1.0), t)));
}

int	main(void)
{
	const float	aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = image_width / aspect_ratio;

	t_mlx		app;
	int			i;
	int			j;
	t_color		rgb;

	app.mlx = mlx_init();
	app.win = mlx_new_window(app.mlx, 800, 600, "step2");
	app.img = mlx_new_image(app.mlx, image_width, image_height);
	app.data = (int *)mlx_get_data_addr(app.img, &app.bpp, &app.size_l, &app.endian);

	//camera
	double		viewport_height = 2.0;
	double		viewport_width = aspect_ratio * viewport_height;
	double		focal_length = 1.0;

	point3		origin = point3_(0, 0, 0);
	t_vec3		horizontal = vec3_(viewport_width, 0, 0);
	t_vec3		vertical = vec3_(0, viewport_height, 0);
	t_vec3		lower_left_corner = subtract(&origin, divide(horizontal, 2));
	subtract_(&lower_left_corner, divide(vertical, 2));
	subtract_(&lower_left_corner, vec3_(0, 0, focal_length));

	j = 0;
	while (j < image_height)
	{
		i = 0;
		while (i < image_width)
		{
			double	u = (double)i / (image_width - 1);
			double	v = (image_height - (double)j - 1) / (image_height - 1);
			
			t_vec3	direction = add(lower_left_corner, multiply(horizontal, u));
			add_(&direction, multiply(vertical, v));
			subtract_(&direction, origin);

			t_ray	r = ray_(origin, direction);
			color	pixel_color = ray_color(r);
			write_color(&rgb, pixel_color);
			mlx_pixel_put(app.mlx, app.win, i, j, rgb.int_color);
			app.data[j * image_width + i] = rgb.int_color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx, app.win, app.img, 0, 0);
	mlx_hook(app.win, 2, 1L<<0, close, &app);
	mlx_loop(app.mlx);
}
