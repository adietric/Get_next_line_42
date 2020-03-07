/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:06:47 by adietric          #+#    #+#             */
/*   Updated: 2018/11/17 14:31:33 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	else
	{
		tmp->content = ft_memalloc(content_size);
		tmp->content_size = content_size;
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		tmp->next = NULL;
	}
	return (tmp);
}
