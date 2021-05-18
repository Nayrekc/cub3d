/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:15:58 by ketaouki          #+#    #+#             */
/*   Updated: 2021/03/23 08:41:50 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newelem;

	if (!lst || !f)
		return (0);
	new = NULL;
	while (lst)
	{
		newelem = ft_lstnew((*f)(lst->content));
		if (!(newelem))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, newelem);
		lst = lst->next;
	}
	return (new);
}
