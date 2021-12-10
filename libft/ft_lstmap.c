/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sublee <sublee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:30:08 by sublee            #+#    #+#             */
/*   Updated: 2021/02/17 16:34:26 by sublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*make_list;

	make_list = NULL;
	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(make_list = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, make_list);
		make_list = make_list->next;
		lst = lst->next;
	}
	return (new_list);
}
