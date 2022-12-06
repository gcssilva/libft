/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:27:39 by gsilva            #+#    #+#             */
/*   Updated: 2022/12/06 13:17:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	newlist = NULL;
	while (lst)
	{
		temp = ft_lstnew((f)(lst->content));
		if (!temp)
			ft_lstclear(&temp, del);
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
