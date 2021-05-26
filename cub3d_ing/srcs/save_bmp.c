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
	O_CREAT, 0777 | O_TRUNC | O_APPEND)) < 0)
		return (0);
	bmp_header(fd, info->config.height, info->config.width, padsize);
	bmp_data(fd, info, padsize);
	close(fd);
	return (1);
}

void	save_bmp(t_info *info, char *str)
{
	if (ft_strncmp("--save", str, 7) != 0)
		print_error("ERROR\n'--save' is not correct\n", info);
	if (!take_screenshot(info))
		print_error("ERROR\nCouldn't create/open .bmp\n", info);
	write(1, "save.bmp saved!\n", 16);
	cub_close(info);
}