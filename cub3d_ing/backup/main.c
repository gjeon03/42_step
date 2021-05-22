/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:02:51 by gjeon             #+#    #+#             */
/*   Updated: 2021/04/21 20:03:12 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_info *info)
{
	info->window->mlx = mlx_init();
	info->window->win = mlx_new_window(info->window->mlx,
			info->window->width, info->window->height, "cub3d");
	info->window->img.img = mlx_new_image(info->window->mlx,
			info->window->width, info->window->height);
	info->window->img.data = (int *)mlx_get_data_addr(info->window->img.img,
			&info->window->img.bpp, &window->img.size_l, &window->img.endian);
	mlx_loop_hook(info->window->mlx, &main_loop, &info);
	mlx_hook(info->window->win, 2, 0, &key_press, &info);
	mlx_hook(info->window->win, 3, 0, &key_release, &info);
	mlx_loop(info->window->mlx);
}

int		main(int argc, char **argv)
{
	t_info	info;
	init_window(&info);
	return (0);
}
