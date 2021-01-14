/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:16:17 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/14 21:21:39 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (lst == 0 || del == 0)
		return ;
	while (*lst)
	{
		head = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = head;
	}
	*lst = 0;
}
