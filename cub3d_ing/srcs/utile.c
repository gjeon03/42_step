#include "../include/cub3d.h"

int		info_malloc(t_info *info)
{
	//if (!(info->map = malloc(sizeof(t_map))))
	//	return (-1);
	if (!(info->path = malloc(sizeof(char *) * 5)))
		return (-1);
	//if (!(info->config = malloc(sizeof(t_config))))
	//	return (-1);
	if (!(info->texture = malloc(sizeof(int *) * 5)))
		return (-1);
	//if (!(info->key = malloc(sizeof(t_key))))
	//	return (-1);
	//if (!(info->player = malloc(sizeof(t_player))))
	//	return (-1);
	return (1);
}

void	buf_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->config.height)
	{
		free(info->buf[i]);
		i++;
	}
	free(info->buf);
	free(info->zBuffer);
}

void	malloc_clear(t_info *info)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(info->path[i]);
		info->path[i++] = 0;
		free(info->texture[i]);
		info->texture[i++] = 0;
	}
	i = 0;
	while (i < info->map.row)
	{
		free(info->map.tab[i]);
		info->map.tab[i++] = 0;
	}
	free(info->map.tab);
	//free(info->map);
	free(info->path);
	free(info->texture);
	//free(info->config);
	//free(info->key);
	//free(info->player);
	lstclear(&info->sprites);
	buf_free(info);
}

int		**buf_malloc(t_info *info)
{
	int	**tmp;
	int	i;

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