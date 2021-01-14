/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:30:41 by gjeon             #+#    #+#             */
/*   Updated: 2021/01/14 21:43:06 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	if (lst == 0 || f == 0)
		return (0);
	if (!(new_lst = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	temp = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = temp;
		new_lst = temp;
		lst = lst->next;
	}
	return (new_lst);
}
