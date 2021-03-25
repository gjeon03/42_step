#include "mlx.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
} t_vec;

typedef	struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	int  *data;
	int		bpp;
	int	size_l;
	int	endian;

	t_vec	color;
	int		int_color;

} t_mlx;

t_vec	make_v(float n)
{
	t_vec v;
	v.x = n;
	v.y = n;
	v.z = n;

	return (v);
}

t_vec	v_mul_n(t_vec v1, float n)
{
	t_vec	result;

	result.x = v1.x * n;
	result.y = v1.y * n;
	result.z = v1.z * n;
	return (result);
}

t_vec	v_mul(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

float	dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	v_sub(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec	v_add(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec	v_div(t_vec v1, float d)
{
	t_vec	result;

	result.x = v1.x / d;
	result.y = v1.y / d;
	result.z = v1.z / d;
	return (result);
}

t_vec	origin(t_vec orig, t_vec dir)
{
	return (orig);
}

t_vec	direction(t_vec orig, t_vec dir)
{
	return (dir);
}

void	write_color(t_mlx *app, t_vec c)
{
	int	ir = 255.999 * c.x;
	int	ig = 255.999 * c.y;
	int	ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->int_color = app->color.x + app->color.y + app->color.z;
}

float	length_squared(t_vec e)
{
	return (e.x * e.x + e.y * e.y + e.z * e.z);
}

float length(t_vec e)
{
	return (sqrt(length_squared(e)));
}

t_vec	unit_vector(t_vec v)
{
	return (v_div(v, length(v)));
}

t_vec	at(t_vec orig, t_vec dir, double t)
{
	return (v_add(orig, v_mul_n(dir, t)));
}

double	hit_sphere(t_vec center, double radius, t_vec origin, t_vec direction)
{
	t_vec oc = v_sub(origin, center);
	float a = dot(direction, direction);
	float b = 2.0 * dot(oc, direction);
	float c = dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_vec	ray_color(t_vec orig, t_vec dir)
{
	t_vec sphere = {0, 0, -1};
	float t = hit_sphere(sphere, 0.5, orig, dir);
	if (t > 0.0)
	{
		t_vec N = unit_vector(v_sub(at(orig, dir, t), sphere));
		t_vec color;
		color.x = N.x + 1;
		color.y = N.y + 1;
		color.z = N.z + 1;

		return (v_mul_n(color, 0.5));

	}
//	t_vec sphere_color = {1, 0, 0};
//	if (hit_sphere(sphere, 0.5, orig, dir))
//		return (sphere_color);
	t_vec unit_direction = unit_vector(dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec a= make_v(1.0);
	t_vec b; b.x = 0.5; b.y = 0.7; b.z = 1.0;
	return (v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t)));
}

#include <stdio.h>

int	main()
{
	// Image
	const float	aspect_ratio = 16.0 / 9.0;
	const int	image_width = 400;
	const int	image_height = image_width / aspect_ratio;

	// Start mlx
	t_mlx	*app;
	if (!(app = (t_mlx*)malloc(sizeof(t_mlx))))
		return (-1);
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, 800, 600, "raytracer");
	app->img_ptr = mlx_new_image(app->mlx_ptr, image_width, image_height);
	app->data = (int *)mlx_get_data_addr(app->img_ptr, &app->bpp, &app->size_l, &app->endian);


	// Camera
	float	viewport_height = 2.0;
	float	viewport_width = aspect_ratio * viewport_height;
	float	focal_length = 1.0;

	t_vec	origin = {0,0,0};
	t_vec	horizontal = {viewport_width, 0, 0};
	t_vec	vertical = {0, viewport_height, 0}; t_vec any = {0, 0, focal_length};
	t_vec	lower_left_corner = v_sub(origin, v_add(v_add(v_div(horizontal, 2), v_div(vertical, 2)), any));

	// Render

	int jj = 0;
	int j = image_height - 1;
	while (j >= 0 && jj < image_height)
	{
		int i = 0;
		while (i < image_width)
		{

			float u = (double)i / (image_width - 1);
			float v = (double)j / (image_height - 1);

			t_vec a = origin;
			t_vec b = v_add(lower_left_corner, v_add(v_mul_n(horizontal, u), v_mul_n(v_sub(vertical, origin), v)));
			t_vec pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx_ptr, app->win_ptr, i, jj, app->int_color);
			app->data[jj * 400 + i] = app->int_color;

			++i;
		}
		--j;
		++jj; //예제의 점 찍히는 순서를 똑같이 하려고 jj를 따로 만들었음..
	}
//	mlx_put_image_to_window (app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
	mlx_loop(app->mlx_ptr);
}
