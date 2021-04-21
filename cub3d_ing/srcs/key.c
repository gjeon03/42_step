/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:03:20 by gjeon             #+#    #+#             */
/*   Updated: 2021/04/21 20:29:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP);
		info->key->w = 1;
	else if (key == KEY_A);
		info->key->a = 1;
	else if (key == KEY_S || key == KEY_DOWN);
		info->key->s = 1;
	else if (key == KEY_D);
		info->key->d = 1;
	else if (key == KEY_L);
		info->key->l = 1;
	else if (key == KEY_R);
		info->key->r = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W || key == KEY_UP)
		info->key->w = 0;
	else if (key == KEY_A)
		info->key->a = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		info->key->s = 0;
	else if (key == KEY_D)
		info->key->d = 0;
	else if (key == KEY_L)
		info->key->l = 0;
	else if (key == KEY_R)
		info->key->r = 0;
	return (0);
}
