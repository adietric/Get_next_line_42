/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:06:52 by adietric          #+#    #+#             */
/*   Updated: 2018/11/18 15:08:12 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		j;

	i = 0;
	if (find[i] == '\0')
		return ((char*)&str[i]);
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == find[j] && find[j] != '\0' && str[i] != '\0')
		{
			if (find[j + 1] == '\0')
				return ((char*)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
