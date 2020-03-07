/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:39:36 by adietric          #+#    #+#             */
/*   Updated: 2018/11/17 15:01:44 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	while ((*alst)->next != NULL)
	{
		del((*alst)->next->content, (*alst)->next->content_size);
		free((*alst)->next);
		(*alst)->next = (*alst)->next->next;
	}
	ft_memdel((void**)alst);
}
