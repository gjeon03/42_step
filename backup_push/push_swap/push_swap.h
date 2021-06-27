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
	int					data;
	struct s_stack_ls	*next;
}						t_stack_ls;

typedef struct			s_stack
{
	t_stack_ls			*a;
	t_stack_ls			*b;
}						t_stack;

typedef struct			s_sort_info
{
	int					ra_count;
	int					rb_count;
	int					pa_count;
	int					pb_count;
	int					rr_count;
	int					pivot1;
	int					pivot2;
}						t_sort_info;

typedef struct			s_info
{
	t_stack				stack;
	int					pivot;
	int					count;
	t_sort_info			sort;
	int					ra_count;
	int					rb_count;
	int					pa_count;
	int					pb_count;
	int					pivot1;
	int					pivot2;
}						t_info;

t_stack_ls				*stack_lsnew(int data);
void					stack_lsadd_back(t_stack_ls **lst, t_stack_ls *new);
void					stack_lsadd_front(t_stack_ls **lst, t_stack_ls *new);
void					set_stack(t_stack_ls **stack, int data);
void					stack_lsclear(t_stack_ls **stack);
t_stack_ls				*stack_lslast(t_stack_ls *lst);
int						stack_lssize(t_stack_ls *lst);

void					set_sa_sb(t_stack_ls **stack, int flag);
void					set_pa_pb(t_stack_ls **a, t_stack_ls **b, int flag, t_sort_info *info);
void					set_ra_rb(t_stack_ls **a, int flag, t_sort_info *info);
void					set_rra_rrb(t_stack_ls **a, int flag);

void					set_ss(t_stack_ls **a, t_stack_ls **b);
void					set_rr(t_stack_ls **a, t_stack_ls **b, t_sort_info *info);
void					set_rrr(t_stack_ls **a, t_stack_ls **b);

int						set_first_pivot(t_stack_ls *stack, t_info *info, int p_count);
int						set_second_pivot(t_stack_ls *stack, t_info *info, int p_count);
int						set_pivot(t_stack_ls *stack, t_info *info, int p_count);

void					a_to_b(t_info *info, int count);
void					b_to_a(t_info *info, int count);

#endif
