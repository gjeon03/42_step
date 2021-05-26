#include "../include/cub3d.h"

int		info_malloc(t_info *info)
{
	if (!(info->path = malloc(sizeof(char *) * 5)))
		return (-1);
	if (!(info->texture = malloc(sizeof(int *) * 5)))
	{
		free(info->path);
		return (-1);
	}
	return (1);
}

void	buf_free(t_info *info)
{
	int	i;

	i = 0;
	while (info->buf[i])
		free(info->buf[i++]);
	if (info->buf)
	{
		free(info->buf);
		info->buf = 0;
	}
	if (info->zBuffer)
		free(info->zBuffer);
}

void	malloc_clear(t_info *info)
{
	int	i;

	path_free(info, 5);
	i = 0;
	while (info->texture[i])
		free(info->texture[i++]);
	i = 0;
	while (info->map.tab[i])
		free(info->map.tab[i++]);
	if (info->map.tab)
	{
		free(info->map.tab);
		info->map.tab = 0;
	}
	if (info->texture)
	{
		free(info->texture);
		info->texture = 0;
	}
	if (info->sprites)
		lstclear(&info->sprites);
	buf_free(info);
}

int		**buf_malloc(t_info *info)
{
	int	**tmp;
	int	i;
	int	j;

	j = 0;
	if (!(tmp = malloc(sizeof(int*) * info->config.height)))
		return (0);
	i = 0;
	while (i < info->config.height)
	{
		if (!(tmp[i] = malloc(sizeof(int) * info->config.width)))
			return (0);
		ft_bzero(tmp[i], info->config.width);
		i++;
	}
	return (tmp);
}

double	*zBuffer_malloc(t_info *info)
{
	double	*tmp;

	if (!(tmp = malloc(sizeof(double) * info->config.width)))
		return (0);
	ft_bzero(tmp, info->config.width);
	return (tmp);
}