/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:27:33 by gjeon             #+#    #+#             */
/*   Updated: 2021/06/10 17:27:34 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_stack_ls
{
	int			index;
	int			data;
	t_stack_ls	*next;
}				t_stack_ls;

typedef struct	s_stack
{
	t_stack_ls	*a;
	t_stack_ls	*b;
}				t_stack;

#endif
