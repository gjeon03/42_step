#ifndef RAY2_H
# define RAY2_H

t_vec3	origin(t_ray r)
{
	return (r.orig);
}

t_vec3	direction(t_ray r)
{
	return (r.dir);
}

t_vec3	at(t_ray r, double t)
{
	return (v_add(r.orig, v_mul_n(r.dir, t)));
}

typedef struct	s_hittable_list
{
	t_sphere	sp[2];
}		t_hittable_list;

t_vec3	ray_color(t_ray r, t_hittable_list world)
{
	double t = hit_sphere(world.sp[0], r);
	if (t > 0.0)
	{
		t_vec3 n = unit_vector(v_sub(at(r, t), world.sp[0].center));
		t_vec3 color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;

		return (v_mul_n(color, 0.5));

	}

	t = hit_sphere(world.sp[1], r);
	if (t > 0.0)
	{
		t_vec3 n = unit_vector(v_sub(at(r, t), world.sp[1].center));
		t_vec3 color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;

		return (v_mul_n(color, 0.5));

	}
	t_vec3 unit_direction = unit_vector(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	t_vec3 a= make_vec(1.0);
	t_vec3 b; b.x = 0.5; b.y = 0.7; b.z = 1.0;

	return (v_add(v_mul_n(a, 1.0 - t), v_mul_n(b, t)));
}

#endif
