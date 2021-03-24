#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct	s_ray
{
	point3		orig;
	t_vec3		dir;
}				t_ray;

t_ray	ray_(point3 origin, t_vec3 direction)
{
	t_ray	r;

	r.orig = origin;
	r.dir = direction;
	return (r);
}

point3	at(t_ray r, double t)
{
	return (add(r.orig, multiply(r.dir, t)));
}

#endif
