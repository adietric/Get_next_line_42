/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adietric <adietric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:40:04 by adietric          #+#    #+#             */
/*   Updated: 2018/11/16 11:25:15 by adietric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char *s1, int i, char c)
{
	while (s1[i])
	{
		i++;
		if (s1[i] == c)
			return (1);
	}
	return (0);
}

char			*ft_strrchr(const char *s, int c)
{
	char		*s1;
	int			i;

	s1 = (char*)s;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
		{
			if (check(s1, i, c) == 0)
				return (&s1[i]);
		}
		i++;
	}
	if (s1[i] == (char)c)
		return (&s1[i]);
	return (0);
}
