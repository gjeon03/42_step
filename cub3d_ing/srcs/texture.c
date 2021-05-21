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

void		get_textures(t_info *info)
{
	char	*tex_paths[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		tex_paths[i] = info->path[i];
		i++;
	}
	i = 0;
	while (i < 5)
	{
		info->tex[i].img = mlx_xpm_file_to_image(info->mlx, tex_paths[i],
								&info->tex[i].img_width,
								&info->tex[i].img_height);
		if (!info->tex[i].img)
			error_exit("No textures");
		info->tex[i].img_addr = mlx_get_data_addr(info->tex[i].img,
								&info->tex[i].bpp,
								&info->tex[i].line_lenght,
								&info->tex[i].endian);
		i++;
	}
	return ;
}
/*
void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
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
}

int		load_texture(t_info *info, t_img *img)
{
	t_img	img;
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) *
						(texHeight * texWidth))))
			return (-1);
		j = 0;
		while (j < texHeight * texWidth)
			info->texture[i][j++] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		load_image(info, info->texture[i], info->path[i], img);
		i++;
	}
	return (1);
}
*/