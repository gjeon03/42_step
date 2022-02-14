/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:30:41 by gjeon             #+#    #+#             */
/*   Updated: 2021/07/11 01:25:51 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*piece;
	t_list	*temp;

	if (lst == 0 || f == 0)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == 0)
		return (0);
	lst = lst->next;
	temp = new_lst;
	while (lst)
	{
		piece = ft_lstnew(f(lst->content));
		if (piece == 0)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		temp->next = piece;
		temp = piece;
		lst = lst->next;
	}
	return (new_lst);
}
