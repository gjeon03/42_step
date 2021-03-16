/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:39:03 by gjeon             #+#    #+#             */
/*   Updated: 2021/03/16 21:19:22 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;

	t_vec		color;
	int			int_color;
}				t_mlx;

t_vec	make_vec(float n)
{
	t_vec	result;

	result.x = n;
	result.y = n;
	result.z = n;
	return (result);
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

t_vec	v_div_n(t_vec v1, float n)
{
	t_vec	result;

	result.x = v1.x / n;
	result.y = v1.y / n;
	result.z = v1.z / n;
	return (result);
}

float	dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float	length_squared(t_vec e)
{
	return (e.x * e.x + e.y * e.y + e.z * e.z);
}

float	length(t_vec e)
{
	return (sqrt(length_squared(e)));
}

t_vec	unit_vector(t_vec v)
{
	return (v_div_n(v, length(v)));
}

t_vec	cross(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

void	write_color(t_mlx *app, t_vec c)
{
	int		ir = 255.999 * c.x;
	int		ig = 255.999 * c.y;
	int		ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->int_color = app->color.x + app->color.y + app->color.z;
}

typedef struct	s_ray
{
	t_vec		orig;
	t_vec		dir;
}				t_ray;

typedef struct	s_sphere
{
	t_vec		center;
	double		radius;
}				t_sphere;

double	hit_sphere(t_sphere s, t_ray r)
{
	t_vec	oc = v_sub(r.orig, s.center);
	float	a = length_squared(r.dir);
	float	half_b = dot(oc, r.dir);
	float	c = length_squared(oc) - s.radius * s.radius;
	float	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

typedef struct	s_hit_record
{
	t_vec		p;
	t_vec		normal;
	double		t;
	int			front_face;
}				t_hit_record;

t_vec	origin(t_ray r)
{
	return (r.orig);
}

t_vec	direction(t_ray r)
{
	return (r.dir);
}

t_vec	at(t_ray r, double t)
{
	return (v_add(r.orig, v_mul_n(r.dir, t)));
}

int		hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_sphere s);

typedef struct	s_hittable_list
{
	t_sphere	sp[2];
}				t_hittable_list;

int		ittable_list_it(t_ray r, double t_min, double t_max, t_hit_record rec, t_hittable_list world);

t_vec	ray_color(t_ray r, t_hittable_list world)
{
	float	t = hit_sphere(world.sp[0], r);
	if (t > 0.0)
	{
		t_vec	n = unit_vector(v_sub(at(r, t), world.sp[0].center));
		t_vec	color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;

		return (v_mul_n(color, 0.5));
	}
	t = hit_sphere(world.sp[1], r);
	if (t > 0.0)
	{
		t_vec	n = unit_vector(v_sub(at(r, t), world.sp[1].center));
		t_vec	color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;

		return (v_mul_n(color, 0.5));
	}
	t_vec	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec	a = make_vec(1.0);
	t_vec	b; b.x = 0.5; b.y = 0.7; b.z = 1.0;

	return (v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t)));
}

void	set_face_normal(t_vec direction, t_vec normal, t_vec outward_normal, int front_face)
{
	front_face = dot(direction, outward_normal) < 0 ? 1 : 0;
	normal = front_face ? outward_normal : v_mul_n(outward_normal, -1);
}

int		hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_sphere s)
{
	t_vec	oc = v_sub(r.orig, s.center);
	float	a = length_squared(r.dir);
	float	half_b = dot(oc, r.dir);
	float	c = length_squared(oc) - s.radius * s.radius;
	float	discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		float	root = sqrt(discriminant);
		float	temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r, rec.t);
			t_vec outward_normal = v_div_n(v_sub(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r, rec.t);
			t_vec	outward_normal = v_div_n(v_sub(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);
		}
	}
	return (0);
}

int		hittable_list_hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_hittable_list world)
{
	t_hit_record	temp_rec;
	int				hit_anything = 0;
	float			closest_so_far = t_max;

	int				i = 0;

	while (i < 2)
	{
		if (hit(r, t_min, closest_so_far, temp_rec, world.sp[i]))
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
		i++;
	}
	return (hit_anything);
}

#define PI 3.1415926535897932385

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

#include <stdio.h>

int		main(void)
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

	// World
	t_hittable_list	world;

	world.sp[0].center.x = 0;
	world.sp[0].center.y = 0;
	world.sp[0].center.z = -1;
	world.sp[0].radius = 0.5;

	world.sp[1].center.x = 0;
	world.sp[1].center.y = -100.5;
	world.sp[1].center.z = -1;
	world.sp[1].radius = 100;

	// Camera
	float	viewport_height = 2.0;
	float	viewport_width = aspect_ratio * viewport_height;
	float	focal_length = 1.0;

	t_vec	origin = {0,0,0};
	t_vec	horizontal = {viewport_width, 0, 0};
	t_vec	vertical = {0, viewport_height, 0}; t_vec any = {0, 0, focal_length};
	t_vec	lower_left_corner = v_sub(origin, v_add(v_add(v_div_n(horizontal, 2), v_div_n(vertical, 2)), any));

	// Render

	int j = 0;
	while (j < image_height)
	{
		int i = 0;
		while (i < image_width)
		{

			float u = (double)i / (image_width - 1);
			float v = (image_height - (double)j - 1)/ (image_height - 1);

			t_ray r;
			r.orig = origin;
			r.dir = v_add(lower_left_corner, v_add(v_mul_n(horizontal, u), v_mul_n(v_sub(vertical, origin), v)));
			t_vec pixel_color = ray_color(r, world);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx, app->win, i, j, app->int_color);
//			app->data[j * image_width + i] = app->int_color;

			++i;
		}
		++j;
	}
//	mlx_put_image_to_window (app->mlx_ptr, app->win_ptr, app->img_ptr, 0, 0);
	mlx_loop(app->mlx);	
}
