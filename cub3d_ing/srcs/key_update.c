#include "../include/cub3d.h"

void	player_movright(t_info *info)
{
	char	ch;

	if (info->key.d == 1)
	{
		ch = info->map.tab[(int)(info->config.posX
				+ info->player.planeX * info->player.moveSpeed)]
				[(int)(info->config.posY)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posX += info->player.planeX
					* info->player.moveSpeed;
		ch = info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY + info->player.planeY
				* info->player.moveSpeed)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posY += info->player.planeY
					* info->player.moveSpeed;
	}
}

void	player_movleft(t_info *info)
{
	char	ch;

	if (info->key.a == 1)
	{
		ch = info->map.tab[(int)(info->config.posX
				- info->player.planeX * info->player.moveSpeed)]
				[(int)(info->config.posY)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posX -= info->player.planeX
					* info->player.moveSpeed;
		ch = info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY - info->player.planeY
				* info->player.moveSpeed)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posY -= info->player.planeY
					* info->player.moveSpeed;
	}
}

void	player_movback(t_info *info)
{
	char	ch;

	if (info->key.s == 1 || info->key.down == 1)
	{
		ch = info->map.tab[(int)(info->config.posX
				- info->player.dirX * info->player.moveSpeed)]
				[(int)(info->config.posY)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posX -= info->player.dirX
					* info->player.moveSpeed;
		ch = info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY
				- info->player.dirY * info->player.moveSpeed)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posY -= info->player.dirY
					* info->player.moveSpeed;
	}
}

void	player_movforward(t_info *info)
{
	char	ch;

	if (info->key.w == 1 || info->key.up == 1)
	{
		ch = info->map.tab[(int)(info->config.posX
				+ info->player.dirX * info->player.moveSpeed)]
				[(int)(info->config.posY)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posX += info->player.dirX
					* info->player.moveSpeed;
		ch = info->map.tab[(int)(info->config.posX)]
				[(int)(info->config.posY
				+ info->player.dirY * info->player.moveSpeed)];
		if((!(ch - '0')) || ft_strchr(DIR_CH, ch))
			info->config.posY += info->player.dirY
					* info->player.moveSpeed;
	}
}

void	key_update(t_info *info)
{
	player_movforward(info);
	player_movback(info);
	player_movleft(info);
	player_movright(info);
	player_rotright(info);
	player_rotleft(info);
}