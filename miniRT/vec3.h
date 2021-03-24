#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_color
{
	t_vec3		color;
	int			int_color;
}				t_color;

t_vec3	vec3_(double e1, double e2, double e3)
{
	t_vec3	v;

	v.x = e1;
	v.y = e2;
	v.z = e3;
	return (v);
}

void	update(t_vec3 *v, double e1, double e2, double e3)
{
	v->x = e1;
	v->y = e2;
	v->z = e3;
}

t_vec3	negate(t_vec3 v)
{
	return (vec3_(-v.x, -v.y, -v.z));
}

void	multiply_(t_vec3 *v, double t)
{
	v->x *= t;
	v->y *= t;
	v->z *= t;
}

t_vec3	multiply(t_vec3 v, double t)
{
	return (vec3_(v.x * t, v.y * t, v.z * t));
}

void	divide_(t_vec3 *v, double t)
{
	multiply_(v, 1 / t);
}

t_vec3	divide(t_vec3 v, double t)
{
	return (multiply(v, 1 / t));
}

double	dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	length(t_vec3 v)
{
	return (sqrt(dot(v, v)));
}

void	add_(t_vec3 *u, t_vec3 v)
{
	update(u, u->x + v.x, u->y + v.y, u->z + v.z);
}

t_vec3	add(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.x + v.x, u.y + v.y, u.z + v.z));
}

void	subtract_(t_vec3 *u, t_vec3 v)
{
	update(u, u->x - v.x, u->y - v.y, u->z - v.z);
}

t_vec3	subtract(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	return (vec3_(u.y * v.z - u.z * v.y,
				u.z * v.x - u.x * v.z,
				u.x * v.y - u.y * v.x));
}

t_vec3	unit_vector(t_vec3 v)
{
	return (divide(v, length(v)));
}

t_vec3	(*color_)(double e1, double e2, double e3) = vec3_;
t_vec3	(*point3_)(double e1, double e2, double e3) = vec3_;

typedef t_vec3	point3;
typedef t_vec3	color;

#endif
