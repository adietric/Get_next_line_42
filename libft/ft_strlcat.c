/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:12:55 by adietric          #+#    #+#             */
/*   Updated: 2018/11/16 11:17:43 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	char		*sourc;

	sourc = (char*)src;
	i = 0;
	j = 0;
	if (size == 0)
		return (ft_len(sourc));
	while (dst[i] != '\0' && i < size)
		i++;
	while (sourc[j] != '\0' && (i + j) < size - 1)
	{
		dst[i + j] = sourc[j];
		j++;
	}
	if ((i + j) < size)
		dst[i + j] = '\0';
	return (ft_len(sourc) + i);
}
