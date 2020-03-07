/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:37:40 by adietric          #+#    #+#             */
/*   Updated: 2018/11/17 13:27:09 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*src1;
	char	*dest1;
	size_t	i;

	i = 0;
	src1 = (char *)src;
	dest1 = (char *)dest;
	while (src1[i] != '\0' && i < n)
	{
		dest1[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest1[i] = '\0';
		i++;
	}
	return (dest1);
}
