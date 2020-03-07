/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:57:35 by adietric          #+#    #+#             */
/*   Updated: 2018/11/16 11:19:06 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (0);
}
