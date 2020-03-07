/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:45:57 by adietric          #+#    #+#             */
/*   Updated: 2018/11/16 11:24:14 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stri, const char *find, size_t len)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)stri;
	i = 0;
	if (find[i] == '\0')
		return (&str[i]);
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (str[i + j] == find[j] && find[j] != '\0'
		&& str[i] != '\0' && i + j < (int)len)
		{
			if (find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
