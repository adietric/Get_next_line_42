/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:18:10 by adietric          #+#    #+#             */
/*   Updated: 2018/11/15 18:38:00 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	const char		*src1;
	unsigned char	*dest1;

	dest1 = (unsigned char *)dest;
	src1 = (const char *)src;
	i = 0;
	if (dest > src && n != 0)
	{
		n--;
		while (n != 0)
		{
			dest1[n] = src1[n];
			n--;
		}
		dest1[n] = src1[n];
		return (dest);
	}
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
