#include "mlx.h"
#include "vec3.h"
#include "color.h"
#include "ray1.h"
#include "sphere.h"
#include "ray2.h"
#include "hittable.h"

int	main(void)
{
	// Image
	const float	aspect_ratio = 16.0 / 9.0;
	const int	image_width = 448;
	const int	image_height = image_width / aspect_ratio;

	// Start mlx
	t_mlx	*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, 800, 600, "raytracer");
	app->img = mlx_new_image(app->mlx, image_width, image_height);
	app->data = (int *)mlx_get_data_addr(app->img, &app->bpp, &app->size_l, &app->endian);

	//world
	t_hittable_list world;

	world.sp[0].center.x = 0;
	world.sp[0].center.y = 0;
	world.sp[0].center.z = -1;
	world.sp[0].radius = 0.5;

	world.sp[1].center.x = 0;
	world.sp[1].center.y = -100.5;
	world.sp[1].center.z = -1;
	world.sp[1].radius = 100;
	// Camera
	double	viewport_height = 2.0;
	double	viewport_width = aspect_ratio * viewport_height;
	double	focal_length = 1.0;

	t_vec3	origin = {0, 0, 0};
	t_vec3	horizontal = {viewport_width, 0, 0};
	t_vec3	vertical = {0, viewport_height, 0};
	t_vec3	any = {0, 0, focal_length};
	t_vec3	lower_left_corner = v_sub(origin, v_add(v_add(v_div_n(horizontal, 2), v_div_n(vertical, 2)), any));

	// Render

	int j = 0;
	while (j < image_height)
	{
		int i = 0;
		while (i < image_width)
		{	
			double u = (double)i / (image_width - 1);
			double v = (image_height - (double)j - 1) / (image_height - 1);
			
			t_ray	r;
			r.orig = origin;
			r.dir = v_add(lower_left_corner, v_add(v_mul_n(horizontal, u), v_mul_n(v_sub(vertical, origin), v)));
			t_vec3	pixel_color = ray_color(r, world);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx, app->win, i, j, app->int_color);	
			app->data[j * image_width + i] = app->int_color;	
			i++;
		}
		j++;
	}
	mlx_put_image_to_window (app->mlx, app->win, app->img, 0, 0);
	mlx_loop(app->mlx);
}
