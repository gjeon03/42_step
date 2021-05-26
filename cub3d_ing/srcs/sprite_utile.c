#include "../include/cub3d.h"

void		lstclear(t_sprites **lst)
{
	t_sprites	*temp;

	if (lst == 0)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = 0;
}

void		lstadd_back(t_sprites **lst, t_sprites *new)
{
	t_sprites	*tmp;
	int			i = 0;

	if (lst == 0 || new == 0)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_sprites  *sprite_ltsnew(int x, int y)
{
	t_sprites	*new;

	if (!(new = malloc(sizeof(t_sprites))))
		return (0);
	new->x = (double)x + 0.5;
	new->y = (double)y + 0.5;
	new->next = 0;
	return (new);
}

void		sprites_lts(int x, int y, t_info *info)
{
	t_sprites	*tmp;
	
	tmp = sprite_ltsnew(x, y);
	if (tmp != 0)
		lstadd_back(&info->sprites, tmp);
	else
		print_error("ERROR\nsprite list memory\n", info);
	info->config.sprite_count++;
}

t_sprites	*order_find(t_sprites *sprites, int s_order)
{
	t_sprites	*tmp;
	int			i;

	i = 0;
	tmp = sprites;
	while (i < s_order)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}