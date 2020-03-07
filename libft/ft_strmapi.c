/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:15:18 by adietric          #+#    #+#             */
/*   Updated: 2018/11/16 11:20:01 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s1;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
			i++;
		if (!(s1 = (char*)malloc(sizeof(char) * i + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			s1[i] = f(i, s[i]);
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (0);
}
