/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:18:23 by gjeon             #+#    #+#             */
/*   Updated: 2021/03/09 18:25:24 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;
//벡터 사칙연산 함수
t_vec3	*ft_vec3_add(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_sub(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_multi(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_div(t_vec3 *target, t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_multi_float(t_vec3 *target, float t, t_vec3 *v);
t_vec3	*ft_vec3_div_float(t_vec3 *target, float t, t_vec3 *v);
//벡터 내적, 외적 연산 함수
float	ft_vec3_dot(t_vec3 *u, t_vec3 *v);
t_vec3	*ft_vec3_cross(t_vec3 *target, t_vec3 *u, t_vec3 *v);
//기타 함수
float	ft_vec3_len(t_vec3 *target);
float	ft_vec3_len_sqr(t_vec3 *target);
t_vec3	*ft_vec3_unit_vec(t_vec3 *target, t_vec3 *v);
t_vec3	*ft_vec3_set_xyz(t_vec3 *target, float x, float y, float z);

#endif
