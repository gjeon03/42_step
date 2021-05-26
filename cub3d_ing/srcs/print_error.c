/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 05:19:49 by gjeon             #+#    #+#             */
/*   Updated: 2021/05/07 00:43:42 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		print_error(char *str, t_info *info)
{
	ft_putstr_fd(str, 1);
	cub_close(info);
	return (-1);
}

int		cub_close(t_info *info)
{
	malloc_clear(info);
	exit(0);
}