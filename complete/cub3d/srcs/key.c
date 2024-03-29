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

#include "../include/cub3d.h"

int		key_press(int k, t_info *info)
{
	if (k == KEY_ESC)
		print_error("", info);
	else if (k == KEY_W)
		info->key.w = 1;
	else if (k == KEY_UP)
		info->key.up = 1;
	else if (k == KEY_A)
		info->key.a = 1;
	else if (k == KEY_S)
		info->key.s = 1;
	else if (k == KEY_DOWN)
		info->key.down = 1;
	else if (k == KEY_D)
		info->key.d = 1;
	else if (k == KEY_L)
		info->key.l = 1;
	else if (k == KEY_R)
		info->key.r = 1;
	return (0);
}

int		key_release(int k, t_info *info)
{
	if (k == KEY_ESC)
		print_error("", info);
	else if (k == KEY_W)
		info->key.w = 0;
	else if (k == KEY_UP)
		info->key.up = 0;
	else if (k == KEY_A)
		info->key.a = 0;
	else if (k == KEY_S)
		info->key.s = 0;
	else if (k == KEY_DOWN)
		info->key.down = 0;
	else if (k == KEY_D)
		info->key.d = 0;
	else if (k == KEY_L)
		info->key.l = 0;
	else if (k == KEY_R)
		info->key.r = 0;
	return (0);
}
