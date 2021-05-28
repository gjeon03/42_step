/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save	bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:50:56 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 23:34:38 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	bmp_header(int fd, int h, int w, int padsize)
{
	int		filesize;
	t_bmp	bmp;

	filesize = (w * 3 + padsize) * h;
	//filesize = (54 + 4) * w * h;
	bmp.bf_type1 = 'B';
	bmp.bf_type2 = 'M';
	bmp.bf_size = filesize;
	bmp.bf_reserved1 = 0;
	bmp.bf_reserved1 = 0;
	bmp.bf_off_bits = 54;
	bmp.bi_size = 40;
	bmp.bi_width = w;
	bmp.bi_height = h;
	bmp.bi_planes = 1;
	bmp.bi_bit_count = 32;
	bmp.bi_compression = 0;
	bmp.bi_size_image = 0;
	bmp.bi_xpels_per_meter = 0;
	bmp.bi_ypels_per_meter = 0;
	bmp.bi_clr_used = 0;
	bmp.bi_clr_important = 0;
	printf("w=%d\n",w);
	printf("h=%d\n",h);
	write(fd, &bmp, 54);
}

int		bmp_data(int fd, t_info *info, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	/*y = info->config.height - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < (info->img.size_l / 4))
		{
			pixel = *(info->img.data + x + y * (info->img.size_l / 4));
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}*/
	y = info->config.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < (info->img.size_l / 4))
		{
			pixel = *(info->img.data + x + y * info->img.size_l / 4);
			if (write(fd, &pixel, 4) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

void	save_bmp(t_info *info, char *str)
{
	int padsize;
	int fd;

	info->save = 1;
	if (ft_strncmp("--save", str, 7) != 0)
		print_error("ERROR\n'--save' is not correct\n", info);
	write(1, "saveing...\n", 11);
	main_loop(info);
	padsize = (4 - ((int)(info->img.size_l / 4) * 3) % 4) % 4;
	if ((fd = open("save.bmp", O_WRONLY |
			O_CREAT | O_TRUNC | O_APPEND)) < 0)
		print_error("ERROR\nCouldn't create/open .bmp\n", info);
	bmp_header(fd, info->config.height, (info->img.size_l / 4), padsize);
	bmp_data(fd, info, padsize);
	close(fd);
	write(1, "save.bmp saved!\n", 16);
	cub_close(info);
}
