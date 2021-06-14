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

typedef struct			s_stack_ls
{
	int					index;
	int					data;
	struct s_stack_ls	*next;
}						t_stack_ls;

typedef struct			s_stack
{
	t_stack_ls			*a;
	t_stack_ls			*b;
}						t_stack;

typedef struct			s_info
{
	t_stack				stack;
}						t_info;

t_stack_ls				*stack_lsnew(int index, int data);
void					stack_lsadd_back(t_stack_ls **lst, t_stack_ls *new);
void					stack_lsadd_front(t_stack_ls **lst, t_stack_ls *new);
void					set_stack(t_stack_ls **stack, int index, int data);
void					stack_lsclear(t_stack_ls **stack);
t_stack_ls  			*stack_lslast(t_stack_ls *lst);

void					set_sa_sb(t_stack_ls **stack);
void					set_pa_pb(t_stack_ls **a, t_stack_ls **b);
void					set_ra_rb(t_stack_ls **a);
void					set_rra_rrb(t_stack_ls **a);

#endif
