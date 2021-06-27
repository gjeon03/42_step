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

# define TRUE 1
# define FALSE 0

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_array_stack {
	int					*arr;
	int					top;
}						t_array_stack;

typedef struct			s_stack
{
	t_array_stack		a;
	t_array_stack		b;
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
	int					count;
}						t_info;

int						error_msg(char *str);

void					set_ss(int *a, int *b);
void					set_rr(int *a, int *b, t_sort_info *sort);
void					set_rrr(int *a, int *b);
void					set_sa_sb(int *stack, int flag);
void					set_pa_pb(int *a, int *b, int flag, t_sort_info *info);
void					set_ra_rb(int *stack, int flag, t_sort_info *info);
void					set_rra_rrb(int *stack, int flag);

int						intlen(int *arr);
int						malloc_stack(t_info *info, int total);
void					set_stack(t_info *info, char **str, int total);

#endif
