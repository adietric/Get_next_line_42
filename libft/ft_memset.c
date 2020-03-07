/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:48:46 by adietric          #+#    #+#             */
/*   Updated: 2018/11/17 14:15:08 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < (int)n)
	{
		s2[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
