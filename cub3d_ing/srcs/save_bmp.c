/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:50:56 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/27 18:50:57 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	int_to_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

int		bmp_header(int fd, int h, int w, int padsize)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (w * 3 * h) + (padsize * h);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_char(header + 18, w);
	int_to_char(header + 22, h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, 54) < 0));
}

int		bmp_data(int fd, t_info *info, int padsize)
{
	unsigned char	zero[3];
	int				x;
	int				y;
	int				pixel;

	y = info->config.height - 1;
	ft_bzero(zero, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < info->config.width)
		{
			pixel = *(info->img.data + x + y * info->img.size_l / 4);
			if (write(fd, &pixel, 3) < 0)
				return (0);
			if (padsize > 0 && write(fd, &zero, padsize) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int		take_screenshot(t_info *info)
{
	int padsize;
	int fd;

	main_loop(info);
	padsize = (4 - ((int)info->config.width * 3) % 4) % 4;
	if ((fd = open("save.bmp", O_WRONLY |
	O_CREAT | O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, info->config.height, info->config.width, padsize);
	bmp_data(fd, info, padsize);
	close(fd);
	return (1);
}

/*int	data_to_bitmap(t_info *info, int fd)
{
	int i;

	i = info->config.width * info->config.height - 1;
	while (i >= 0)
	{
		write(fd, &info->img.data[i * info->img.bpp / 8], 4);
		i--;
	}
	return (1);
}

void	mir_verti_pixel(t_info *info, int line_cnt, int *e, int f)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = info->img.data[*e + (line_cnt * info->img.size_l)];
		info->img.data[*e + (line_cnt * info->img.size_l)] =
			info->img.data[f - k + (line_cnt * info->img.size_l - 1)];
		info->img.data[f - k + (line_cnt * info->img.size_l - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

int		mir_verti(t_info *info)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < info->config.height)
	{
		e = 0;
		f = info->img.size_l;
		while (e < f && e != f)
		{
			mir_verti_pixel(info, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
	return (1);
}

int		bitmap_info_header(t_info *info, int fd)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	main_loop(info);
	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &info->config.width, 4);
	write(fd, &info->config.height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &info->img.bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (1);
}*/

void	save_bmp(t_info *info, char *str)
{
	int fd;
	int file_size;
	int first_pix;

	info->save = 1;
	if (ft_strncmp("--save", str, 7) != 0)
		print_error("ERROR\n'--save' is not correct\n", info);
	write(1, "saveing...\n", 11);
	/*if ((fd = open("save.bmp", O_WRONLY |
			O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		print_error("ERROR\nCouldn't create/open .bmp\n", info);
	file_size = 14 + 40 + 4 + (info->config.width * info->config.height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(info, fd);
	mir_verti(info);
	data_to_bitmap(info, fd);
	close(fd);*/
	if (!take_screenshot(info))
		print_error("ERROR\nCouldn't create/open .bmp\n", info);
	write(1, "save.bmp saved!\n", 16);
	cub_close(info);
}
