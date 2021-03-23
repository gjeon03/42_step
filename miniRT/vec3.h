#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	t_vec3		color;
	int			int_color;
}				t_mlx;

typedef struct	s_ray
{
	t_vec3		orig;
	t_vec3		dir;
}				t_ray;

t_vec3	make_vec(double n)
{
	t_vec3	result;

	result.x = n;
	result.y = n;
	result.z = n;
	return (result);
}

t_vec3	v_mul_n(t_vec3 v, double n)
{
	t_vec3	result;

	result.x = v.x * n;
	result.y = v.y * n;
	result.z = v.z * n;
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

t_vec3	v_div_n(t_vec3 v1, double d)
{
	t_vec3	result;

	result.x = v1.x / d;
	result.y = v1.y / d;
	result.z = v1.z / d;
	return (result);
}

double	length_squared(t_vec3 e)
{
	return (e.x * e.x + e.y * e.y + e.z * e.z);
}

double	length(t_vec3 e)
{
	return (sqrt(length_squared(e)));
}

t_vec3	unit_vector(t_vec3 v)
{
	return (v_div_n(v, length(v)));
}

t_vec3	cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

t_vec3	at(t_ray r, double t)
{
	return (r.dir);
}

//void	write_color(t_mlx *app, t_vec3 c);
//t_vec3	ray_color(t_vec3 orig, t_vec3 dir);
//int		hit_sphere(t_vec3 center, double radius, t_vec3 origin, t_vec3 direction);

#endif
