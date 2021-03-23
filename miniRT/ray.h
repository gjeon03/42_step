#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "hittable.h"
# include "sphere.h"

t_vec3	origin(t_ray r)
{
	return (r.orig);
}

t_vec3	direction(t_ray r)
{
	return (r.dir);
}

t_vec3	ray_color(t_ray r, t_hittable_list world)
{
	t_vec3	n;
	t_vec3	color;
	double	t;
	t_vec3	a;
	t_vec3	b;
	t_vec3	unit_direction;

	t = hit_sphere(world.sp[0], r);
	if (t > 0.0)
	{
		n = unit_vector(v_sub(at(r, t), world.sp[0].center));
		t_vec3	color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (v_mul_n(color, 0.5));
	}
	t = hit_sphere(world.sp[1], r);
	if (t > 0.0)
	{
		n = unit_vector(v_sub(at(r, t), world.sp[1].center));
		t_vec3	color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (v_mul_n(color, 0.5));
	}
	unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	a = make_vec(1.0);
	b.x = 0.5;
	b.y = 0.7;
	b.z = 1.0;
	return (v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t)));
}

#endif
