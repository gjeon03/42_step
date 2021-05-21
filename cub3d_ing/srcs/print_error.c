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

int		print_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (-1);
}

int		cub_close(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}