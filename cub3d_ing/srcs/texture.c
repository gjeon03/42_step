/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:46:54 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/18 19:48:46 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texture_free(t_info *info, int index)
{
	int i;

	i = 0;
	while (info->texture[i] && i < 5)
		free(info->texture[i++]);
	free(info->texture);
	info->texture = 0;
}

int		load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (img->img == 0)
		return (print_error("ERROR\nThe path name is not correct.\n", info));
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
	return (1);
}

int		load_texture(t_info *info)
{
	int		i;
	int		j;
	t_img	img;

	i = 0;
	while (i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) *
						(T_H * T_W))))
			return (print_error("ERROR\ntexture table allocation\n", info));
		j = 0;
		while (j < T_H * T_W)
			info->texture[i][j++] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		load_image(info, info->texture[i], info->path[i], &img);
		i++;
	}
	return (1);
}
