/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:30:41 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/16 23:06:39 by gjeon            ###   ########.fr       */
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
	if (!(new_lst = ft_lstnew(f(lst->content))))
		return (0);
	lst = lst->next;
	temp = new_lst;
	while (lst)
	{
		if (!(piece = ft_lstnew(f(lst->content))))
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
