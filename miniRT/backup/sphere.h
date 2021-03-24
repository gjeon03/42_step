#ifndef SPHERE_H
# define SPHERE_H

typedef struct 	s_sphere
{
	t_vec3		center;
	double		radius;
}				t_sphere;

double	hit_sphere(t_sphere s, t_ray r)
{
	t_vec3 oc = v_sub(r.orig, s.center);
	double a = length_squared(r.dir);
	double half_b = dot(oc, r.dir);
	double c = length_squared(oc) - s.radius * s.radius;
	double discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((- half_b - sqrt(discriminant)) / a);
}

#endif
