#ifndef HITTABLE_H
# define HITTABLE_H

# include "ray.h"

typedef struct	s_hit_record
{
	point3		p;
	t_vec3		normal;
	double		t;
	int			front_face;
}				t_hit_record;

void	set_face_normal(t_hit_record *rec, t_ray r, t_vec3 outward_normal)
{
	rec->front_face = dot(r.dir, outward_normal) < 0;
	rec->normal = rec->front_face ? outward_normal : negate(outward_normal);
}

typedef enum	s_geometry
{
	_sphere
}				t_geometry;

typedef struct	s_hittable
{
	t_geometry	mesh;
	void		*pointer;
}				t_hittable;

#endif
