/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:48:43 by adietric          #+#    #+#             */
/*   Updated: 2018/11/17 16:55:36 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*lst2;
	t_list		*tmp;
	t_list		*tmp2;

	lst2 = NULL;
	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(lst2 = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	tmp2 = lst2;
	while (lst)
	{
		if (lst->next == NULL)
			return (tmp2);
		lst = lst->next;
		tmp = f(lst);
		if (!(lst2->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst2 = lst2->next;
	}
	return (tmp2);
}
