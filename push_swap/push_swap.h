/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:27:33 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 03:29:27 by gjeon            ###   ########.fr       */
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

typedef struct s_array_stack
{
	int			*arr;
	int			top;
}				t_array_stack;

typedef struct s_stack
{
	t_array_stack	a;
	t_array_stack	b;
}					t_stack;

typedef struct s_sort_info
{
	int			ra_count;
	int			rb_count;
	int			pa_count;
	int			pb_count;
	int			rr_count;
	int			rrr_count;
	int			pivot1;
	int			pivot2;
	int			pivot;
}				t_sort_info;

typedef struct s_info
{
	t_stack		stack;
	t_sort_info	sort;
	int			count;
	int			check;
}				t_info;

int						sort_check(t_info *info);
void					info_init(t_info *info);

int						error_msg(char *str, t_info *info);
int						stack_free(t_info *info);

void					set_ss(t_array_stack *a, t_array_stack *b);
void					set_rr(t_array_stack *a, t_array_stack *b, \
		t_sort_info *sort);
void					set_rrr(t_array_stack *a, t_array_stack *b);
void					set_sa_sb(t_array_stack *stack, int flag);
void					set_pa_pb(t_array_stack *a, t_array_stack *b, \
		int flag, t_sort_info *sort);
void					set_ra_rb(t_array_stack *stack, int flag, \
		t_sort_info *sort);
void					set_rra_rrb(t_array_stack *stack, int flag);

int						malloc_stack(t_info *info, int total);
void					set_stack(t_info *info, char **str, int total);
void					stack_pop_first(t_array_stack *pstack);
void					stack_pop_end(t_array_stack *pstack);
void					stack_push_first(t_array_stack *pstack, int data);
void					stack_push_end(t_array_stack *pstack, int data);
void					stack_init(t_array_stack *pstack);
int						is_empty(t_array_stack *pstack);

int						set_pivot(t_array_stack *stack, int range);

void					a_to_b(t_info *info, int count);
void					b_to_a(t_info *info, int count);
void					sort_info_init(t_sort_info *sort, \
		t_array_stack *stack, int range);
void					rrr_count_init(t_sort_info *sort);
void					sort_three(t_info *info, t_array_stack *stack, \
		int flag);
void					sort_two(t_info *info, int count);

void					arr3_sort(t_info *info);

void					blank_handling(t_info *info, char *str, int count);
int						ft_strchar_count(char *str);
char					*ft_strndup(char *str, int n);
void					tmp_free(char **tmp, int count);
#endif
