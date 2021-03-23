#ifndef VEC_H
# define VEC_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
} t_vec3;

typedef	struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
	int  *data;
	int		bpp;
	int	size_l;
	int	endian;

	t_vec3	color;
	int		int_color;

} t_mlx;

t_vec3	make_v(double n)
{
	t_vec3 v;
	v.x = n;
	v.y = n;
	v.z = n;

	return (v);
}

t_vec3	v_mul_n(t_vec3 v1, double n)
{
	t_vec3	result;

	result.x = v1.x * n;
	result.y = v1.y * n;
	result.z = v1.z * n;
	return (result);
}

t_vec3	v_mul(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

double	dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	v_sub(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec3	v_add(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec3	v_div(t_vec3 v1, double d)
{
	t_vec3	result;

	result.x = v1.x / d;
	result.y = v1.y / d;
	result.z = v1.z / d;
	return (result);
}

t_vec3	origin(t_vec3 orig, t_vec3 dir)
{
	return (orig);
}

t_vec3	direction(t_vec3 orig, t_vec3 dir)
{
	return (dir);
}
/*
t_vec	ray(t_vec orig, t_vec dir)
{
		
}

t_vec	at(t_vec orig, t_vec dir, double t)
{
	return (orig + t * dir);
}


void	write_color(t_mlx *app, t_vec3 c) 
{
	int	ir = 255.999 * c.x;
	int	ig = 255.999 * c.y;
	int	ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->int_color = app->color.x + app->color.y + app->color.z;
}*/

double	length_squared(t_vec3 e)
{
	return (e.x * e.x + e.y * e.y + e.z * e.z);
}

double length(t_vec3 e)
{
	return (sqrt(length_squared(e)));
}

t_vec3	unit_vector(t_vec3 v)
{
	return (v_div(v, length(v)));
}

/*t_vec3	ray_color(t_vec3 orig, t_vec3 dir)
{
	t_vec3 unit_direction = unit_vector(dir);
	double t = 0.5 * (unit_direction.y + 1.0);
	t_vec3 a= make_v(1.0);
	t_vec3 b; b.x = 0.5; b.y = 0.7; b.z = 1.0;
	return v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t));
}*/

#endif
