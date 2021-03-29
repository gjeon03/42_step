#ifndef SPHERE_H
# define SPHERE_H

# include "vec3.h"
# include "hittable.h"

typedef struct	s_sphere
{
	point3		center;
	double		radius;
}				t_sphere;

t_hittable	sphere_(point3 center, double radius)
{
	t_hittable	h;
	t_sphere	*s;

	h.mesh = _sphere;
	h.pointer = malloc(sizeof(t_sphere));
	if ((s = h.pointer))
	{
		s->center = center;
		s->radius = radius;
	}
	return (h);
}

int			hit_sphere(t_sphere *s, t_ray r, double t_min, double t_max, t_hit_record *rec)
{
	t_vec3	oc = subtract(r.orig, s->center);
	double	a = length_squared(r.dir);
	double	half_b = dot(oc, r.dir);
	double	c = length_squared(oc) - s->radius * s->radius;

	double	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	
	double	sqrtd = sqrt(discriminant);
	double	root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return (FALSE);
	}

	rec->t = root;
	rec->p = at(r, rec->t);
	t_vec3	outward_normal = divide(subtract(rec->p, s->center), s->radius);
	set_face_normal(rec, r, outward_normal);

	return (TRUE);
}

#endif
