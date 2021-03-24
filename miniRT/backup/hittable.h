#ifndef HITTABLE_H
# define HITTABLE_H

typedef struct s_hit_record
{
	t_vec3	p;
	t_vec3	normal;
	double	t;
	int	front_face;
}		t_hit_record;

void	set_face_normal(t_vec3 direction, t_vec3 normal, t_vec3 outward_normal, int front_face)
{
	front_face = dot(direction, outward_normal) < 0 ? 1 : 0;
	normal = front_face ? outward_normal : v_mul_n(outward_normal, -1);
}


int	hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_sphere s)
{
	t_vec3 oc = v_sub(r.orig, s.center);
	double a = length_squared(r.dir);
	double half_b = dot(oc, r.dir);
	double c = length_squared(oc) - s.radius * s.radius;
	double discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r, rec.t);
			t_vec3 outward_normal  = v_div_n(v_sub(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = at(r, rec.t);
			t_vec3 outward_normal = v_div_n(v_sub(rec.p, s.center), s.radius);
			set_face_normal(r.dir, rec.normal, outward_normal, rec.front_face);
			return (1);
		}
	}
	return (0);
}

int	hittable_list_hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_hittable_list world)
{
	t_hit_record	temp_rec;
	int	hit_anything = 0;
	double	closest_so_far = t_max;

	int	i = 0;

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

#endif
