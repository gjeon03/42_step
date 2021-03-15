/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:25:38 by gjeon             #+#    #+#             */
/*   Updated: 2021/03/09 18:41:42 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	*ft_vec3_add(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->x + v->x;
	target->y = u->y + v->y;
	target->z = u->z + v->z;
	return (target);
}

t_vec3	*ft_vec3_sub(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->x - v->x;
	target->y = u->y - v->y;
	target->z = u->z - v->z;
	return (target);
}

t_vec3	*ft_vec3_multi(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->x * v->x;
	target->y = u->y * v->y;
	target->z = u->z * v->z;
	return (target);
}

t_vec3	*ft_vec3_div(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->x / v->x;
	target->y = u->y / v->y;
	target->z = u->z / v->z;
	return (target);
}

t_vec3	*ft_vec3_multi_float(t_vec3 *target, float t, t_vec3 *v)
{
	target->x = u->x * t;
	target->y = u->y * t;
	target->z = u->z * t;
	return (target);
}

t_vec3	*ft_vec3_float(t_vec3 *target, float t, t_vec3 *v)
{
	return (ft_vec3_multi_float(target, (1 / t), v));
}

float	ft_vec3_dot(t_vec3 *u, t_vec3 *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vec3	*ft_vec3_cross(t_vec3 *target, t_vec3 *u, t_vec3 *v)
{
	target->x = u->y * v->z - u->z * v->y;
	target->y = u->z * v->x - u->x * v->z;
	target->z = u->x * v->y - u->y * v->x;
	return (target);
}

float	ft_vec3_len(t_vec3 *target)
{
	return (sqrt(ft_vec3_len_sqr(target)));
}

float	ft_vec3_len_sqr(t_vec3 *target)
{
	float	result;

	result = pow(target->x, 2.0) + pow(target->y, 2.0) + pow(target->z, 2.0);
	return (result);
}

t_vec3	*ft_vec3_unit_vec(t_vec3 *target, t_vec3 *v)
{
	return (ft_vec3_div_float(target, ft_vec3_len(v)), v);
}

t_vec3	*ft_vec3_set_xyz(t_vec3 *target, float x, float y, float z)
{
	target->x = x;
	target->y = y;
	target->z = z;
	return (target);
}